/**
 * Authors:
 * Charles Bido
 * Emanuel Taylor
 * // insert your names here
 */

#include <stdio.h>
#include <stdlib.h>

void inc_n(int *n)
{
  /* increment n to 100 */
  while(++(*n) < 1000000000);
}

int main()
{

  /**
   * For piping:
   * 0 = read
   * 1 = write
   */
  int fd[2];
  pipe(fd);

  int x = 0, y = 0;
  pid_t pid;

  printf("x: %d, y: %d\n", x, y);

  pid = fork();

  // if child
  if (pid == 0)
  {
    // close the read-descriptor 
    close(fd[0]);

    // increment x
    inc_n(&x);
    printf("x increment finished\n");

    // "send" value to the parent process
    write(fd[1], &x, sizeof(x));

    return 0;
  }
  // if parent
  if (pid > 0)
  {
    // close the write-descriptor
    close(fd[1]);

    // increment y
    inc_n(&y);
    printf("y increment finished\n");

    // read in the piped value from the child process
    read(fd[0], &x, sizeof(x));

    // close the read-descriptor
    close(fd[0]);
    printf("x: %d, y: %d\n", x, y);
  }
  return 1;
}
