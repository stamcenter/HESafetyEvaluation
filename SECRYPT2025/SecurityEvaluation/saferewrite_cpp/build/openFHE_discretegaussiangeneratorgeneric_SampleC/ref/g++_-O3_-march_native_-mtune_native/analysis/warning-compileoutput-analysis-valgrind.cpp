analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:16:23: warning: ‘*alloc_center’ is used uninitialized [-Wuninitialized]
   16 |   alloc_c[0] = SampleC(*alloc_center);
      |                ~~~~~~~^~~~~~~~~~~~~~~
