#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main (void)
{
 char buff[200];
 int fd;

 if (mknod("/tmp/myfifo",S_IFIFO | 0666,0) <0)
   {
    perror ("Error en mknod");
    exit (1);
   }

 if ((fd=open ("/tmp/myfifo",O_WRONLY))==-1) 
   {
      error ("Error en Open");
     exit (2);
   }
 
while(strncmp(buff,"FIN",3))
 {
  printf("\nEscriba su mensaje: ");
  gets(buff);
  write(fd,buff,strlen(buff)+1);
 }
 close(fd);
 return(0);
}
  

 
