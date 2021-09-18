#include <stdio.h>
#include <string.h>
#include <math.h>

#define FALSE 0
#define TRUE 1

int validateIP( char *);
int validateTarjeta( char *);
int validateCorreo( char *);

int menor( char *);

int validateString( char *, int (*) (char *) );
