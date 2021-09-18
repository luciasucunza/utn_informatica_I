#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define PATH_FIFO /home/luciasucunza/Documentos/Info1/Clases/9.27/mififo
#define TAM

int main (void)
{
  FILE *fd;
  char buffer[300];
  
  if( mkfifo(PATH_FIFO, 0666) < 0 )
  {
    perror ("mkfifo: ");
    exit (EXIT_FAILURE);
  }
  
  fd = open (PATH_FIFO, O_WRONLY);
  
  write (1, buffer, strlen(buffer) + 1);
  
}