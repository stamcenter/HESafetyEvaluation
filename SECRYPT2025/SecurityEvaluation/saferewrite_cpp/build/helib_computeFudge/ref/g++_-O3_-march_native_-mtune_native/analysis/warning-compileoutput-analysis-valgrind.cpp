analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:16:16: warning: ‘*alloc_pe’ is used uninitialized [-Wuninitialized]
   16 |   compute_fudge(*alloc_peprime,*alloc_pe);
      |   ~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~
analysis-valgrind.cpp:16:16: warning: ‘*alloc_peprime’ is used uninitialized [-Wuninitialized]
