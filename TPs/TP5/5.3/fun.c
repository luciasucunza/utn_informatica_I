/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	15-11-16
 * @brief 	Funciones ejercicio 3
*/ 
#include "main.h" 
/**
 * @fn			CargarLista( struct nodo ** )
 * @brief 		Carga los datos de los alumnos en una lista
 * @param nodoprimero	Puntero donde se guarda la direccion del primer nodo de la lista
 * @return		Void
*/
void CargarLista( struct nodo **nodoprimero )
{
  int flagcargar;
  struct nodo *nodonuevo;
  
  do 
  {
   nodonuevo =(struct nodo *)malloc( sizeof(struct nodo) );
   nodonuevo->datos =(struct alumno *)malloc( sizeof(struct alumno) );
   
   CargarDatos( nodonuevo->datos );
   
   nodonuevo->next = *nodoprimero;
   *nodoprimero = nodonuevo;   
    
    printf( "Ingrese 0 para dejar de cargar datos:	" );
    scanf( "%d", &flagcargar );
  }while( flagcargar );  
}
/**
 * @fn		CargarDatos( struct alumno * )
 * @brief 	Carga los datos en una estructura
 * @param a1 	Estructura en la que se cargan los datos
 * @return	Void
*/
void CargarDatos ( struct alumno * a1 )
{  
  printf ("	NOMBRE: ");
  scanf ("%s", a1->nombre);  
  printf ("	APELLIDO: ");
  scanf ("%s", a1->apellido);
  printf ("	EDAD: ");
  scanf ("%d", &a1->edad);
  printf ("	DNI: ");
  scanf ("%d", &a1->dni);
  printf ("	PROMEDIO: ");
  scanf ("%f", &a1->promedio);
}
/**
 * @fn			RemoverDuplicados( struct nodo * )
 * @brief 		Remueve de la lista los nodos que repitan el DNI de algun nodo anterior
 * @param nodoprimero	Direccion del primer nodo de la lista
 * @return		Void
*/
void RemoverDuplicados( struct nodo *nodo1 )
{
  struct nodo *nodo2, *nodoaux;
  
  for( ; nodo1 != NULL  ; nodo1 = nodo1->next )
  {    
    nodo2 = nodo1;
    while( nodo2->next != NULL )
    {      
      if( nodo1->datos->dni == nodo2->next->datos->dni )
      {
	nodoaux = nodo2->next->next;	
	free( nodo2->next->datos );
	free( nodo2->next );
	nodo2->next = nodoaux;
      }
      else
	nodo2 = nodo2->next;
    }
  }
}
/**
 * @fn			MostrarLista( struct nodo * )
 * @brief 		Muestra el contenido de la lista
 * @param nodoprimero	Direccion del primer nodo de la lista
 * @return		Void
*/
void MostrarLista( struct nodo *nodoprimero )
{
  struct nodo *nodoaux;
  
  for( nodoaux = nodoprimero ; nodoaux != NULL ; nodoaux = nodoaux->next )
    printf( "N:%s	A:%s	E:%d	D:%d	P:%f\n",nodoaux->datos->nombre,nodoaux->datos->apellido,nodoaux->datos->edad,nodoaux->datos->dni,nodoaux->datos->promedio );
}
/**
 * @fn			LiberarLista( struct nodo ** )
 * @brief 		Muestra el contenido de la lista
 * @param nodoprimero	Direccion del primer nodo de la lista
 * @return		Void
*/
void LiberarLista( struct nodo **nodoprimero )
{
  struct nodo *nodoaux;
  
  for( nodoaux = *nodoprimero ; nodoaux != NULL ; nodoaux = *nodoprimero )
  {
    (*nodoprimero) = nodoaux->next;
    free( nodoaux->datos );
    free( nodoaux );    
  }  
}