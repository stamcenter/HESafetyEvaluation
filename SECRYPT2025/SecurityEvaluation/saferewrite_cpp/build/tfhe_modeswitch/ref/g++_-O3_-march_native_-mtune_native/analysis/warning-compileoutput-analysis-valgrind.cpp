analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:16:21: warning: ‘*alloc_msize’ is used uninitialized [-Wuninitialized]
   16 |   modSwitchToTorus32(*alloc_mu,*alloc_msize);
      |   ~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~
analysis-valgrind.cpp:16:21: warning: ‘*alloc_mu’ is used uninitialized [-Wuninitialized]
