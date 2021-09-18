#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

 

void main(void) {

        char	local_buffer[40];
		int		semid, shmid,i;
		char		*shmptr;
        key_t           clave;
        struct sembuf   SemArg;
        
        
        clave=ftok(".",101);
          
        shmid=shmget(clave, 40,IPC_CREAT | 0666);
        shmptr=shmat(shmid,NULL,0);

        semid=semget(clave, 2, IPC_CREAT | 0666);

        
	while(1)
        {
        
         
         SemArg.sem_num = 1;
         SemArg.sem_op=-1;
         SemArg.sem_flg=SEM_UNDO;
         semop(semid, &SemArg, 1 );
          
         printf("\n\nMensaje Leido: %s\n\n",shmptr);
         
         SemArg.sem_num = 0;
         SemArg.sem_op=1;
         SemArg.sem_flg=SEM_UNDO;
         semop(semid, &SemArg, 1 );
        }
}

					

		
				
