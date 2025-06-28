analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:18:24: warning: ‘*alloc_m’ is used uninitialized [-Wuninitialized]
   18 |   alloc_z[0] = evalpoly(*alloc_i,*alloc_m);
      |                ~~~~~~~~^~~~~~~~~~~~~~~~~~~
analysis-valgrind.cpp:18:24: warning: ‘*alloc_i’ is used uninitialized [-Wuninitialized]
