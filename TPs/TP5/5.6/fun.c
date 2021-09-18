/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	15-11-16
 * @brief 	Funcion ejercicio 6
*/ 
#include "main.h"
/**
 * @fn			struct nodo * DetectaLazo (struct nodo *)
 * @brief 		Localiza el nodo que genera el lazo circular
 * @param nodoprimero 	Primer nodo de la lista
 * @return		Puntero al nodo que genera el lazo
*/
struct nodo * DetectaLazo (struct nodo *nodoprimero)
{
  struct nodo *nodoanterior, *nodo1;

  for( nodo1 = nodoprimero ; 1 ; nodo1 = nodo1->next)
  {
    for( nodoanterior = nodoprimero ; nodoanterior != nodo1 ; nodoanterior = nodoanterior->next)
    {
      if( nodo1->next == nodoanterior)
      {
	return (nodoanterior);
      }
    }
  }
}