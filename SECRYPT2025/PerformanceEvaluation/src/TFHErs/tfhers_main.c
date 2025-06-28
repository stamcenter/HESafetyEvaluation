#include <tfhe.h>

#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

long long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL); // Get current time
    long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000LL;
    return milliseconds;
}

int clock_diff(long long start, long long end){
  int time_diff = (end - start);
  return time_diff;
}

int main(int argc, char* argv[]) {

	int64_t a_data = atoi(argv[1]);
  	int64_t b_data = atoi(argv[2]);
  	int64_t c_data = atoi(argv[3]);
    int ok = 0;
    // Prepare the config builder for the high level API and choose which types to enable
    ConfigBuilder *builder;
    Config *config;
    time_t start,end;
  	double dif;
    long long  starttime;
    long long  endtime;
    int  timediff;

    // Put the builder in a default state without any types enabled
    config_builder_all_disabled(&builder);
    config_builder_enable_default_integers_small(&builder);
    config_builder_build(builder, &config);

    ClientKey *client_key = NULL;
    ServerKey *server_key = NULL;
    starttime = current_timestamp();
    // Generate the keys using the config
    generate_keys(config, &client_key, &server_key);
    set_server_key(server_key);

    endtime = current_timestamp();
    timediff = clock_diff(starttime, endtime);
    printf ("KeygenTime: %dms\n", timediff );

    FheUint64 *lhs = NULL;
    FheUint64 *rhs = NULL;
    FheUint64 *mhs = NULL;
    FheUint64 *result = NULL;
    FheUint64 *add_result = NULL;
    FheUint64 *mult_one_result = NULL;
    FheUint64 *mult_result = NULL;
	
	starttime = current_timestamp();
    ok = fhe_uint64_try_encrypt_with_client_key_u64(a_data, client_key, &lhs);
    endtime = current_timestamp();
    timediff = clock_diff(starttime, endtime);
    printf ("EncryptTime: %dms\n", timediff);
    assert(ok == 0);

    ok = fhe_uint64_try_encrypt_with_client_key_u64(b_data, client_key, &rhs);
    assert(ok == 0);

	ok = fhe_uint64_try_encrypt_with_client_key_u64(c_data, client_key, &mhs);
    assert(ok == 0);

  	// Compute the Multiplication
	starttime = current_timestamp();
    ok = fhe_uint64_mul(lhs, rhs,  &mult_one_result);
    ok = fhe_uint64_mul(mult_one_result, mhs,  &mult_result);
    endtime = current_timestamp();
    timediff = clock_diff(starttime, endtime);
    printf ("MultTime: %dms\n", timediff );
    
    // Compute the Addition
    starttime = current_timestamp();
    ok = fhe_uint64_add(lhs, rhs,  &result);
    ok = fhe_uint64_add(result, mhs,  &add_result);
    endtime = current_timestamp();
    timediff = clock_diff(starttime, endtime);
  	printf ("AddTime: %dms\n", timediff);
    assert(ok == 0);
    
    uint64_t clear_result;
    ok = fhe_uint64_decrypt(add_result, client_key, &clear_result);
    assert(ok == 0);
    
    // printf("The Sum:  %ld\n",clear_result);
	
    uint64_t clear_mult_result;
    // Decrypt
    starttime = current_timestamp();
    ok = fhe_uint64_decrypt(mult_one_result, client_key, &clear_mult_result);
    endtime = current_timestamp();
    timediff = clock_diff(starttime, endtime);
  	printf ("DecryptTime: %dms\n", timediff);
    // printf("The Multiplication result %ld\n", clear_mult_result);
    
    assert(ok == 0);
    
    fhe_uint64_destroy(lhs);
    fhe_uint64_destroy(rhs);
    fhe_uint64_destroy(mhs);
    fhe_uint64_destroy(result);

    // Destroy the keys
    client_key_destroy(client_key);
    server_key_destroy(server_key);
    
    return EXIT_SUCCESS;
}


