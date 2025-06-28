analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:18:22: warning: ‘*alloc_k’ is used uninitialized [-Wuninitialized]
   18 |   alloc_z[0] = RevInc(*alloc_a,*alloc_k);
      |                ~~~~~~^~~~~~~~~~~~~~~~~~~
analysis-valgrind.cpp:18:22: warning: ‘*alloc_a’ is used uninitialized [-Wuninitialized]
