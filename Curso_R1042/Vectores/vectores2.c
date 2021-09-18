/**
 * \fn int main(void)
 * \brief Llena un vector de CANT posiciones y suma su contenido, informa promedio.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 2014.05.30 
 * \return Retorna 0 en caso de exito
 * \BUG Tira warning
 */

/*********************************************
 *          Proceso de compilacion           *
 *                                           *
 * gcc -c vectores2.c -o vectores2.o         *
 * gcc vectores2.o -o vectores2              *
 * ./vectores2                               *
 *                                           *
 ********************************************/

//--------------
//-- Includes --
//--------------

#include <stdio.h>

#define CANT 10

int suma_vector(int vec_copia[]);
void carga_vector(int vec_copia[]);

int main(void){

  int vector[CANT];
  int suma=0;
  
  carga_vector(vector);
  suma = suma_vector(vector);
    
  printf("La suma es: %d\n",suma);
  printf("El promedio es: %f\n",(float)suma/CANT);
  
  return(0);
}


/**
 * \fn carga_vector(void)
 * \brief Carga los elementos en el vector
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 2014.05.30 
 * \param 
 * \return
 */


void carga_vector(int vec_copia[]){

  int contador=0;
  
  printf("ingrese un numero entero: ");
  
  do{
      scanf("%d",&vec_copia[contador]);
      contador++;
      printf("Ingrese valor: ");
  }while (contador<CANT);
}



/**
 * \fn suma_vector()
 * \brief Calcula la suma de los elementos del vector
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 2014.05.30 
 * \param 
 * \return Retorna 0 en caso de exito
 */

int suma_vector(int vec_copia[]){
  
  int suma=0;
  int contador=0;
  
  for(contador=0;contador<CANT;contador++)
    suma += vec_copia[contador];
  
  return(suma);
}

