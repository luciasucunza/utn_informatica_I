#include <stdio.h>
#include <stdlib.h>

typedef struct complejos
{
  float real;
  float imag;
}Complex;

Complex Suma (Complex * , Complex *);
Complex Resta (Complex *, Complex *);
Complex Producto (Complex *, Complex *);
Complex Cociente (Complex *, Complex *);
Complex Conjugado (Complex *);