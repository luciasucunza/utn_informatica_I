/**
 * \fn int main(void)
 * \brief Llena un vector de CANT posiciones y suma su contenido
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 2014.05.30 
 * \return Retorna 0 en caso de exito
 */

/*********************************************
 *          Proceso de compilacion           *
 *                                           *
 * gcc -c vectores1.c -o vectores1.o         *
 * gcc vectores1.o -o vectores1              *
 * ./vectores1                               *
 *                                           *
 ********************************************/


//--------------
//-- Includes --
//--------------

#define CANT 10

int main(void){

  int vec[CANT];
  int contador=0;
  int suma=0;
  
  printf("ingrese un numero entero: ");
  
  do{
      scanf("%d",&vec[contador]);
      contador++;
      printf("Ingrese valor: ");
  }while (contador<CANT);
  
  for(contador=0;contador<CANT;contador++)
    suma = suma + vec[contador];
  
  printf("La suma es: %d\n",suma);
    
  return(0);
}
  