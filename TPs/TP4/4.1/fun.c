#include "main.h"

int imprimir (long long* a)
{    
    int i;
    char *p;
    
    p = (char *) a;
    
    for(i = 0 ; i < 8 ; i++)
	printf("%x \n", (unsigned int)*(p+i));
    
    return 0;
}

