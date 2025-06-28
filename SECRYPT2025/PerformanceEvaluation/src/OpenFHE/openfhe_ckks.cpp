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
  Simple examples for CKKS
 */

#define PROFILE

#include <iostream>
#include <string>
#include "openfhe.h"

using namespace lbcrypto;
using namespace std;

int  main(int argc, char* argv[]) {
    // Step 1: Setup CryptoContext
    double num1 = stof(argv[1]);
    double num2 = stof(argv[2]);
    double num3 = stof(argv[3]);

    std::vector<double> x1 = {num1};
    std::vector<double> x2 = {num2};
    std::vector<double> x3 = {num3};
    int64_t poly_coef = atoi(argv[4]);
    uint32_t multDepth = 1;
    TimeVar t;
    double processingTime(0.0);

    /* A2) Bit-length of scaling factor.
   * CKKS works for real numbers, but these numbers are encoded as integers.
   * For instance, real number m=0.01 is encoded as m'=round(m*D), where D is
   * a scheme parameter called scaling factor. Suppose D=1000, then m' is 10 (an
   * integer). Say the result of a computation based on m' is 130, then at
   * decryption, the scaling factor is removed so the user is presented with
   * the real number result of 0.13.
   *
   * Parameter 'scaleModSize' determines the bit-length of the scaling
   * factor D, but not the scaling factor itself. The latter is implementation
   * specific, and it may also vary between ciphertexts in certain versions of
   * CKKS (e.g., in FLEXIBLEAUTO).
   *
   * Choosing 'scaleModSize' depends on the desired accuracy of the
   * computation, as well as the remaining parameters like multDepth or security
   * standard. This is because the remaining parameters determine how much noise
   * will be incurred during the computation (remember CKKS is an approximate
   * scheme that incurs small amounts of noise with every operation). The
   * scaling factor should be large enough to both accommodate this noise and
   * support results that match the desired accuracy.
   */
    uint32_t scaleModSize = 50;

    /* A3) Number of plaintext slots used in the ciphertext.
   * CKKS packs multiple plaintext values in each ciphertext.
   * The maximum number of slots depends on a security parameter called ring
   * dimension. In this instance, we don't specify the ring dimension directly,
   * but let the library choose it for us, based on the security level we
   * choose, the multiplicative depth we want to support, and the scaling factor
   * size.
   *
   * Please use method GetRingDimension() to find out the exact ring dimension
   * being used for these parameters. Give ring dimension N, the maximum batch
   * size is N/2, because of the way CKKS works.
   */
    uint32_t batchSize = 1;
    // Step 5: Decryption and output
    Plaintext result;
    // We set the cout precision to 8 decimal digits for a nicer output.
    // If you want to see the error/noise introduced by CKKS, bump it up
    // to 15 and it should become visible.
    std::cout.precision(8);

    /* A4) Desired security level based on FHE standards.
   * This parameter can take four values. Three of the possible values
   * correspond to 128-bit, 192-bit, and 256-bit security, and the fourth value
   * corresponds to "NotSet", which means that the user is responsible for
   * choosing security parameters. Naturally, "NotSet" should be used only in
   * non-production environments, or by experts who understand the security
   * implications of their choices.
   *
   * If a given security level is selected, the library will consult the current
   * security parameter tables defined by the FHE standards consortium
   * (https://homomorphicencryption.org/introduction/) to automatically
   * select the security parameters. Please see "TABLES of RECOMMENDED
   * PARAMETERS" in  the following reference for more details:
   * http://homomorphicencryption.org/wp-content/uploads/2018/11/HomomorphicEncryptionStandardv1.1.pdf
   */
    CCParams<CryptoContextCKKSRNS> parameters;
    parameters.SetMultiplicativeDepth(multDepth);
    parameters.SetScalingModSize(scaleModSize);
    parameters.SetRingDim(poly_coef);
    parameters.SetBatchSize(batchSize);
    
    CryptoContext<DCRTPoly> cc = GenCryptoContext(parameters);
    // Enable the features that you wish to use
    cc->Enable(PKE);
    cc->Enable(KEYSWITCH);
    cc->Enable(LEVELEDSHE);
    
    TIC(t);
    auto keys = cc->KeyGen();
    cc->EvalMultKeyGen(keys.secretKey);
    processingTime = TOC(t);
    std::cout << "KeygenTime: " << processingTime << "ms" << std::endl;
    
    // std::cout << "CKKS scheme is using ring dimension " << cc->GetRingDimension() << std::endl << std::endl;

    // Encoding as plaintexts
    Plaintext ptxt1 = cc->MakeCKKSPackedPlaintext(x1);
    TIC(t);
    auto c1 = cc->Encrypt(keys.publicKey, ptxt1);
    processingTime = TOC(t);
    std::cout << "EncryptTime: " << processingTime << "ms" << std::endl;
    
    Plaintext ptxt2 = cc->MakeCKKSPackedPlaintext(x2);
    Plaintext ptxt3 = cc->MakeCKKSPackedPlaintext(x3);

    // Encrypt the encoded vectors
    auto c2 = cc->Encrypt(keys.publicKey, ptxt2);
    auto c3 = cc->Encrypt(keys.publicKey, ptxt3);
    

    // Homomorphic multiplication
    TIC(t);
    auto cMul123 = cc->EvalMult(c1, c2);
    //auto cMul123 = cc->EvalMult(cMul12, c3);
	processingTime = TOC(t);
    std::cout << "MultTime: " << processingTime << "ms" << std::endl;
    
    // Homomorphic addition
    TIC(t);
    auto cAdd12 = cc->EvalAdd(c1, c2);
    auto cAdd123 = cc->EvalAdd(cAdd12, c3);
    processingTime = TOC(t);
    std::cout << "AddTime: " << processingTime << "ms" << std::endl;
    
    // Decrypt the result of addition
    cc->Decrypt(keys.secretKey, cAdd123, &result);
    result->SetLength(batchSize);
    // std::cout << "x1 + x2 = " << result;
    // std::cout << std::endl;

    // Decrypt the result of multiplication
    TIC(t);
    cc->Decrypt(keys.secretKey, cMul123, &result);
    result->SetLength(batchSize);
     processingTime = TOC(t);
    std::cout << "DecryptTime: " << processingTime << "ms" << std::endl;
    
    // std::cout << "x1 * x2 = " << result << std::endl;
    // std::cout << std::endl;

    return 0;
}
