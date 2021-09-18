/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	07-12-16
 * @brief 	Main
*/ 
#include "main.h"
/**
 * @fn 		int main( void )
 * @brief 	Guarda los datos de personas en un archivo
 * @details	Se ingresan los datos de, como maximo, 255 personas en un vector de estructuras, luego se los ordena en orden alfabetico por el apellido para finalmente guardar los datos en un archivo
 * @return 	0 por exito
 */ 
int main (void)
{
  int i = -1;
  struct datos vector[MAX_VECTOR];
    
  do 
  {
    i++;
    carga( (vector+i) );     
  }while( (fin(*(vector+i))) == 0 );
  
  Ordenar( vector );
  
  Guardar( vector );
  
  return 0; 
}
