#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// void inc_n(int *n)
// {
//    increment n to 100 
//   while(++(*n) < 1000000000);
// }

void* threadTask(void* param)
{
  printf("Working...\n");
  // casting back to desired type
  int *p = (int*)param;
  /* increment n to 100 */
  while(++(*p) < 1000000000);
  return 0;
}

int main(int argc, char const *argv[])
{
  int x = 0;
  int y = 0;

  printf("x: %d, y: %d\n", x, y);

  // create thread handles
  pthread_t threadX;
  pthread_t threadY;

  // saves the result of pthread_create(...)
  int result;

  // start a thread and save the result
  result = pthread_create(&threadX, 0, threadTask, (void*)&x);
  // validate the thread
  if (result != 0)
  {
    printf("Create thread has failed...\nError: %d\n", result);
    return 1;
  }

  // start a thread and save the result
  result = pthread_create(&threadY, 0, threadTask, (void*)&y);
  // validate the thread
  if (result != 0)
  {
    printf("Create thread has failed...\nError: %d\n", result);
    return 1;
  }

  // join the threads
  pthread_join(threadX, 0); printf("x increment finished\n");
  pthread_join(threadY, 0); printf("y increment finished\n");

  printf("x: %d, y: %d\n", x, y);

  return 0;
}