analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:18:26: warning: ‘*alloc_b’ is used uninitialized [-Wuninitialized]
   18 |   alloc_x[0] = ModInverse(*alloc_a,*alloc_b);
      |                ~~~~~~~~~~^~~~~~~~~~~~~~~~~~~
analysis-valgrind.cpp:18:26: warning: ‘*alloc_a’ is used uninitialized [-Wuninitialized]
