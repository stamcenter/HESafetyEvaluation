analysis-valgrind.c: In function ‘main’:
analysis-valgrind.c:18:16: warning: ‘*alloc_n’ is used uninitialized [-Wuninitialized]
   18 |   alloc_z[0] = reverse_bits(*alloc_x,*alloc_n);
      |                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
analysis-valgrind.c:18:16: warning: ‘*alloc_x’ is used uninitialized [-Wuninitialized]
