analysis-execute.cpp: In function ‘int main(int, char**)’:
analysis-execute.cpp:27:22: warning: ‘*alloc_a’ may be used uninitialized [-Wmaybe-uninitialized]
   27 |   alloc_z[0] = RevInc(*alloc_a,*alloc_k);
      |                ~~~~~~^~~~~~~~~~~~~~~~~~~
