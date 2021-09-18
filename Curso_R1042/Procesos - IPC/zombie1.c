#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (void)
{
 pid_t pid;
 

 while(1)
 {
  pid=fork();

  if (pid==0)
  {
 
   printf("\nSoy el hijo y mi pid es %d\n",getpid());
   exit(0);
  }
  else
   sleep(2);
 } 
 
}
