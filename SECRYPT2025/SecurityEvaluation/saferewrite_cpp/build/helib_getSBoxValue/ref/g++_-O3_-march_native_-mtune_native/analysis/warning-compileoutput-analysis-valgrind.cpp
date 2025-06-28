analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:16:28: warning: ‘*alloc_num’ is used uninitialized [-Wuninitialized]
   16 |   alloc_z[0] = getSBoxValue(*alloc_num);
      |                ~~~~~~~~~~~~^~~~~~~~~~~~
