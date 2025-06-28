//==================================================================================
// BSD 2-Clause License
//
// Copyright (c) 2014-2022, NJIT, Duality Technologies Inc. and other contributors
//
// All rights reserved.
//
// Author TPOC: contact@openfhe.org
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//==================================================================================

/*
  Simple example for BFVrns (integer arithmetic)
 */
#define PROFILE

#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iterator>

#include "openfhe.h"

using namespace lbcrypto;
using namespace std;

int main(int argc, char* argv[]) {
    TimeVar t;
    double processingTime(0.000);
    int64_t num1 = atoi(argv[1]);
    int64_t num2 = atoi(argv[2]);
    int64_t num3 = atoi(argv[3]);
    int64_t poly_coef = atoi(argv[4]);
    
    // cout << endl;
    // cout << "+----------------------------------------------------------------------+" << endl;
    // cout << "| OPENFHE: BFV Scheme: Multiplication and Addition of three inputs     |" << endl;
    // cout << "+----------------------------------------------------------------------|" << endl;
    // cout << "/" << endl;
	// Sample Program: Step 1: Set CryptoContext
    CCParams<CryptoContextBFVRNS> parameters;
    // long int pol = pow(2,0)+1;
    parameters.SetRingDim(poly_coef);
    if(poly_coef == 8192)
      parameters.SetPlaintextModulus(1032193);
    else if(poly_coef == 16384)
      parameters.SetPlaintextModulus(786433);
    else
      parameters.SetPlaintextModulus(786433);
    parameters.SetMultiplicativeDepth(3);
    parameters.SetMaxRelinSkDeg(3);
    
    
    
    CryptoContext<DCRTPoly> cryptoContext = GenCryptoContext(parameters);
    // Enable features that you wish to use
    cryptoContext->Enable(PKE);
    cryptoContext->Enable(LEVELEDSHE);
  
    KeyPair<DCRTPoly> keyPair;

    t=timeNow();
    // Generate a public/private key pair
    keyPair = cryptoContext->KeyGen();
    cryptoContext->EvalMultKeyGen(keyPair.secretKey);
    processingTime =  duration(timeNow()-t);
    std::cout << "KeygenTime: " << processingTime << "ms" << std::endl;

    // cout << endl;
    // cout << "Encryption Parameters: " << endl;
    // std::cout << "p = " << cryptoContext->GetCryptoParameters()->GetPlaintextModulus() << std::endl;
    // std::cout << "n = " << cryptoContext->GetCryptoParameters()->GetElementParams()->GetCyclotomicOrder() / 2
    //           << std::endl;
    // std::cout << "log2 q = "
    //           << log2(cryptoContext->GetCryptoParameters()->GetElementParams()->GetModulus().ConvertToDouble())
    //           << std::endl;

    // get the three inputs from terminal
   
    std::vector<int64_t> vectorOfInts1 = {num1};
    Plaintext plaintext1               = cryptoContext->MakePackedPlaintext(vectorOfInts1);
    std::vector<int64_t> vectorOfInts2 = {num2};
    Plaintext plaintext2               = cryptoContext->MakePackedPlaintext(vectorOfInts2);
    std::vector<int64_t> vectorOfInts3 = {num3};
    Plaintext plaintext3               = cryptoContext->MakePackedPlaintext(vectorOfInts3);

    t=timeNow();
    auto ciphertext1 = cryptoContext->Encrypt(keyPair.publicKey, plaintext1);
    processingTime =  duration(timeNow()-t);
    std::cout << "EncryptTime: " << processingTime << "ms" << std::endl;
    
    auto ciphertext2 = cryptoContext->Encrypt(keyPair.publicKey, plaintext2);
    auto ciphertext3 = cryptoContext->Encrypt(keyPair.publicKey, plaintext3);

    // Homomorphic multiplications
    auto ciphertextMul12      = cryptoContext->EvalMult(ciphertext1, ciphertext2);
    auto ciphertextMultResult = cryptoContext->EvalMult(ciphertextMul12, ciphertext3);
    processingTime = TOC(t);
    std::cout << "MultTime: " << processingTime << "ms" << std::endl;
    // Decrypt the result of multiplications
    Plaintext plaintextMultResult;
    cryptoContext->Decrypt(keyPair.secretKey, ciphertextMultResult, &plaintextMultResult);
    // std::cout << "Results #1 * #2 * #3: " << plaintextMultResult << std::endl;
    
    // Homomorphic additions
    TIC(t);
    auto ciphertextAdd12     = cryptoContext->EvalAdd(ciphertext1, ciphertext2);
    auto ciphertextAddResult = cryptoContext->EvalAdd(ciphertextAdd12, ciphertext3);
    processingTime = TOC(t);
    std::cout << "AddTime: " << processingTime << "ms" << std::endl;

  // Decrypt the result of additions
    Plaintext plaintextAddResult;
    TIC(t);
    cryptoContext->Decrypt(keyPair.secretKey, ciphertextAddResult, &plaintextAddResult);
    processingTime = TOC(t);
    std::cout << "DecryptTime: " << processingTime << "ms" << std::endl;
    // std::cout << "Sum #1 + #2 + #3: " << plaintextAddResult << std::endl;

    return 0;
}
