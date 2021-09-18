//Hijo escribe un pipe, padre lo lee y lo muestra en pantalla
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define TAM 10

int main (void)
{
  int pid1, pid2, pid3, fd[2];
  char buffer[TAM];  
  char buffer2[TAM];
  
  pid1 = getpid();
  printf("Mi PID es: %d\n", pid1);
  
  printf("Complete el buffer a transferir\n");
  scanf ("%s", buffer);
  
  if( pipe(fd) )
  {
    perror ("Pipe: ");
    exit(EXIT_FAILURE);
  }  
  
  pid2 = fork();  
    if( pid2 == -1 )
    {
      perror( "Fork: " );
      exit(EXIT_FAILURE);
    }  
    if( pid2 == 0 )
    {
      close( fd[0] );
      pid3 = getpid();
      printf ("Soy hijo, escribo y mi pid es: %d\n",pid3);
      pid3 = getppid();
      printf ("El pid de padre es: %d\n",pid3);
  
      write ( fd[1], buffer, TAM);
      printf("Soy Hijo, escribí y me fui\n");
      
    exit(0);   
      
    }
    else
    {   
      close( fd[1] );
      pid3 = getpid();
      printf("Soy padre, leo y mi pid es: %d\n", pid3);
      
      printf("Esperanndo a Hijo...\n");      
      
      wait(NULL);            
      
      printf("Llegó Hijo...\n");  
      
      read ( fd[0], buffer2, TAM);
      printf("Leo y escribo en pantalla\n");  
      write ( 1, buffer2, TAM  );
      printf ("\n");
    }
    
    exit(EXIT_SUCCESS);    
}

