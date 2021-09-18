/**
 * \fn void ordenar(int *arreglo,int tamano){
 * \brief Función que ordena un vector de enteros 
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \param Vetor de (int) a ordenar
 * \param Cantidad de elementos a ordenar
 */
#include <stdio.h>
#include <stdlib.h>

void ordenar(int *arreglo,int tamano){

	int i,j,buffer;

   for(i=0;i<(tamano-1);i++){
   	for(j=i+1;j<tamano;j++){
      	if(*(arreglo+i)>*(arreglo+j)){
         	buffer = *(arreglo+j);
            *(arreglo+j) = *(arreglo+i);
            *(arreglo+i) = buffer;
         }
      }
   }
}




