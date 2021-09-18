/*Ejemplo de un programa que recibe parámetros como argumento de la función main*/
/*Este programa recibe como argumentos 2 operandos y realiza una operación matemática con ellos*/

#include "argmain2.h"

int Operar (int, int, int);

int main(int argc, char *argv[])
{
    int operacion,resultado;
    
    if(argc != CANT_ARGUMENTOS)
    {
        printf("Debe indicar como parámetros los 2 operandos para realizar la operación\n");
        exit(OK);
    }
    
    system("clear");
    
    printf("Indique la operación matemática a realizar entre los operandos:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("\nElijo la opcion: ");
    scanf("%d",&operacion);
    
    resultado = Operar (OPERANDO1, OPERANDO2, operacion);
    
    printf("\nEl resultado de la operación es: %d\n\n", resultado);
    
    return 0;
    
}

int Operar (int operando1, int operando2, int operacion)
{
    int resultado;
    switch(operacion)
    {
        case SUMA:
            resultado = operando1 + operando2;
            break;
        case RESTA:
            resultado = operando1 - operando2;
            break;
        case MULTIPLICACION:
            resultado = operando1 * operando2;
            break;
        case DIVISION:
            resultado = operando1 / operando2;
            break;
        default:
            printf("Debe seleccionar un numero de 1 a 4\n");
            exit(0);
    }
    return(resultado);
}
