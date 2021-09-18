#include <stdio.h>
#include <errno.h>

struct libros{
     char nombre[10];
     int  codigo;
};

int main(void){
     
     FILE *fp;
     char nombre[40], pass[40];
     
     
     
     //Abro archivo.
     
     fp = fopen("biblio.txt","r+");
     if(fp==NULL){
	    fp = fopen("biblio.txt","w");
	    if(fp==NULL){
		   printf("%s",strerror(errno));
	    }
     }
     
     strcpy(nombre,"Daniela");
     strcpy(pass, "1234");
     fprintf(fp,"Nombre=%s\r\nContraseña=%s\r\n",nombre, pass);
     
     strcpy(nombre,"Feer");
     strcpy(pass,"456");
     
     fprintf(fp,"Nombre=%s\r\nContraseña=%s\r\n",nombre, pass);
     
     close(fp);    
     
     
     return 0;
}