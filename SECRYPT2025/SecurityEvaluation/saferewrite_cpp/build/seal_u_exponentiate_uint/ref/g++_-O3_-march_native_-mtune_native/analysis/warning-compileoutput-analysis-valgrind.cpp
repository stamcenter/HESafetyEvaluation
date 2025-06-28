analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:18:33: warning: ‘*alloc_exponent’ is used uninitialized [-Wuninitialized]
   18 |   alloc_z[0] = exponentiate_uint(*alloc_operand,*alloc_exponent);
      |                ~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
analysis-valgrind.cpp:18:33: warning: ‘*alloc_operand’ is used uninitialized [-Wuninitialized]
