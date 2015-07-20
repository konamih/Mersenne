#include <time.h>
#include <stdio.h>

int main(void)
{
   clock_t start, end;
   long l;

   start = clock();

   for (l=0; l<100000000; l++);

   end = clock();
   printf("空ループ1億回の時間: %f秒\n", (double)(end - start) / CLOCKS_PER_SEC);

   return 0;
}
