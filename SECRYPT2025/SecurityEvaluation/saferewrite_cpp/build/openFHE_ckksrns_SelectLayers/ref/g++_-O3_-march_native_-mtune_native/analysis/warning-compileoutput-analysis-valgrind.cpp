analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:18:28: warning: ‘*alloc_b’ is used uninitialized [-Wuninitialized]
   18 |   alloc_d[0] = SelectLayers(*alloc_a,*alloc_b);
      |                ~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~
analysis-valgrind.cpp:18:28: warning: ‘*alloc_a’ is used uninitialized [-Wuninitialized]
