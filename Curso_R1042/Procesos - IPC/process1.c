#include <stdio.h>
#include <unistd.h>


int main (void)
{
 pid_t pid;

 pid=fork();

 if (pid>0)
  {
   printf("\nSoy el Padre y mi pid es %d\n",getpid());
   sleep(5);
   printf("\nProceso Padre Finalizado\n");
   return(0);
   }
 else
  {
   printf("\nSoy el hijo y mi pid es %d\n",getpid());
   sleep(10);
   printf("\nProceso Hijo Finalizado\n");
   printf("mi padre es: %d\n",getppid());
   return(0);
  }
}
