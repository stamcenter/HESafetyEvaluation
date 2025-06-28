#include "openfhe.h"
#include "binfhecontext.h"

using namespace lbcrypto;

void SwitchFHEWtoCKKS();

int main() {
    
    SwitchFHEWtoCKKS();
    return 0;
}

void SwitchFHEWtoCKKS() {
    // std::cout << "\n-----TFHE Evaluation-----\n";

    TimeVar t;
    double processingTime(0.000);

    // Step 2: Prepare the FHEW cryptocontext and keys for FHEW and scheme switching
    t=timeNow();
    auto ccLWE = BinFHEContext();
    ccLWE.BinFHEContext::GenerateBinFHEContext(STD128);

    // LWE private key
    LWEPrivateKey lwesk;
    lwesk = ccLWE.KeyGen();
    ccLWE.BTKeyGen(lwesk);
    processingTime =  duration(timeNow()-t);
    std::cout << "KeygenTime: " << processingTime << "ms" << std::endl;

    // std::cout << "FHEW scheme is using lattice parameter " << ccLWE.GetParams()->GetLWEParams()->Getn();
    // // std::cout << ", logQ " << logQ_ccLWE;
    // std::cout << ", and modulus q " << ccLWE.GetParams()->GetLWEParams()->Getq() << std::endl << std::endl;

    // Inputs
    bool a_data = 1;
    bool b_data = 0;
  
    // Encrypt 
    TIC(t);
    LWECiphertext ctxtsLWE1;
    ctxtsLWE1 = ccLWE.Encrypt(lwesk, a_data);
    processingTime =  duration(timeNow()-t);
    std::cout << "EncryptTime: " << processingTime << "ms" << std::endl;
    LWECiphertext ctxtsLWE2;
    ctxtsLWE2 = ccLWE.Encrypt(lwesk, b_data); 

    TIC(t);
    auto ctAND = ccLWE.EvalBinGate(AND, ctxtsLWE1, ctxtsLWE2);
    processingTime =  duration(timeNow()-t);
    std::cout << "ANDGate: " << processingTime << "ms" << std::endl;
    
    TIC(t);
    auto ctOR = ccLWE.EvalBinGate(OR, ctxtsLWE1, ctxtsLWE2);
    processingTime =  duration(timeNow()-t);
    std::cout << "ORGate: " << processingTime << "ms" << std::endl;

    TIC(t);
    auto ctXOR = ccLWE.EvalBinGate(XOR, ctxtsLWE1, ctxtsLWE2);
    processingTime =  duration(timeNow()-t);
    std::cout << "XORGate: " << processingTime << "ms" << std::endl;

    TIC(t);
    LWEPlaintext result;
    ccLWE.Decrypt(lwesk, ctAND, &result);
    processingTime = TOC(t);
    std::cout << "DecryptTime: " << processingTime << "ms" << std::endl;
    // std::cout << a_data <<  " AND " << b_data << ": " << result << std::endl;

    // ccLWE.Decrypt(lwesk, ctOR, &result);
    // std::cout << a_data <<  " OR " << b_data << ": " << result << std::endl;

    // ccLWE.Decrypt(lwesk, ctXOR, &result);
    // std::cout << a_data <<  " XOR " << b_data << ": " << result << std::endl;
}