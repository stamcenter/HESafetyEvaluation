# saferewrite_for_test
 inspired by a talk by Dr Daniel Bernstein, I am exploring Saferewrite to detect memory leaks and vulnerabilities  in open-source homomorphic encryption libraries such as SEAL and OpenFHE
 
  
EXPERIMENT 

change the analyze file from canalyze to analayze then run the following commands:

    chmod +t src/*
  	chmod -t src/seal_load64
  	chmod -t src/seal_sha3_512
  	chmod -t src/seal_Store64
  	chmod -t src/seal_blake2b
  	chmod -t src/seal_keccak
  	chmod -t src/seal_keccakf1600
  	chmod -t src/seal_sha3_256
  	chmod -t src/seal_shake256
  	chmod -t src/openFHE_store48
  	chmod -t src/openFHE_store32
  	chmod -t src/openFHE_blake2b_state
  	
  	chmod -t src/tfhe_accurate_sine
  	chmod -t src/tfhe_fft
  	chmod -t src/tfhe_floor
  	chmod -t src/tfhe_reals
  	chmod -t src/tfhe_reversebits
  	
	./analyze


To work with C++ functions, rename the c++ppanalyze to analyze then run the following commands to set the c++ functions to run

	chmod +t src/*
  	chmod -t src/seal_u_exponentiate_uint
  	chmod -t src/seal_u_exponentiate_uint_safe
  	chmod -t src/seal_p_get_coeff_power
	chmod -t src/seal_p_get_plus
    chmod -t src/seal_ntt

 	chmod -t src/openFHE_bgvrns_getCyclicOrder
  	chmod -t src/openFHE_bigintdyn_add_bitVal
  	chmod -t src/openFHE_ckksrns_ReduceRotation
	chmod -t src/openFHE_ckksrns_SelectLayers
    chmod -t src/openFHE_discretegaussiangeneratorgeneric_SampleC
	chmod -t src/openFHE_nbtheory2_ModInverse
    chmod -t src/openFHE_ubintdyn_nlz32
	chmod -t src/openFHE_ubintdyn_nlz64
	
	chmod -t src/helib_cipher
  	chmod -t src/helib_computeFudge
  	chmod -t src/helib_evalpoly
	chmod -t src/helib_getSBoxValue
    chmod -t src/helib_longtobitvector
	chmod -t src/helib_noisefresh
    chmod -t src/helib_powerdouble
	chmod -t src/helib_revinc
	chmod -t src/helib_rotations
	
	chmod -t src/tfhe_modeswitch
	chmod -t src/tfhe_modswitchfromtorus32
	
	./analyze
  
