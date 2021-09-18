#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 0
#define ERR_MEMORY 1
#define ERR_ITEM -1

typedef struct sub_s
{
  char id[100];				//Identificador único del subscriptor
  unsigned int *canales;		// Lista de canales a los que esta suscripto
  int (* enviar )( char * );		//Puntero a función para enviar msj
  struct sub_s *sig;
}sub_t;

int suscribir ( sub_t **s, char *id, unsigned int *canales, int (*enviar)(char *) );
//AgregaRR un suscriptor a la lista
//Devuelve OK por exito
//ERR_MEMORY error por memoria
//ERR_ITEM ya existe, no lo agrego
int desuscribir ( sub_t **s, char *id );
//Quita un suscriptor de la lista
//Liberar Memoria
//Devuelve OK por exito
//ERR_MEMORY errror por memoria
//ERR_ITEM si no existe
int publicar ( sub_t *s, char *msg, unsigned int canal );
//Busca suscriptores conocidos que esten colgados al canl y les envia un msj especificado
//Devuevle OK por exito
//ERR_ITEM si no hay subsscriptores para el canal

int Enviar2(char *msj);
int Enviar1(char *msj);

int main (void)
{
  int opcion, canales[4];
  char id[100], msj[100];
  sub_t *s, *subaux;
   
  s = NULL;
  printf("Ingrese la opcion 1)Susribir 2)Desuscribir 3)Publicar 4)Salir\n");
  scanf("%d",&opcion);
  while( opcion != 4)
  {
    if( opcion == 1 )
    {
      printf("Ingrese el id a agregar\n");
      scanf("%s", id );
      printf("Ingrese 1,2 o 3 canales y luego rellene con 0\n");
      scanf("%d", &canales[0] );
      scanf("%d", &canales[1] );
      scanf("%d", &canales[2] );
      scanf("%d", &canales[3] );
      printf("Ingrese Enviar1 (1)o Enviar2(0)\n");
      scanf("%d", &opcion );
      if( opcion )
	suscribir(&s, id, canales, Enviar1);
      else
	suscribir(&s, id, canales, Enviar2);
    }
    else if( opcion == 2 )
    {
      printf("Ingrese el id a eliminar\n");
      scanf("%s", id );
      desuscribir(&s, id);
    }
    else 
    {
      printf("Ingrese el MSJ\n");
      scanf("%s", msj );
      printf("Ingrese el canal\n");
      scanf("%d", &canales[0] );
      publicar( s, msj ,canales[0])  ;    
    }
    
    printf("Ingrese la opcion 1)Susribir 2)Desuscribir 3)Publicar 4)Salir\n");
    scanf("%d",&opcion);    
  }
  
  for( subaux = s ; subaux != NULL; subaux = subaux->sig)
  {
    
    printf("Salid del for22");
    printf("El Id es %s \n", subaux->id);
    printf("Los canales son %d, %d, %d, %d\n", *(subaux->canales), *((subaux->canales)+1), *((subaux->canales)+2), *((subaux->canales)+3) );    
  
    printf("Salid del for11");
  }
  printf("Salid del for");
  return 0;
}

int Enviar1(char *msj)
{
  printf("Enviar1: %s\n", msj);
}

int Enviar2(char *msj)
{
  printf("Enviar2: %s\n", msj);
}

int CantidadDeCanales( sub_t *subscriptor )
{
   int i; 
   for( i = 0 ; *((subscriptor->canales)+i) != 0 ; i++ )
   {
     printf("%d\n", *((subscriptor->canales)+i));
   }
   return i;
}
  
int suscribir ( sub_t **s, char *id, unsigned int *canales, int (*enviar)(char *) )
{
  sub_t *nuevosub;
  int cantCanales, i;
  unsigned int *vectorcanales;

  
 //BUSCO QUE NO EXISTA
  for( nuevosub = (*s) ; nuevosub != NULL ; nuevosub = nuevosub->sig )
  {
    if( !(strcmp( nuevosub->id, id )) )
      return ERR_ITEM; 
  }
  
  //PIDO LA MEMORIA DE LA ESTRUCTIRA SUB
  if( ( nuevosub = (sub_t *) malloc ( sizeof(s) ) ) == NULL )
    return ERR_MEMORY;
  //HAGO QUE EL NUEVO SEÑALE AL PRIMERO (A NULL SI ES EL 1°), Y QUE AHORA EL PRIMERO SE EL NUEVO
  nuevosub->sig = *(s);
  *(s) = nuevosub;
  
  //CARGO EL CONTENIDO DE LA FUNCION
  nuevosub->enviar = enviar;
  
  //CARGO EL ID  
  strcpy( nuevosub->id, id );  
  
  //CARGO LOS CANALES
  cantCanales = CantidadDeCanales( nuevosub);
  
  if( ( nuevosub->canales = (unsigned int *)malloc(4*cantCanales)) == NULL )
       return ERR_MEMORY;  
  
//Con el = tambien copia el cero para indicar ue es el ultimo
  for( i = 0 ; i <= cantCanales ; i++ )
     *( vectorcanales+i ) = *( canales+i );    
 
  nuevosub->canales = vectorcanales;
  return OK;
}

int desuscribir ( sub_t **s, char *id )
{
  sub_t *subaux, *subant = NULL;
  
  //AVERIGUO SI LA LISTA TIENE ELEMENTOS
  if( *(s) == NULL )
    return ERR_ITEM;  
  
  //RECORRO LA LISTA
  for( subaux = *(s) ; subaux != NULL ; subant = subaux, subaux = subaux->sig )
  {
    //SI TIENEN EL MISMO ID
    if( !(strcmp( subaux->id, id )) )
    {
      //SI ES EL PRIMERO
      if( subant == NULL)
	(*s) = subaux->sig;
      //SI NO ES EL PRIMERO
      else
	subant->sig = subaux->sig;
      
      free( subaux->canales ); 
      free( subaux );
      break;
    }
  }
  
    return ERR_ITEM;
}

int publicar ( sub_t *s, char *msg, unsigned int canal )
{
  sub_t *subaux = s;
  int i, cantCanales, retorno = 0;
  
  if( subaux  == NULL )
    return ERR_ITEM;
  
  while( subaux != NULL )
  {
    cantCanales = CantidadDeCanales( subaux );
    for( i = 0 ; i < cantCanales ; i++ )
    {
      if( *((subaux->canales)+i) == canal )
      {
	(*(subaux->enviar))(msg);
	retorno ++;
      }
    }    
    subaux = subaux->sig;
  }
  if( retorno )
    return ERR_ITEM;
  else
    return OK;
}









