/**
 * \fn int main(void)
 * \brief Imprime tamaño de variables utilizando el operador sizeof();
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 16/08/14
 * \return 0 si salio bien.
 */

#include <stdio.h>
#include <stdlib.h>

/* sizeof(argumento) devuelve el número de bytes del tipo "argumento" */

int main()
{
    printf("El tamano en bytes de ""unsigned char"" = %d\n",sizeof(unsigned char));
    printf("El tamano en bytes de ""char""          = %d\n",sizeof(char));
    printf("El tamano en bytes de ""unsigned int""  = %d\n",sizeof(unsigned int));
    printf("El tamano en bytes de ""int""           = %d\n",sizeof(int));
    printf("El tamano en bytes de ""unsigned long"" = %d\n",sizeof(unsigned long));
    printf("El tamano en bytes de ""long""          = %d\n",sizeof(long));
    printf("El tamano en bytes de ""float""         = %d\n",sizeof(float));
    printf("El tamano en bytes de ""double""        = %d\n",sizeof(double));
    printf("El tamano en bytes de ""long double""   = %d\n",sizeof(long double));
    return 0;
}
