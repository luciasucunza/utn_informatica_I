#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (void)
{
 char buff[200];
 int fd;

 if ((fd=open("/tmp/myfifo",O_RDONLY))==-1)
   {
    perror ("Error en Open");
   exit (3);
   }


while(strcmp(buff,"FIN"))
 {
  read(fd,buff,40);
  printf("\nMensaje Recibido: %s\n",buff);
 }
 close(fd);
 return(0);
}
  

 
