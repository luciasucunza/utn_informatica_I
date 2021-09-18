/* Escriba un programa que abra un archivo llamado "log.info1" en el directorio
de trabajo, si no existe lo crea y redirecciona la salida standard al archivo
abierto o creado, luego, el programa, lee lineas desde el stdin y las escribe
en el archivo por medio de la funcion fprintf. (variante: escribir el archivo
mediante alguna otra funcion de stream de texto). */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARACTERES 50

int main(void){

	FILE *fp;
   char palabra[MAX_CARACTERES];

   /************ Abro el archivo ***************/

   fp = fopen("log.txt","w+");
   if(fp == NULL){
   	puts("Error al abrir el archivo");
      return(-1);
   }

   /********** Realizo la consigna *************/

   puts("Escriba ""salir"" para terminar la operacion, cadenas de no mas de 50 caracteres.");
   scanf("%s",palabra);
   while(strcmp(palabra,"salir")!=0){
		fprintf(fp,"%s ",palabra);
      scanf("%s",palabra);
   }
   fclose(fp);
   puts("Fin del programa");
   getchar();
   return(1);
}






