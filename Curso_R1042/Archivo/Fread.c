#include <stdio.h>
#include <errno.h>

struct libros{
     char nombre[10];
     int  codigo;
};

int main(void){
     
     FILE *fp;
     struct libros libro;
     
     fp = fopen("texto.txt","r");
     while(!feof(fp)){
	    
	    fread(&libro,sizeof(struct libros),1,fp);
	    
	    printf("%s\n",libro.nombre);
	    printf("%d\n",libro.codigo);
     }
	    
	    fclose(fp);
     return 0;
}

//El leer me escribe dos veces el ultimo dato del archivo...