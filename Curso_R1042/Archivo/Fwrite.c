#include <stdio.h>
#include <errno.h>

struct libros{
     char nombre[10];
     int  codigo;
};

int main(void){
     
     FILE *fp;
     struct libros libro;
     
     //Abro archivo.
    
     fp = fopen("texto.txt","r+");
     if(fp==NULL){
	    fp = fopen("texto.txt","w");
	    if(fp==NULL){
		   printf("%s",strerror(errno));
	    }
     }
     
     //Escribo libro.
     
    strcpy(libro.nombre,"HOLAFERNA");
    libro.codigo=10;
    
   //ESCRIBO ARCHIVO
    
    fwrite(&libro,sizeof(struct libros),1,fp);
    
    //Escribo otro libro
    
    strcpy(libro.nombre,"asdaFERNA");
    libro.codigo=12;
    
    fwrite(&libro,sizeof(struct libros),1,fp);
    
    close(fp);    
     
     
     return 0;
}

