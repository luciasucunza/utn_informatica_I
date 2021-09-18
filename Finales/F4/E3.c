#include<stdio.h>

typedef struct _carta
{
  int nuemero;
  char palo;
  char *literal
  struct _carta*sig;
} miCarta;

void leerCartas( miCarta **Primera);
int cortarBaraja( miCarta **Primera);
int verificarCartas( miCarta **Primera);
void cargarLiteral( miCarta **Primera);


void leerCartas( miCarta **Primera)
{
  FILE *fd_cartas;
  miCarta *nuevonodo;
  
  fd_cartas = fopen( "cartasEntrada.txt", r );

  if( fd_cartas == NULL )
    return ERR_APERTURA;
  
  (*Primera ) == NULL;
  
  while( !feof(fd_cartas) )
  {
    if( (nuevonodo = (miCarta *)malloc(sizeof(miCarta) ) ) == NULL )
      return ERR_MEMORIA;
    
    nodonuevo->sig = (*Primera);
    *Primera = nodonuevo;
    
    if( (fscanf( fd_cartas, "%d-%c\n", &nodonuevo->numero, nodonuevo->palo)) == -1 )
      return ERR_LECTURA;
  }
  fclose( fd_cartas );
}

int cortarBaraja( miCarta **Primera)
{
  int i, n;
  miCarta *nodoaux;
  
  for( nodoaux = *Primera ; nodoaux->sig  != NULL ; nodoaux = nodoaux->sig );

  nodoaux->sig = *Primera;
  
  for( nodoaux = *Primera , i = 0 ; i < n ; i ++ )
    nodoaux = nodoaux->sig ;

  *Primera = nodoaux; 
}
int verificarCartas( miCarta **Primera)
{
  miCarta *nodoaux, *nodoaux2;
  for( nodoaux = *Primera ; nodoaux->sig != NULL ; nodoaux = nodoaux->sig )
  {
    for( nodoaux2 = nodoaux->sig ; nodoaux2 != NULL ; nodoaux2 = nodoaux2->sig )
    {
      if( nodoaux->numero == nodoaux2->numero )
      {
	if( !(strcmp(nodoaux->palo, nodoaux2->palo)) )
	  return 1;
      }    
    }
  }
  return 0;
}

void cargarLiteral( miCarta **Primera);
{
  int i;
  char aux[16];
  
  for( nodoaux = miCarta ; nodoaux->sig != NULL ; nodoaux = nodoaux->sig )
  {
    switch ( nodoaux->numero )
    {
      case 1:
	strcpy( aux, "Uno de");
	i = 6;
	break;
      case 2:
	strcpy( aux, "Dos de");
	i = 6;
	break;
      case 3:
	strcpy( aux, "Tres de");
	break;
	i = 7;
      case 4:
	strcpy( aux, "Cuatro de");
	i = 9;
	break;
      case 5:
	strcpy( aux, "Cinco de");
	i = 8;
	break;
      case 6:
	strcpy( aux, "Seis de");
	i = 7;
	break;
      case 7:
	strcpy( aux, "Siete de");
	i = 8;
	break;
      case 8:
	strcpy( aux, "Ocho de");
	i = 7;
	break;
      case 9:
	strcpy( aux, "Nueve de");
	i = 8;
	break;
      case 10:
	strcpy( aux, "Diez de");
	i = 7;
	break;      
      case 11:
	strcpy( aux, "Once de");
	i = 7;
	break;      
      case 12:
	strcpy( aux, "Doce de");
	i = 7;
	break;
    }
    switch ( nodoaux->palo)
    {
      case 'O':
	strcpy( &(aux[i]) , "Oro" );
	i = i+4;
	break;
      case 'C':
	strcpy( &(aux[i]) , "Copa" );
	i = i+5;
	break;
      case 'E':
	strcpy( &(aux[i]) , "Espada" );
	i = i+7;
	break;
      case 'B':
	strcpy( &(aux[i]) , "Basto" );
	i = i+6;
	break;
    }
    nodoaux->literal = (char *)malloc( i );
    strcpy( nodoaux->literal, aux );
  }  
}




