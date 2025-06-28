analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:16:23: warning: ‘*alloc_msize’ is used uninitialized [-Wuninitialized]
   16 |   modSwitchFromTorus32(*alloc_phase,*alloc_msize);
      |   ~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~
analysis-valgrind.cpp:16:23: warning: ‘*alloc_phase’ is used uninitialized [-Wuninitialized]
