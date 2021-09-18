#include "info1.h"

//FORMA 1
void contarPalosCortosConIf (void)
{
	//Definimos nuestras variables a utilizar (Las variables las definimos en minuscula)
	int oro,espada,basto,copa,carta,cont;

	//Inicializamos las variables con un valor arbitrario
	oro = espada = basto = copa = cont = carta = 0;


	//Empezamos nuestro lazo repetitivo. 
	//Tomando como tope 14 (Ya que pregunto por MENOR a 15)
	// Esto se contaria como 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14
	while(cont < 15)
	{
		//Pedimos una carta
		printf("\nPor favor ingrese el tipo de carta que esta entrando. Recuerde: \nORO: 1\nESPADA: 2\nBASTO: 3\nCOPA: 4\nCOMODIN: Cualquier otro numero\n");
		scanf("%d",&carta);

		//Aumentamos el contador
		cont++;

		//Aumentamos el contador correspondiente a cada tipo de carta
		if(carta == ORO)
		{
			oro++;
		}
		if(carta == ESPADA)
		{
			espada++;
		}
		if(carta == BASTO)
		{
			basto++;
		}
		if(carta == COPA)
		{
			copa++;	
		}
	}

	//Imprimimos todo nuestro trabajo
	printf("\nORO = %d,ESPADA = %d, COPA = %d, BASTO = %d, COMODINES = %d\n",oro,espada,copa,basto,cont - oro - espada - copa - basto);

	//Devuelvo void
	//RECORDAR: Todas las funciones en C devuelven un valor, este puede ser void
	return;
}
//FORMA 2
void contarPalosCortosConIfElse (void)
{
	//Definimos nuestras variables a utilizar (Las variables las definimos en minuscula)
	int oro,espada,basto,copa,carta,cont;

	//Inicializamos las variables con un valor arbitrario
	oro = espada = basto = copa = cont = carta = 0;


	//Empezamos nuestro lazo repetitivo. 
	//Tomando como tope 14 (Ya que pregunto por MENOR a 15)
	// Esto se contaria como 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14
	while(cont < 15)
	{
		//Pedimos una carta
		printf("\nPor favor ingrese el tipo de carta que esta entrando. Recuerde: \nORO: 1\nESPADA: 2\nBASTO: 3\nCOPA: 4\nCOMODIN: Cualquier otro numero\n");
		scanf("%d",&carta);

		//Aumentamos el contador
		cont++;

		//Aumentamos el contador correspondiente a cada tipo de carta
		if(carta == ORO)
		{
			oro++;
		}
		else if(carta == ESPADA)
		{
			espada++;
		}
		else if(carta == BASTO)
		{
			basto++;
		}
		else if(carta == COPA)
		{
			copa++;	
		}
	}

	//Imprimimos todo nuestro trabajo
	printf("\nORO = %d,ESPADA = %d, COPA = %d, BASTO = %d, COMODINES = %d\n",oro,espada,copa,basto,cont - oro - espada - copa - basto);

	//Devuelvo void
	//RECORDAR: Todas las funciones en C devuelven un valor, este puede ser void
	return;
}

//FORMA 3
void contarPalosCortosConSwitch (void)
{
	//Definimos nuestras variables a utilizar (Las variables las definimos en minuscula)
	int oro,espada,basto,copa,carta,cont;

	//Inicializamos las variables con un valor arbitrario
	oro = espada = basto = copa = cont = carta = 0;


	//Empezamos nuestro lazo repetitivo. 
	//Tomando como tope 14 (Ya que pregunto por MENOR a 15)
	// Esto se contaria como 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14
	while(cont < 15)
	{
		//Pedimos una carta
		printf("\nPor favor ingrese el tipo de carta que esta entrando. Recuerde: \nORO: 1\nESPADA: 2\nBASTO: 3\nCOPA: 4\nCOMODIN: Cualquier otro numero\n");
		scanf("%d",&carta);

		//Aumentamos el contador
		cont++;

		//Ahora preguntamos por cada caso posible de valor que pueda a llegar a tener nuestra variable "carta"
		//RECODAR: El condicional switch UNICAMENTE acepta valores ENTEROS
		switch(carta)
		{
			case ORO:
				oro++;
				break;
			case ESPADA:
				espada++;
				break;
			case COPA:
				copa++;
				break;
			case BASTO:
				basto++;
				break;
			//Este es el caso que se ejecuta cuando no se cumple ningun otro. En nuestro caso seria el comodin
			default:
				break;
		}
	}

	//Imprimimos todo nuestro trabajo
	printf("\nORO = %d,ESPADA = %d, COPA = %d, BASTO = %d, COMODINES = %d\n",oro,espada,copa,basto,cont - oro - espada - copa - basto);

	//Devuelvo void
	//RECORDAR: Todas las funciones en C devuelven un valor, este puede ser void
	return;
}