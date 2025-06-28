analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:18:22: warning: ‘*alloc_bitsize’ is used uninitialized [-Wuninitialized]
   18 |   alloc_z[0] = verify(*alloc_factor,*alloc_bitsize);
      |                ~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
analysis-valgrind.cpp:18:22: warning: ‘*alloc_factor’ is used uninitialized [-Wuninitialized]
