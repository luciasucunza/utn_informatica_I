/**
 * \file programa_child.c
 * \brief Programa que crea "x" procesos hijos, luego los mata.
 * \author Pose, Fernando Ezequiel (fernandoepose@gmail.com)
 * \date 2015.05.04
 * \version 1.0.0
 */


//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>

//-------------
//-- Defines --
//-------------

#define CANT_ARGUMENTOS 2

//----------------
//-- Prototipos --
//----------------

void soy_hijo(int childs);


/**
 * \fn int main(int argc, char *argv[])
 * \brief Función principal del programa: Crea los procesos y los mata.
 * \author Pose, Fernando Ezequiel (fernandoepose@gmail.com)
 * \date 2015.05.04
 * \return -1 si falla, 0 si no falla.
 */



int main(int argc, char *argv[]){

	if(argc != CANT_ARGUMENTOS){
        printf("Debe indicar hijos a crear\n");
        return(-1);
    }
    system("clear");
	
	int cant_hijos = 0;
	pid_t pid;
		
	do{
		pid = fork();
		switch(pid){
		
			case -1:
				printf("Error al crear el child\n");
				return(-1);
				break;
		
			case 0:
				soy_hijo(atoi(argv[1]));
				break;
			
			default:
				sleep(2);
				break;
		}
		cant_hijos +=1; 
	}while(cant_hijos != atoi(argv[1]));

	do{
		wait();
		printf("Zombie owned\n");
		cant_hijos-=1;
	}while(cant_hijos>0);
	
	return(0);
}


/**
 * \fn void soy_hijo(int childs)
 * \brief Controla tiempo de cada hijo.
 * \author Pose, Fernando Ezequiel (fernandoepose@gmail.com)
 * \date 2015.05.04
 * \return La función no retorna
 */

void soy_hijo(int childs){
	
	int random = 0;
	int tiempo = 0;
	
	srand (time (NULL));	
	
	printf("Soy el hijo y mi PID es: %d\n",getpid());
	printf("El PID de mi padre es:   %d\n", getppid());
	
	random = rand()%30;
	tiempo = random + childs*2;
	printf("El tiempo que duro antes de eliminarme es: %d\n",tiempo);
	sleep(tiempo);
	printf("Hijo zombie: %d\n\n",getpid());
	exit(1);
}




