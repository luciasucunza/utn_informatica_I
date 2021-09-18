#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void chldHandler (void);

int main (void)
{
 pid_t pid;
 struct sigaction chldAction;

 memset (&chldAction, 0, sizeof(chldAction));

 chldAction.sa_handler = (void *) chldHandler;
 chldAction.sa_restorer = NULL;

 sigaction (SIGCHLD, &chldAction, NULL);
 

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

void chldHandler (void)
{
 wait(NULL);
}

