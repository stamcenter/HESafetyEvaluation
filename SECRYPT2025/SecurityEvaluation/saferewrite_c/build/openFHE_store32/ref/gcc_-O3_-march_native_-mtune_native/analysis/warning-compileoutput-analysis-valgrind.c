analysis-valgrind.c: In function ‘main’:
analysis-valgrind.c:18:32: warning: ‘*alloc_dst’ is used uninitialized [-Wuninitialized]
   18 |   alloc_a[0] = store32(alloc_w,*alloc_dst);
      |                                ^~~~~~~~~~
