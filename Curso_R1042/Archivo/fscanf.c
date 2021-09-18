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
     
     fp = fopen("biblio.txt","r");
     if(fp==NULL){
	      printf("%s",strerror(errno));
	   
     }
     
     while(!feof(fp)){                                                 
	    fscanf(fp,"Nombre=%s\r\nContraseña=%s\r\n",nombre, pass);
	    printf("Nombre=%s\nContraseña=%s\n",nombre, pass);
     }
     
     
     close(fp);    
     
     
     return 0;
}