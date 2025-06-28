analysis-valgrind.cpp: In function ‘int main(int, char**)’:
analysis-valgrind.cpp:18:30: warning: ‘*alloc_slots’ is used uninitialized [-Wuninitialized]
   18 |   alloc_d[0] = ReduceRotation(*alloc_index,*alloc_slots);
      |                ~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~
analysis-valgrind.cpp:18:30: warning: ‘*alloc_index’ is used uninitialized [-Wuninitialized]
