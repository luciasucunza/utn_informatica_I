#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){

	int pfds[2];
	char buf[30];
	
	pipe(pfds);
	
	if(!fork()){
		printf("Soy hijo y mi pid es: %d\n",getpid());
		printf("Soy hijo y mi papa es: %d\n",getppid());
		printf("Hijo: escribiendo en el pipe\n");
		write(pfds[1],"test",5);
		printf("Soy el hijo y termine de hacer lo que tenia que hacer\n");
		printf("Soy hijo y me voy\n");
		exit(0);		
	}
	else{
		printf("Soy el padre y mi pid es: %d\n",getpid());
		printf("Padre: leyendo del pipe\n");
		read(pfds[0],buf,5);
		printf("Soy el padre y termine de hacer lo que tenia que hacer\n");
		printf("Padre: lei %s\n",buf);
		wait(NULL);
	}
	return(0);
}
