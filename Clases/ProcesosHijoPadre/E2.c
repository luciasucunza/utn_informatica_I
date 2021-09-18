#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  int pid;
  
  pid = fork();
  
  if( pid == 0)
  {
    printf("Soy el hijo\n");
    exit(0);
  }
  else
  {
    printf("Soy el padre\n");
    wait(NULL);

  }
  return 0; 
}