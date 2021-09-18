/**
 * \fn int main(void)
 * \brief Función principal para probar la funcion strBubleSort
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \return 0 si salio bien.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARACTERES 50

void strBubleSort(int cant, char *arr[]);

int main(void){

	int i = 0;
   int cant = 7;

   char **vector = NULL;

   vector = (char **) malloc ( sizeof(char *) *  cant );
	for (i = 0 ; i < cant ; i++){
   	vector[i] = (char *) malloc (sizeof(char) * MAX_CARACTERES);
		if(!vector[i]){
      	printf ("MALLOC_ERROR\n");
         return 1;
      }
		printf("\nIngrese una palabra: ");
      fgets(vector[i], MAX_CARACTERES, stdin);
   }

   /***** Imprimo vector desordenado. *****/
   puts("El vector no ordenado es el siguiente: \n");
   for(i=0;i<cant;i++)
   	printf("Palabra[%d]: %s\n",i,vector[i]);
   /***** Ordeno el vector e imprimo  *****/
   strBubleSort(cant,vector);
   puts("\nEl vector ordenado es el siguiente: \n");
   for(i=0;i<cant;i++)
   	printf("Palabra[%d]: %s\n",i,vector[i]);
   printf("\n***** Fin de la aplicacion ******");
   getchar();
   return(0);
}


/**
 * \fn void strBubleSort(int cant, char *arr[])
 * \brief Ordena el arreglo 
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \param Cantidad de elementos a ordenar
 * \param arreglo a ordenar
 */

void strBubleSort(int cant, char *arr[]){

	int i,j; //Contadores de for.
   char *buffer=NULL; //Para el swap

   for(i=0 ; i<(cant-1) ; i++){
   	for(j=i+1 ; j<cant ; j++){
       	/* SWAP - Intercambio de nodos */
      	if(strcmp(arr[i],arr[j])>0){
         	buffer=arr[j];
            arr[j]=arr[i];
            arr[i]=buffer;
         }
      }
   }
}

