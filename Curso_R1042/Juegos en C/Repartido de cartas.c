/* Escriba un programa qeu simule la mezcla de un mazo de cartas de poker
y su reparto completo a dos jugadores (medio mazo a cada uno). El reparto
se debe mostrar en la pantalla imprimiendo las 52 cartas en
dos columnas (una para cada jugador).
Estructura: (en el programa)

Sugerencia: El mazo de cartas de poker se puede simular como un arreglo
bidimensional de 13 filas por 4 columnas o viceversa.

Ayuda de funciones de biblioteca: rand() y srand() en stdio.h

Descripcion: La funcion rand() devuelve un entero pseudo-aleatorio entre 0
y RAND_MAX. La funcion srand() establece su argumento como la semilla de una
nueva serie de enteros pseudo-aleatorios que seran devueltos en secuencia
por rand(). Las secuencias son repetibles si se llama a srand() siempre
con el mismo valor de semilla.
La funcion rand() automaticamente asigna el valor de semilla 1 si no se
proporciona ningun valor de semilla a traves de srand(), es decir, si no se
llama a srand() previamente. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carta{
	const char *valor;
   const char *palo;
}CARTA;

void cargar(CARTA *mazo,char *palo[],char *valor[]);
void barajar(CARTA *mazo);
void repartir(CARTA *mazo);

int main(void){

	char *palo[4]={"Corazon","Diamante","Pica","Trebol"};
   char *valor[13]={"Uno","Dos","Tres","Cuatro","Cinco","Seis","Siete","Ocho","Nueve","Diez","Joto","Quina","Rey"};
   CARTA mazo[52];
   srand(time(NULL));
   cargar(mazo,palo,valor);
   barajar(mazo);
   repartir(mazo);
   getchar();
   return(1);
}


void cargar(CARTA *mazo,char *palo[],char *valor[]){
   	int i,j;
   int cont=0;
	for(i=0 ; i<4 ; i++){
   	for(j=0 ; j<13; j++){
      	(mazo+cont)->valor = *(valor+j);
         (mazo+cont)->palo  = *(palo+i);
         cont++;
      }
   }
}

void barajar(CARTA *mazo){
   int i;
   CARTA buffer;
   int r_rand;
   
	for(i=0;i<52;i++){
   	r_rand = rand()%51;
      //swapp
      buffer = mazo[i];
      mazo[i]= mazo[r_rand];
      mazo[r_rand] = buffer;
   }
}

void repartir(CARTA *mazo){

	int i,j;

	for(i = 0, j = 0; i < 52; j++, i+=2)
		printf("%d.\tJugador 1: %s %s\t\tJugador 2: %s %s\n",j,(mazo+i)->valor,(mazo+i)->palo,mazo[i+1].valor,(mazo+i+1)->palo);
}






