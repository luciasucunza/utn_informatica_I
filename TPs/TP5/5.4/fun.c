/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	15-11-16
 * @brief 	Funcion ejercicio 4
*/ 
#include "main.h"
/**
 * @fn		void RemoverNodo (struct nodo *)
 * @brief 	Remueve el nodo que se pasa como parametro, de una lista simplemente enlazada
 * @param c 	Nodo a remover
 * @return	Void
*/
void RemoverNodo (struct nodo *c)
{
  *(c) = *(c->next);
}