analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:20:30: warning: ‘*alloc_c’ is used uninitialized [-Wuninitialized]
   20 |   alloc_d[0] = getCyclicOrder(*alloc_a,*alloc_b,*alloc_c);
      |                ~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~
analysis-valgrind.cpp:20:30: warning: ‘*alloc_b’ is used uninitialized [-Wuninitialized]
analysis-valgrind.cpp:20:30: warning: ‘*alloc_a’ is used uninitialized [-Wuninitialized]
