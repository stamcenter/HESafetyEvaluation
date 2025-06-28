analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:16:18: warning: ‘*alloc_bitsize’ is used uninitialized [-Wuninitialized]
   16 |   longtobitvector(*alloc_num,*alloc_bitsize);
      |   ~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~
analysis-valgrind.cpp:16:18: warning: ‘*alloc_num’ is used uninitialized [-Wuninitialized]
