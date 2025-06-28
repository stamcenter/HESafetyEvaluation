/* Copyright (C) 2020-2021 IBM Corp.
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

// In the CKKS encryption scheme, plaintexts are vectors of real or complex
// numbers.  The length, n, of these vectors is determined by the choice of
// parameters, as discussed below.  We often refer to the components of these
// vectors as "slots", which are indexed 0, ..., n-1.  We can add, subtract, or
// multiply two ciphertexts, and the corresponding operations are carried out
// slot by slot.  This is sometimes referred to as a "SIMD operation" (SIMD
// means Single Instruction Multiple Data), since we can effectively perform
// the same scalar operation in parallel on all n slots.

#include <helib/helib.h>

#include <chrono>
#include <cstddef>
#include <fstream>

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::milliseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

using namespace std;
using namespace helib;

int main(int argc, char* argv[])
{

	TimeVar t;
    int processingTime;
    int64_t a_data = atoi(argv[1]);
    int64_t b_data = atoi(argv[2]);
    int64_t c_data = atoi(argv[3]);
    int64_t poly_coef = atoi(argv[4]);

  	Context context =

      // initialize a Context object using the builder pattern
      ContextBuilder<CKKS>()

          .m(poly_coef)
          .bits(218)
          // bits specifies the number of bits in the "ciphertext modulus".  As
          // bits increases, you get less security, but you can perform deeper
          // homomorphic computations; in addition, the size of a ciphertext
          // increases.  See table below for more information. Also see
          // 02_depth.cpp for more information about how depth and bits are
          // related.

          .precision(20)
          // precision specifies the number of bits of precision when data is
          // encoded, encrypted, or decrypted.  More precisely, each of these
          // operations are designed to add an error term of at most
          // 2^{-precision} to each slot.  As precision increases, the allowed
          // depth of homomorphic computations decreases (but security and
          // performance are not affected).  It is not recommended to use
          // precision greater than about 40 or so.

          .c(2)
          // c specifies the number of columns in key-switching matrices.  Yes,
          // it sounds very technical, and it is.  However, all you have to know
          // about this parameter is that as c increases, you get a little more
          // security, but performance degrades and the memory requirement for
          // the public key increases. c must be at least 2 and it is not
          // recommended to set c higher than 8.  See table below for more
          // information.

          .build();
  // last step of the builder pattern

  // The following table lists settings of m, bits, and c that yield (at least)
  // 128-bit security.  It is highly recommended to only use settings from this
  // table.
  //
  //	m	bits	c
  //	16384	119	2
  //	32768	358	6
  //	32768	299	3
  //	32768	239	2
  //	65536	725	8
  //	65536	717	6
  //	65536	669	4
  //	65536	613	3
  //	65536	558	2
  //	131072	1445	8
  //	131072	1435	6
  //	131072	1387	5
  //	131072	1329	4
  //	131072	1255	3
  //	131072	1098	2
  //	262144	2940	8
  //	262144	2870	6
  //	262144	2763	5
  //	262144	2646	4
  //	262144	2511	3
  //	262144	2234	2

  // We can print out the estimated security level.
  // This estimate is based on the LWE security estimator.
  //   cout << "securityLevel=" << context.securityLevel() << "\n";

  //   context.printout();

  // Get the number of slots, n.  Note that for CKKS, we always have n=m/4.
  long n = context.getNSlots();

  // Construct a secret key. A secret key must be associated with a specific
  // Context, which is passed (by reference) to the constructor.  Programming
  // note: to avoid dangling pointers, the given Context object must not be
  // destroyed while any objects associated with it are still in use.
  t=timeNow();
  SecKey secretKey(context);

  // Constructing a secret key does not actually do very much.  To actually
  // build a full-fledged secret key, we have to invoke the GenSecKey method.
  secretKey.GenSecKey();

  // In HElib, the SecKey class is actually a subclass if the PubKey class.  So
  // one way to initialize a public key object is like this:
  const PubKey& publicKey = secretKey;
  processingTime =  duration(timeNow()-t);
  std::cout << "KeygeTime: " << processingTime << "ms" << std::endl;

  // TECHNICAL NOTE: Note the "&" in the declaration of publicKey. Since the
  // SecKey class is a subclass of PubKey, this particular PubKey object is
  // ultimately a SecKey object, and through the magic of C++ polymorphism,
  // encryptions done via publicKey will actually use the secret key, which has
  // certain advantages.  If one left out the "&", then encryptions done via
  // publicKey will NOT use the secret key.

  //===========================================================================

  // Next, we load the plaintext vector v0 into a special type of container,
  // called a PtxtArray.  Note that a PtxtArray is associated with a Context
  // object, which is passed (by reference) to the constructor.
  PtxtArray p0(context, a_data);
  PtxtArray plaintext_a(context, a_data);
  PtxtArray plaintext_b(context, b_data);
  PtxtArray plaintext_c(context, c_data);
  PtxtArray plaintext_d(context, a_data);

  Ctxt cipher_a(publicKey);
  Ctxt cipher_b(publicKey);
  Ctxt cipher_c(publicKey);
  Ctxt cipher_d(publicKey);
  Ctxt cipher_result(publicKey);

  // Finally, we can encrypt p0 and store it in c0:
  	t=timeNow();
	plaintext_a.encrypt(cipher_a);
	processingTime =  duration(timeNow()-t);
    std::cout << "EncryptTime: " << processingTime << "ms" << std::endl;
	plaintext_b.encrypt(cipher_b);
    plaintext_c.encrypt(cipher_c);
    plaintext_d.encrypt(cipher_d);

	t=timeNow();
	cipher_a *= cipher_b;
	cipher_c *= cipher_a;
	processingTime =  duration(timeNow()-t);
    std::cout << "MultTime: " << processingTime << "ms" << std::endl;
    
	PtxtArray decryptora(context);
	decryptora.decrypt(cipher_a, secretKey);
	// cout << "Result: " << decryptora << endl;
	
	t=timeNow();
	cipher_d +=cipher_b;
	cipher_d +=cipher_c;
	processingTime =  duration(timeNow()-t);
    std::cout << "AddTime " << processingTime << "ms" << std::endl;
	
	t=timeNow();
	PtxtArray decryptorsum(context);
	decryptorsum.decrypt(cipher_d, secretKey);
	processingTime =  duration(timeNow()-t);
    std::cout << "DecryptTime: " << processingTime << "ms" << std::endl;
	// cout << "Result: " << cipher_d << endl;

  return 0;
}
