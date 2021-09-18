/**
 *	\file  calculadora.c
  *	\brief Calculadora de operaciones básicas aplicando puntero a función.
 *	\author Fernando Pose (fernandoepose@gmail.com)
 *	\date 2014.08.29
 */
 
 
#include <stdio.h>
#include <stdlib.h>

int Funcion_sumar(int ,int);
int Funcion_restar(int ,int);
int Funcion_multiplicar(int ,int);
float Funcion_dividir(int ,int); //Devuelve el resultado - NO el resto!

int main(void){

	int num1,num2,opcion,resultado;

   int (*func[4])(int,int);       //Prototipo (retorno)(*nombre)(parametros)
   func[0] = Funcion_sumar;       //A que apunta cada bloque del vector de
   func[1] = Funcion_restar;                     //puntero a funcion.
   func[2] = Funcion_multiplicar;
   func[3] = Funcion_dividir;

   printf("Ingrese el primer valor: ");
   scanf("%d",&num1);
   printf("Ingrese el segundo valor: ");
   scanf("%d",&num2);

   printf("1- Sumar\n");
   printf("2- Restar\n");
   printf("3- Multiplicar\n");
   printf("4- Dividir\n");
   scanf("%d",&opcion);
   resultado = func[opcion-1](num1,num2);
   printf("Resultado = %d",resultado);
   getchar();
   getchar();
   return(0);
}



int Funcion_sumar(int num1 ,int num2){
	return(num1+num2);
}
int Funcion_restar(int num1 ,int num2){
	return(num1-num2);
}
int Funcion_multiplicar(int num1 ,int num2){
	return(num1*num2);
}
float Funcion_dividir(int num1 ,int num2){
	return(num1/num2);
}

