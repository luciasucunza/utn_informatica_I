#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define PATH_FIFO

int main (void)
{
  
  if( mknod(PATH_FIFO, mode, dev) < 0 )
  {
    perror("mknod: ");
    exit (EXIT_FAILURE);    
  }
  
  printf ("Esperando lectores..\n");
  
  fd = open (PATH_FIFO, O_WRONLY)
  
  printf("Econtre un lector, tipee algo");
  
  if ((num = write(fd, s, strlen(s))) == -1))
    perror ("write: ");
  else
    printf("speak: %d bytes escritos\n", num);
  
  close (fd);
  system("rm mififo");
}