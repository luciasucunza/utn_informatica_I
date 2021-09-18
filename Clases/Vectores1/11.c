// Informar en la pantalla el conetenido de c/bytes de un numero long long
#include <stdio.h>

int main (void)
{
    
    long long l = 0x1234567812345678;	// &l e un puntero long long
    int i;
    unsigned char *p;			// se carga en char porque quiero barrer cada escalon de memoria
    
    p = (unsigned char *) &l;		// &l e un puntero long long=> caseteo asi puedo asignar
    
    printf("%p\n", p);
    
    for(i = 0 ; i < sizeof(l) ; i++)
    {
	printf("%x \n", (unsigned int)*(p+i));		// *p es un unsigned char y %x (ver en hexa) es un entero => casteo
	// p+i lo pongo para no tener que cambiar el valor de p, no poner p++	
    }
    
    printf("AF%d \n", sizeof(l));
    printf("AF%d \n", sizeof(i));
}
