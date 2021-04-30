#include <pthread.h>
#include <stdio.h>

#define REPETITIONS_NUM 1000000

pthread_t tid0, tid1;
long x = 0;

void *t0()
{
  long i;
  for (i = 0; i < REPETITIONS_NUM; i++)
  {
    x = x + 5;
  }
  printf("t2 finished\n");
}

void *t1()
{
  long i;
  for (i = 0; i < REPETITIONS_NUM; i++)
  {
    x = x - 5;
  }
  printf("t1 finished\n");
}

int main()
{
  pthread_create(&tid0, NULL, t0, NULL);
  pthread_create(&tid1, NULL, t1, NULL);
  pthread_join(tid0, NULL);
  pthread_join(tid1, NULL);
  printf("x value is: %ld\n", x);
  return 0;
}
