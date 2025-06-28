analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:16:22: warning: ‘*alloc_x’ is used uninitialized [-Wuninitialized]
   16 |   alloc_z[0] = verify(*alloc_x);
      |                ~~~~~~^~~~~~~~~~
