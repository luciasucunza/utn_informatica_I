#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(void){
	
	int pfds[2];
	char buf[30];
	int aux;
	
	aux = pipe(pfds);
	if(aux == -1){
		perror("pipe");
		exit(1);
	}
	
	printf("file descriptor para escritura #%d\n",pfds[1]);
	write(pfds[1],"test",5);
	printf("file descriptor para lectura #%d\n",pfds[0]);
	read(pfds[0],buf,5);
	printf("leo: %s\n",buf);
	
	return(0);
}
