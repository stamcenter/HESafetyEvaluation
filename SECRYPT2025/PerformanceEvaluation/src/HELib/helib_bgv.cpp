/* Copyright (C) 2019 IBM Corp.
* This program is Licensed under the Apache License, Version 2.0
* (the "License"); you may not use this file except in compliance
* with the License. You may obtain a copy of the License at
*   http://www.apache.org/licenses/LICENSE-2.0
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License. See accompanying LICENSE file.
*/

// This is a sample program for education purposes only.
// It attempts to demonstrate the use of the API for the
// binary arithmetic operations that can be performed.

#include <iostream>
#include <chrono>
#include <cstddef>
#include <fstream>

#include <helib/helib.h>
#include <helib/binaryArith.h>
#include <helib/intraSlot.h>

#include <chrono>
#include <cstddef>
#include <fstream>

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::milliseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

using namespace std;
using namespace helib;

int main(int argc, char* argv[]){

	int64_t a_data = atoi(argv[1]);
    int64_t b_data = atoi(argv[2]);
    int64_t c_data = atoi(argv[3]);
    int64_t poly_coef = atoi(argv[4]);

	// // Plaintext prime modulus.
	long p = poly_coef;
	// Cyclotomic polynomial - defines phi(m).
	long m = poly_coef;
	if(poly_coef == 8192)
      p = 1032193;
    else if(poly_coef == 16384)
      p = 786433;
    else
      p = 786433;
	// Hensel lifting (default = 1).
	long r = 1;
	// Number of bits of the modulus chain.
	long bits = 500;
	// Number of columns of Key-Switching matrix (typically 2 or 3).
	long c = 2;
	// Factorisation of m required for bootstrapping.
	std::vector<long> mvec = {7, 5, 9, 13};
	// Generating set of Zm* group.
	std::vector<long> gens = {2341, 3277, 911};
	// Orders of the previous generators.
	std::vector<long> ords = {6, 4, 6};

	TimeVar t;
    int processingTime;
	
	
	// This object will hold information about the algebra created from the
	// previously set parameters.
	helib::Context context = helib::ContextBuilder<helib::BGV>()
								.m(m)
                               	.p(p)
                               	.r(r)
                               	.bits(bits)
                               	.c(c)
								.mvec(mvec)
							//    .bootstrappable(true)
                               .build();

	// Print the context.
	// context.printout();
	// std::cout << std::endl;
	// std::cout << "Security: " << context.securityLevel() << std::endl;

	// Create a secret key associated with the context.
	t=timeNow();
	helib::SecKey secret_key(context);
  // Generate the secret key
  	secret_key.GenSecKey();
	
	// Public key management.
	// Set the secret key (upcast: SecKey is a subclass of PubKey).
	const helib::PubKey& public_key = secret_key;
	processingTime =  duration(timeNow()-t);
    std::cout << "KeygenTime: " << processingTime << "ms" << std::endl;

	// // Build the unpack slot encoding.
	// std::vector<helib::zzX> unpackSlotEncoding;
	// buildUnpackSlotEncoding(unpackSlotEncoding, ea);

	// // Get the number of slot (phi(m)).
	// long nslots = ea.size();
	// std::cout << "Number of slots: " << nslots << std::endl;

	long bitSize = 8;
	int outSize;

	PtxtArray plaintext_a(context, a_data);
	PtxtArray plaintext_b(context, b_data);
	PtxtArray plaintext_c(context, c_data);
	PtxtArray plaintext_d(context, a_data);

	Ctxt cipher_a(public_key);
	Ctxt cipher_b(public_key);
	Ctxt cipher_c(public_key);
	Ctxt cipher_d(public_key);
	Ctxt cipher_result(public_key);

	// Finally, we can encrypt p0 and store it in c0:
  	t=timeNow();
	plaintext_a.encrypt(cipher_a);
	processingTime =  duration(timeNow()-t);
    std::cout << "EncryptTime: " << processingTime << "ms" << std::endl;
	plaintext_b.encrypt(cipher_b);
    plaintext_c.encrypt(cipher_c);
    plaintext_d.encrypt(cipher_d);

	t=timeNow();
	cipher_d +=cipher_b;
	cipher_d +=cipher_c;
	processingTime =  duration(timeNow()-t);
    std::cout << "AddTime " << processingTime << "ms" << std::endl;

	t=timeNow();
	cipher_a *= cipher_b;
	cipher_c *= cipher_a;
	processingTime =  duration(timeNow()-t);
    std::cout << "MultTime: " << processingTime << "ms" << std::endl;
	
	t=timeNow();
	PtxtArray decryptorsum(context);
	decryptorsum.decrypt(cipher_d, secret_key);
	processingTime =  duration(timeNow()-t);
    std::cout << "DecryptTime: " << processingTime << "ms" << std::endl;
	
	return 0;
	}
