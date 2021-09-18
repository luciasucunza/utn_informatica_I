#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>


union semun
{
 int val;
 struct semid_ds *buf;
 unsigned short int *array;
 struct seminfo *__buf;
 };
 

void main(void) {

        char	local_buffer[40];
		int		semid, shmid,i;
		char		*shmptr;
        key_t           clave;
        struct sembuf   SemArg;
        union semun InitVal;
        
        clave=ftok(".",101);
          
        shmid=shmget(clave, 40,IPC_CREAT | 0666);
        shmptr=shmat(shmid,NULL,0);

        semid=semget(clave, 2, IPC_CREAT | 0666);
        InitVal.val=1;
        semctl(semid,0,SETVAL,InitVal);
        InitVal.val=0;
        semctl(semid,1,SETVAL,InitVal);
	while(1)
        {
         
         SemArg.sem_num = 0;
         SemArg.sem_op=-1;
         SemArg.sem_flg=SEM_UNDO;
         semop(semid, &SemArg, 1 );
        
         printf("\n\nEscriba el Mensaje:");
         gets(local_buffer); 
         strncpy(shmptr,local_buffer,40);
         
         SemArg.sem_num = 1;
         SemArg.sem_op=1;
         SemArg.sem_flg=SEM_UNDO;
         semop(semid, &SemArg, 1 );
        }
}
				
