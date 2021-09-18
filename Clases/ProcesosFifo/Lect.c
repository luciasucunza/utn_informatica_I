#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define PATH_FIFO /home/luciasucunza/Documentos/Info1/Clases/9.27/mififo
#define TAM 300

int main (void)
{
  FILE *fd;  
  char buffer[TAM];
  
  if( mkfifo(PATH_FIFO, 0666) < 0 )
  {
    perror ("mkfifo: ");
    printf ("No hago nada porque lo creó el otro");
  }
  
  fd = open (PATH_FIFO, O_RDONLY);
  
  read (fd, buffer, TAM ); 
  
}