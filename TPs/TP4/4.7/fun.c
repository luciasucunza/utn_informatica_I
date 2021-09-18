#include "main.h"

int validateString( char *str, int (*fun) (char *) )
{
  int retorno;
  retorno = fun (str);
  
  return retorno;
}

int validateIP( char *str )
{
  int i, len, j;
  char aux[3];
  
  len = strlen( str );
  
  if( len > 15 || len < 13 ) 
    return FALSE;  
  
  for( i = 0 ; i < len ; i++)
  {
    if( *(str+i) == '/' || *(str + i) < '.' || *(str + i) > '9' )
      return FALSE;
  }
  
  for( j = 0 ; i != 0 ; i-- )
  {
    if( *(str+i) != '.' )
    {
      *( aux+j ) = *( str+i );
      j++;
    }
    
    else
    {
      *( aux+j ) = '\0';
      j = 0;
      
      if( !(menor(aux)) )
	return FALSE;      
    }
  }
  return TRUE;
}

int menor( char *str )
{
  int i, resultado = 0;
  
  for( i = 0 ; *( str+i ) != '\0' ; i++)
  {
    resultado = resultado + ((*(str+i) - '0') * pow( 10, i ));
  }
  
  if( resultado >= 0 && resultado <=255)
    return TRUE;
  else
    return FALSE;
}

int validateCorreo( char *str )
{
  int i, len, arroba;
  
  len = strlen (str);

  for( i = 0 , arroba = 0 ; i < len ; i++)
  {
    if( *(str+i) == '@')
    {
      arroba++;
      
      if ( i < 4)
	return FALSE;      
    } 
    if( *(str+i) < '0' && *(str+i) != '.' )
      return FALSE;  
    
    if( *(str+i) > '9' && *(str+i) < '@' )
      return FALSE;      
    
    else if( *(str+i) > 'Z' && *(str+i) < '_' )
    {
      if( *(str+i) != '_' )
	return FALSE;      
    }
    
    else if( *(str+i) > 'z')
      return FALSE;        
  }
  
  if( arroba != 1)
    return FALSE;
  
  return TRUE;
}

int validateTarjeta( char *str )
{
  int i;
  
  if( strlen(str) != 16 )
    return FALSE;
  
  for( i = 0 ; i < 16 ; i++ )
  {
      if( *(str + i) < '0' || *(str + i) > '9')
	return FALSE;
  }
  return TRUE;
}
