#include "main.h"

int  my_strlen(char *s)				//longitud
{
    int i;
    
    for(i = 0 ; *(s+i) != NULL ; i++ );			//Trabajar el vector con aritmetica de puntero, esto NO I[0]
    
    return i;    
}

int my_strcpy(char* dest, char* orig)		//copiar
{
    int i;
    
    if( dest == 0x0000)					// null = 0x0000 direccione 0
	return 0;
    
    for(i = 0 ; *(orig+i) != NULL ; i++ )
	*(dest+i) = *(orig+i);
    
    *(dest+i) = NULL;
    
    return 1;
}

int my_strcmp(char* cad1, char* cad2)		//Comparar
{
    int i;
    
    if ( my_strcpy(cad1) != my_strcpy(cad2) ) 
      {
	return 1;
      }
    
    for(i = 0 ; *(cad1+i) != NULL ; i++ )
    {
	if ( *(cad1+i) != *(cad2+i)
	{
	    return 1;
	}
    }
    
    return 0;
}

int my_strat(char* dest, char* orig)		//Pegar uno adelante de otro
{
    int i, j, condicion; 
    
    if ( dest == 0x0000 )
	return 0;
    
    i = my_strlen(dest); 		// la long de dest va a ser la posiion del nulo
    
    *(dest+i) = ' ';
    
    condicion = my_strcpy(dest+i+1);
    
    if ( ! my_strcpy(dest+i+1) )
	return 0;
    
    return 1;  
    
}

int cuentapalabras(char*str)
{
    int i, cont;
    for ( i = 0, cont = 1 ; *(str + i) != NULL ; i++ )
    {
      if ( *(str+i) == ' ' )
	  cont++;
    }    
    return 0;
}

