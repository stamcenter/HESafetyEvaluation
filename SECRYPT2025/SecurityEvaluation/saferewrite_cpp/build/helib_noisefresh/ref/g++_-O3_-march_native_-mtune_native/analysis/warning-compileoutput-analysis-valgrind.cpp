analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:16:18: warning: ‘*alloc_phim’ is used uninitialized [-Wuninitialized]
   16 |   boundFreshNoise(*alloc_m,*alloc_phim);
      |   ~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
analysis-valgrind.cpp:16:18: warning: ‘*alloc_m’ is used uninitialized [-Wuninitialized]
