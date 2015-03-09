#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct param_t
{
  int attr1;
  int attr2;
} param_t;

void* threadTask(void* param)
{

  int i = 0;
  // casting back to desired type
  param_t *p = (param_t*)param;
  printf("\n");
  for (i = 0; i < p->attr1; i++)
  {
    printf("| Loop %d\n| attr1 = %d\n| attr2 = %d\n", i, p->attr1, p->attr2);
    sleep(1); // pauses the thread for 1 sec
    if (i < p->attr1 - 1)
    {
      printf(" ---------------\n");
    }
  }
  printf("\n");

  return 0;
}

int main(int argc, char const *argv[])
{
  // create a thread handle
  pthread_t threadHandle;
  // parameter variable
  param_t testParam = {4,14};

  // start the thread and save the result // cast the param with (void*)
  int result = pthread_create(&threadHandle, 0, threadTask, (void*)&testParam);

  // validate the thread
  if (result != 0)
  {
    printf("Create thread has failed...\nError: %d\n", result);
    return 1;
  }

  // wait till the thread ends
  pthread_join(threadHandle, 0);

  return 0;
}