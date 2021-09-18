#include "main.h"

void replace (char *s, char nuevo, char viejo)
{
  int i, len;
  
  len = strlen(s); 
  
  for ( i = 0 ; i < len ; i++ )
  {    
    if ( *(s+i) == viejo )
      *(s+i) = nuevo;
  }   
}