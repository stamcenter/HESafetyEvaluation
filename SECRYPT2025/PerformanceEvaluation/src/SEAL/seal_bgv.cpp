// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license.

#define PROFILE

#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <time.h>
#include <sstream>
#include <thread>
#include <vector>

#include "examples.h"

using namespace std;
using namespace seal;


void added_bgv(uint64_t num1, uint64_t num2, uint64_t num3, int poly_coeff)
{
	
    TimeVar t=timeNow();
    int processingTime;

    EncryptionParameters parms(scheme_type::bgv);
    size_t poly_modulus_degree = poly_coeff;

    parms.set_poly_modulus_degree(poly_modulus_degree);
    parms.set_poly_modulus_degree(poly_modulus_degree);
    parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
    parms.set_plain_modulus(PlainModulus::Batching(poly_modulus_degree, 20));
    // if (poly_modulus_degree < 8192)
    // {
    //     parms.set_plain_modulus(12289);
    // }

    SEALContext context(parms);
    /*
    Print the parameters that we have chosen.
    */
    print_parameters(context);
	t=timeNow();
    KeyGenerator keygen(context);
    SecretKey secret_key = keygen.secret_key();
    PublicKey public_key;
    keygen.create_public_key(public_key);
    RelinKeys relin_keys;
    keygen.create_relin_keys(relin_keys);
    processingTime =  duration(timeNow()-t);
    std::cout << "KeygeTime: " << processingTime << "ms" << std::endl;

    Encryptor encryptor(context, public_key);
    Evaluator evaluator(context);
    Decryptor decryptor(context, secret_key);
    
    Plaintext plaintext2(num2);
    Plaintext plaintext3(num3);

    Plaintext decrypted_result;
    Ciphertext ciphertext1;
    Ciphertext ciphertext2;
    Ciphertext ciphertext3;
    Ciphertext ciphertext12;
    Ciphertext ciphertext123;
    Ciphertext add_result12;
    Ciphertext add_result123;

    Plaintext plaintext1(num1);
    t = timeNow();
    encryptor.encrypt(plaintext1, ciphertext1);
    processingTime = duration(timeNow()-t);
    cout << "EncryptTime: " << processingTime  << "ms" << endl;

    cout << endl << endl; 
    cout << "    + Noise budget: " << decryptor.invariant_noise_budget(ciphertext1) << " bits" << endl;
    cout << endl;
    
    encryptor.encrypt(plaintext2, ciphertext2);
    encryptor.encrypt(plaintext3, ciphertext3);

    t = timeNow();
    evaluator.multiply(ciphertext1, ciphertext2, ciphertext12);
    evaluator.relinearize_inplace(ciphertext12, relin_keys);
    evaluator.multiply(ciphertext12, ciphertext3, ciphertext123);
    evaluator.relinearize_inplace(ciphertext123, relin_keys);
    evaluator.mod_switch_to_next_inplace(ciphertext123);
    processingTime = duration(timeNow()-t);
    cout << "MultTime: " << processingTime  << "ms" << endl;
    decryptor.decrypt(ciphertext123, decrypted_result);
    // cout << "Results #1 * #2 * #3: " << decrypted_result.to_string()  << endl;

    t = timeNow();
    evaluator.add(ciphertext1, ciphertext2, add_result12);
    evaluator.add(add_result12, ciphertext3, add_result123);
    processingTime = duration(timeNow()-t);
    cout << "AddTime: " << processingTime  << "ms" << endl;
     
    t = timeNow();
    decryptor.decrypt(add_result123, decrypted_result);
    processingTime = duration(timeNow()-t);
    cout << "DecryptTime: " << processingTime  << "ms" << endl;

    // cout << "    + Noise budget in fresh encryption: " << decryptor.invariant_noise_budget(add_result123) << " bits"
    //      << endl;
    // cout << endl;
    // cout << "Sum #1 + #2 + #3: " << decrypted_result.to_string() << endl;
}
