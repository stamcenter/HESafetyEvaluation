analysis-valgrind.c: In function ‘main’:
analysis-valgrind.c:20:32: warning: ‘*alloc_key’ is used uninitialized [-Wuninitialized]
   20 |   alloc_z[0] = blake2(alloc_in,*alloc_key,alloc_out);
      |                                ^~~~~~~~~~
