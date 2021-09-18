/**
 *	\file Lista_Doble_Enlazada.c
 *	\brief Programa de funciones aplicadas a lista doble enlazada.
 *	\author Pose, Fernando (fernandoepose@gmail.com)
 *	\date 5/09/14
 */

/************************
        Includes
************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************
         Defines
************************/

#define MAX_CARACTERES 20
#define SALIR 0
#define OK 1
#define ERROR -1


/************************
      Estructura
************************/

typedef struct nodo{
	char elemento[MAX_CARACTERES];
   struct nodo *siguiente;
   struct nodo *anterior;
}NODO;


/************************
        Prototipos
************************/

int menu(void);
int agregar_principio(NODO **lista);
char *gets_s(char *s, int size);
void listar(NODO *lista);
int agregar_final(NODO **lista);
int cant_elementos(NODO *lista);
int borrar_primer_elemento(NODO **lista);
int borrar_ultimo_elemento(NODO **lista);
void elimiar_lista(NODO **lista);
void salir(NODO **lista);
int guardar_lista(NODO *lista);
NODO * cargar_lista(void);
int guardar_dato_archivo(NODO **lista,NODO dato_nuevo);
int borrar_elemento(NODO **lista);
int ordenar_lista(NODO **lista);
void quitar_elemento(NODO **aux,char *elemento);
int agregar_ordenado(NODO **lista_ordenada,char *elemento);


/**
 * \fn int main(void)
 * \brief Función principal del programa
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 */

int main(void){

   NODO *lista = NULL;
   int opcion;
   int cantidad;

	printf("-------------------------\n");
   printf("- Bienvenido al sistema -\n");
   printf("-------------------------\n");

   do{
   	opcion = menu();
      switch(opcion){
   		case 1: agregar_principio(&lista); break;
      	case 2: agregar_final(&lista); break;
      	case 3: borrar_primer_elemento(&lista); break;
      	case 4: borrar_ultimo_elemento(&lista); break;
         case 5: borrar_elemento(&lista); break;
      	case 6: cantidad = cant_elementos(lista); break;
      	case 7: ordenar_lista(&lista); break;
      	case 8: listar(lista); break;
      	case 9: elimiar_lista(&lista);break;
      	case 10: guardar_lista(lista); break;
      	case 11: lista = cargar_lista(); break;
      	case 0: salir(&lista);break;
      default: printf("Opcion incorrecta");break;
   	}
   }while(opcion!=SALIR);
   puts("Fin del programa");
   getchar();
   getchar();
   return(1);
}

/**
 * \fn int menu(void)
 * \brief Función menu del sistema
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \return opcion - Función a realizar
 */

int menu(void){

	int opcion;

	printf("--------------------\n");
	printf("- Menu del sistema -\n");
	printf("--------------------\n");

   printf("\n\t1-  Agregar elemento al principio de la lista.\n"
			 "\t2-  Agregar elemento al final de la lista.\n"
			 "\t3-  Borrar primer elemento de la lista.\n"
          "\t4-  Borrar ultimo elemento de la lista.\n"
          "\t5-  Borrar un elemento determinado de la lista.\n"
			 "\t6-  Cantidad de elementos de la lista.\n"
			 "\t7-  Ordenar lista.\n"
			 "\t8-  Listar lista.\n"
          "\t9- eliminar lista.\n"
			 "\t10- Guardar lista (testeando).\n"
			 "\t11- Cargar lista (testeando).\n"
			 "\t0-  Salir del programa.\n\n");
	scanf("%d",&opcion);
	return(opcion);
}

/**
 * \fn int agregar_principio(NODO **lista)
 * \brief Inserta elemento al principio de la lista
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param **lista contiene la direccion de lista
 * \return Ok si todo salio bien, Error si todo salio mal :)
 */

int agregar_principio(NODO **lista){

	NODO *nuevo_dato = NULL;
   char nombre_aux[MAX_CARACTERES];
   NODO *aux = NULL; //Para no tener problemas con el doble puntero en struct.

   aux = *lista;

	//Cargo y seteo los valores del nuevo elemento en la lista.
   nuevo_dato = (NODO*) malloc(sizeof(NODO));
   if(nuevo_dato == NULL){
   	printf("Error en el pedido de memoria");
      return(ERROR);
   }
   getchar();
   printf("Ingrese el nombre del elemento a guardar: ");
   gets_s(nombre_aux,MAX_CARACTERES);
   strcpy(nuevo_dato->elemento,nombre_aux);
   nuevo_dato->siguiente = NULL;
   nuevo_dato->anterior = NULL;

	/***************************************************************/

   if(*lista == NULL){ //Primer elemento de la lista..
   	*lista = nuevo_dato;
   }
   else{ //si ya había elementos cargados..
   	nuevo_dato->siguiente = aux;
      nuevo_dato->anterior = aux->anterior;
      aux->anterior = nuevo_dato;
      aux = nuevo_dato;
      *lista = aux;
	}
   return(OK); //Todo salio bien.
}

/**
 * \fn int agregar_final(NODO **lista)
 * \brief Inserta elemento al final de la lista
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param **lista contiene la direccion de lista
 * \return Ok si todo salio bien, Error si todo salio mal :)
 */

int agregar_final(NODO **lista){

	NODO *nuevo_dato = NULL;
   char nombre_aux[MAX_CARACTERES];
   NODO *aux = NULL; //Para no tener problemas con el doble puntero en struct.

   aux = *lista;

	//Cargo y seteo los valores del nuevo elemento en la lista.
   nuevo_dato = (NODO*) malloc(sizeof(NODO));
   if(nuevo_dato == NULL){
   	printf("Error en el pedido de memoria");
      return(ERROR);
   }
   getchar();
   printf("Ingrese el nombre del elemento a guardar: ");
   gets_s(nombre_aux,MAX_CARACTERES);
   strcpy(nuevo_dato->elemento,nombre_aux);
   nuevo_dato->siguiente = NULL;
   nuevo_dato->anterior = NULL;

	/***************************************************************/

   if(*lista == NULL){ //unico elemento..
   	*lista = nuevo_dato;
   }
   else{ //Si no es el unico elemento
   	while(aux->siguiente != NULL){
      	aux = aux->siguiente;
      }
      nuevo_dato->siguiente = aux->siguiente;
      nuevo_dato->anterior = aux;
      aux->siguiente=nuevo_dato;
   }
   return(OK);
}

/**
 * \fn void listar(NODO *lista)
 * \brief Lista los elementos cargados en la lista.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param *lista es la dirección  del primer elemento de la lista.
 */

void listar(NODO *lista){

	if(lista == NULL){
   	printf("No hay elementos cargados en la lista aun\n");
   }
   else{ //Si hay elementos cargados en la lista:
   	do{
   		printf("Elemento: %s\n",lista->elemento);
      	lista = lista->siguiente;
   	}while(lista!=NULL);
   }
}

/**
 * \fn int cant_elementos(NODO *lista)
 * \brief Informa la cantidad de elementos existente en la lista.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param *Dirección al primer elemento de la lista.
 * \return cantidad - Cantidad de elementos en la lista.
 */

int cant_elementos(NODO *lista){

	int cantidad=0;

	if(lista == NULL){
   	puts("No hay elementos en la lista");
      return(ERROR);
   }
   else{
   	while(lista!=NULL){
      	cantidad ++;
         lista = lista->siguiente;
      }
      printf("Cantidad de datos en la lista: %d\n",cantidad);
      return(cantidad);
   }
}


/**
 * \fn int borrar_primer_elemento(NODO **lista)
 * \brief Borra el primer elemento de la lista.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param **lista contiene la direccion del puntero lista
 * \return Ok - Si todo salio bien. Error - En caso de falla.
 */

int borrar_primer_elemento(NODO **lista){

	NODO *buffer = NULL; //guardo el que voy a borrar
   NODO *aux = NULL; //Para no tener problemas con el doble puntero en estructuras

	if(*lista == NULL){  //Si no hay elementos en la lista, no tiene para borrar
   	puts("No hay elementos en la lista!\n");
      return(ERROR);
   }
   aux = *lista;
   if(aux->siguiente == NULL){ //Unico elemento en la lista.
      *lista = NULL;
		free(aux);
      return(OK);
   }
   else{ //Mas de un elemento a borrar.
		buffer = *lista; //lo guardo para el free.
      aux = *lista;
      aux = aux->siguiente;
      aux->anterior = buffer->anterior; // (NULL)
      free(buffer);
      *lista = aux;
      return(OK);
   }
}

/**
 * \fn int borrar_ultimo_elemento(NODO **lista)
 * \brief Borra el ultimo elemento de la lista
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param **lista contiene la direccion del puntero lista.
 * \return Ok - Si todo salio bien.
 */

int borrar_ultimo_elemento(NODO **lista){

   NODO *aux = NULL; //Para no perder la referencia.
   NODO *buffer = NULL; //Aca almaceno el nodo a liberar.

	if(*lista == NULL){
   	puts("La lista esta vacia");
      return(OK);
   }
   aux = *lista;
   while(aux->siguiente!=NULL){
		aux = aux->siguiente;
	}
   buffer = aux;
   aux->anterior->siguiente = aux->siguiente; //(NULL)
   free (buffer);
}

/**
 * \fn  void eliminar_lista(NODO **lista)
 * \brief Elimina la lista.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param **lista contiene la direccion del puntero lista
 */

void elimiar_lista(NODO **lista){

	NODO *aux = NULL; //Para recorrer la lista.
   NODO *buffer = NULL; //El que uso para borrar cada elemento.

	if(*lista == NULL){ //Si no hay elementos en la lista no hay que borrar.
		puts("No hay elementos cargados en la lista");
   }
   else{ //Si hay elementos, los elimino uno a uno :)
      aux = *lista;
      while(aux != NULL){
      	buffer = aux;
         aux = aux->siguiente;
         free(buffer);
      }
      *lista = NULL;
   }
}

/**
 * \fn void salir(NODO **lista)
 * \brief  Salir de lista elimina la lista.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param **lista contiene la direccion del puntero lista
 */

void salir(NODO **lista){

	NODO *aux = NULL; //Para recorrer la lista.
   NODO *buffer = NULL; //El que uso para borrar cada elemento.

	if(*lista == NULL){ //Si no hay elementos en la lista no hay que borrar.
		puts("No hay elementos cargados en la lista");
   }
   else{ //Si hay elementos, los elimino uno a uno :)
      aux = *lista;
      while(aux != NULL){
      	buffer = aux;
         aux = aux->siguiente;
         free(buffer);
      }
      *lista = NULL;
   }
}


/**
 * \fn int guardar_lista(NODO *lista)
 * \brief Guarda la lista en un archivo
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param **lista contiene la direccion de lista
 * \return Ok - Si todo salio bien. Error si falla al abrir el archivo.
 */

int guardar_lista(NODO *lista){

	FILE *fp;
   NODO *aux = NULL;

   fp = fopen("Lista_Doble.txt","a+");
   if(fp == NULL){
   	puts("Error al abrir el archivo");
      return(ERROR);
   }
   while(lista!=NULL){
   	fwrite(lista,sizeof(NODO),1,fp);
      lista = lista->siguiente;
   }
   fclose(fp);
   return(OK);
}


/**
 * \fn NODO *cargar_lista(void)
 * \brief Carga dato de un archivo en una estructura y luego lo guarda en la lista y retorna la misma.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \return Dirección de lista si todo salio bien. Error si no se pudo abrir el archivo.
 */

NODO * cargar_lista(void){

	NODO* lista = NULL;
   NODO dato_nuevo; //Aca guardo el nodo que recibo desde el archivo.
   FILE *fp;

   fp = fopen("Lista_Doble.txt","a+");
   if(fp == NULL){
   	puts("Error al abrir el archivo");
      return(ERROR);
   }
   while(!feof(fp)){
   	fread(&dato_nuevo,sizeof(NODO),1,fp);
      guardar_dato_archivo(&lista,dato_nuevo);
   }
   fclose(fp);
   return(lista);
}

/**
 * \fn int guardar_dato_archivo(NODO **lista, NODO dato_nuevo)
 * \brief guarda la estructura donde tengo mi dato de archivo en la lista.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param **lista contiene la direccion del  puntero lista
 *\param NODO dato_nuevo - Nodo a ingresar a la lista.
 * \return Ok - si todo salio bien. Error si falla el programa al pedir memoria.
 */

int guardar_dato_archivo(NODO **lista,NODO dato_nuevo){

	NODO *nuevo_dato = NULL;
   NODO *aux = NULL;

	nuevo_dato = (NODO*) malloc(sizeof(NODO));
   if(nuevo_dato == NULL){
   	puts("Error al pedir memoria");
      return(ERROR);
   }

   nuevo_dato->siguiente = NULL;
   nuevo_dato->anterior = NULL;
   strcpy(nuevo_dato,dato_nuevo.elemento);

   /********************************************/

	if(*lista == NULL){ //Todavía no cargue ningun nodo..
   	*lista = nuevo_dato;
      return(OK);
   }
   else{
   	aux = *lista;
      nuevo_dato->siguiente = aux;
      nuevo_dato->anterior = aux->anterior; //(NULL)
      aux->anterior = nuevo_dato;
      aux = nuevo_dato;
      *lista = aux;
      return(OK);
   }
}

/**
 * \fn int borrar_elemento(NODO **lista)
 * \brief Elimina un elemento a elección de la lista
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param **lista contiene la direccion del puntero lista
 * \return Ok - Si se elimino el elemento elegido. Error si no se encuentra el dato buscado
 */

int borrar_elemento(NODO **lista){

	NODO dato_borrar;
   NODO* aux = NULL;
   NODO* buffer = NULL; //Este lo uso como buffer del elemento a eliminar.
   getchar();
   puts("Ingrese el dato a borrar: ");
   gets_s(dato_borrar.elemento,MAX_CARACTERES);

   if(*lista == NULL){
   	puts("La lista esta vacia senor");
      return(OK);
   }
   /* Empiezo la comparacion */
   aux = *lista;
   while((aux!=NULL)&&(strcmp(aux->elemento,dato_borrar.elemento)!=0)){
   	aux = aux->siguiente;
   }
   if(aux == NULL){
   	puts("No se encontro el dato buscado");
      return(ERROR);
   }
   if((aux->siguiente == NULL)&&(aux->anterior==NULL)){ //Si hay un solo elem.
		free(aux);
      *lista = NULL;
      return(OK);
   }
   if(aux->anterior == NULL){ //primer elemento de la lista..
      buffer = aux;
   	aux->siguiente->anterior = aux->anterior; // (NULL)
      aux = aux->siguiente;
      *lista = aux;
      free(buffer);
      return(OK);
   }
   if(aux->siguiente == NULL){ //Si es el ultimo..
   	buffer = aux;
   	aux->anterior->siguiente = aux->siguiente;
      free(buffer);
      return(OK);
   }

   //Si es un bloque que este por el medio..
   buffer = aux; //Es el que tengo que eliminar.
   aux->anterior->siguiente = aux->siguiente;
   aux->siguiente->anterior = aux->anterior;
   free(buffer);  //Tambien se puede borrar aux....
   return(OK);
}

/**
 * \fn char* gets_s(char *s, int size)
 * \brief Función para leer un string por  entrada de teclado
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param s - Buffer donde se guarda el string ingresado por stdin
*\param size - Tamaño del string a ingresar por stdin
 * \return s - String cargado por stdin
 */

char *gets_s(char *s, int size){
     int len;

     if (!fgets(s, size, stdin)){
	    if (size > 0)
		   s[0] = '\0';
	    return NULL;
     }
     else{
	    len = strlen(s);
	    if (len && s[len-1] == '\n')
		   s[len-1] = '\0';
	    return s;
     }
}


/**
 * \fn int ordenar_lista(NODO **lista)
 * \brief Función principal para ordenar la lista.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param **lista contiene la direccion del puntero lista
 * \return  Ok - Si se ordeno la lista. Error - Si no hay elementos en la lista.
 */

int ordenar_lista(NODO **lista){

	NODO *aux = NULL;
   NODO *lista_ordenada = NULL; //Aca voy guardando la nueva lista ordenada.
   char  dato_retirado[MAX_CARACTERES];

	if(*lista == NULL){
   	puts("No hay elementos en la lista");
      return(ERROR);
   }
	aux = *lista;
   while(aux!=NULL){
   	quitar_elemento(&aux,dato_retirado);
   	agregar_ordenado(&lista_ordenada,dato_retirado);
   }
   *lista = lista_ordenada;
   return(OK);
}

/**
 * \fn void quitar_elemento(NODO **aux, char *elemento)
 * \brief Quita un elemento de la lista que estoy ordenando.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param **aux contiene la direccion del puntero de aux
 *\param *elemento - Es donde se va a almacenar el elemento eliminado de la llista.
 */

void quitar_elemento(NODO **aux,char *elemento){

	NODO *siguiente_dato = NULL; //Para no tener problemas en el avance de list.
   NODO *buffer = NULL;         //Nodo a eliminar de la lista.

   siguiente_dato = *aux;
	buffer = *aux;

	strcpy(elemento,buffer->elemento);
	*aux = siguiente_dato->siguiente;
   free(buffer);
}


/**
 * \fn int agregar_ordenado(DATO **lista_ordenada, char* elemento)
 * \brief Inserta un elemento en una lista ordenada por orden alfabético
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 5/09/14
 * \param **lista_ordenada - Contiene la dirección del puntero lista_ordenada. elemento - Contiene el elemento a ingresar a la lista.
 * \return Ok - Si ingreso a la lista. Error - Si falla al pedir memoria.
 */

int agregar_ordenado(NODO **lista_ordenada,char *elemento){

	NODO *aux = NULL;
   NODO *ant = NULL;
   NODO *nuevo_dato = NULL;

   nuevo_dato = (NODO*) malloc(sizeof(NODO));
   if(nuevo_dato == NULL){
   	puts("Error al pedir memoria");
      return(ERROR);
   }
   strcpy(nuevo_dato->elemento,elemento);
   nuevo_dato->siguiente = NULL;
   nuevo_dato->anterior  = NULL;

   /* Hasta aca solo cargue la estructura dato (nodo) de la lista */

   if(*lista_ordenada == NULL){ //Si la lista esta vacia.
   	*lista_ordenada = nuevo_dato;
   	return(OK);
   }//De lo contrario agrego el nodo ordenado.

   aux = *lista_ordenada;

   while((aux != NULL)&&(strcmp(aux->elemento,elemento)<0)){
   	ant = aux;
   	aux = aux->siguiente;
   }
   if(ant == NULL){//un solo elemento.
   	nuevo_dato->siguiente = aux;
      nuevo_dato->anterior = aux->anterior;
      aux->anterior = nuevo_dato;
      *lista_ordenada = nuevo_dato;
      return(OK);
   }

   if(aux == NULL){ //Ultimo elemento de la lista.
   	ant->siguiente = nuevo_dato;
      nuevo_dato->anterior = ant;
      nuevo_dato->siguiente = aux;
      return(OK);
   }
   //Si no es porque esta en el medio!

   nuevo_dato->siguiente = aux;
   aux->anterior = nuevo_dato;
   nuevo_dato->anterior = ant;
   ant->siguiente = nuevo_dato;
   return(OK);
}