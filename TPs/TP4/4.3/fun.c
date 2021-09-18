#include "main.h"

void stringReverse (char* str )
{
    int i, len;
    char aux[20];
    
    len = strlen(str);
    
    for ( i = 0 ; i < len ; i++ )
	*(aux + i) = *(str + i);
    
    for ( i = 0 ; i < len ; i++ )
	*(str + i) = *(aux + len - i -1);     
}
