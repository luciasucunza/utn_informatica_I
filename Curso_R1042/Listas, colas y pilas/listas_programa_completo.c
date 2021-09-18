/**
 \ *file Programa completo de listas. Practica final 2012
 \brief Programa que contiene todas las funciones asociadas a listas.
 \author Pose, Fernando Ezequiel.
 \date 29/08/14
 \version 1.0.0
 \TODO En la próxima versión hay que agregar la parte de guardar la lista en un archivo y cargarla para no perderla cuando cierro programa.
 */

//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
	int valor;                     //Contenedor de dato de nodo lista.
	struct nodo *siguiente;        //Puntero a siguiente nodo.
}DATO;                               //Estructura nodo de lista.


//-------------
//-- Defines --
//-------------

#define PATH_DATOS "DATOS.txt"

//----------------
//-- Prototipos --
//----------------

void menu(void);
int agregar_final(DATO **lista);
int agregar_principio(DATO **lista);
int borrar_elemento(DATO **lista);
int cantidad_elementos(DATO *lista);
void listar(DATO *lista);
int salir(DATO **lista);
void buscar_max(DATO *lista);
void buscar_min(DATO *lista);
void ordenar_lista(DATO **lista);
int insertar_ordenado(DATO **listaordenada,int contenido);
int eliminar_primer_nodo(DATO **aux);
void BorrarPantalla(void);
void Pausa(void);
DATO* LeerArchivo(void);
void agregar_nodo(DATO** lista,DATO nodo);
void GuardarArchivo(DATO *lista);


/**
 * \fn int main(void)
 * \brief Función del control del programa integrador.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \return Retorna 0 si el programa finaliza bien.
 */

int main(void){

	printf("\n\t\tBienvenido al programa integrador de listas\r\n\n");
	Pausa();
	menu();
	BorrarPantalla();
	printf("\n\n\tGracias por utilizar el programa\r\n");
	Pausa();
	return(0);
}

/**
 * \fn void menu(void)
 * \brief Menu del programa
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 */

void menu(void){

	int exit;           //Controla la salida del menu.
	int opcion;    	  //Controla las opciones del switch.
	DATO *lista = NULL; //Puntero al comienzo de la lista.

	do{
		BorrarPantalla();
		printf("--------------------\n");
		printf("- Menu del sistema -\n");
		printf("--------------------\n");

		printf("\n\t1-  Agregar elemento al final de la lista.\n"
			 "\t2-  Agregar elemento al principio de la lista.\n"
			 "\t3-  Borrar elemento de la lista.\n"
			 "\t4-  Cantidad de elementos de la lista.\n"
			 "\t5-  Ordenar lista.\n"
			 "\t6-  Buscar minimo.\n"
			 "\t7-  Buscar maximo.\n"
			 "\t8-  Listar lista.\n"
			 "\t9-  Guardar lista (testeando).\n"
			 "\t10- Cargar lista (testeando).\n" //TODO falta enlace con main
			 //"\t11- Enviar por red (no implementada).\n"
			 "\t0- Salir del programa.\n\n");
		printf("Tarea desea realizar <opcion>: ");
		scanf("%d",&opcion);
		exit = 1;
		switch(opcion){
			case 1: agregar_final(&lista); break;
			case 2: agregar_principio(&lista); break;
			case 3: borrar_elemento(&lista); break;
			case 4: cantidad_elementos(lista); break;
			case 5: ordenar_lista(&lista); break;
			case 6: buscar_min(lista); break;
			case 7: buscar_max(lista); break;
			case 8: listar(lista); break;
            case 9: GuardarArchivo(lista); break;
            case 10:lista = LeerArchivo(); break;
			case 0: salir(&lista); exit = 0; break;
			default: ("Opcion incorrecta.\r\n"); break;
		}
		getchar();
	}while(exit != 0);
}

/**
 * \fn int agregar_final(DATO **lista)
 * \brief Inserta elemento al final de la lista
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \param **lista contiene la direccion de lista
 * \return 1 si salio bien, -1 si salio mal.
 */

int agregar_final(DATO **lista){ //Si existe la lista lo agrega al final, de lo contrario crea la lista con el dato.

    DATO *nuevo_elemento; //En esta estructura guardo mi nuevo dato.
    DATO *aux; 		       //Este puntero lo uso para recorrer la lista sin perder el inicio de la misma en el main.
    DATO *ant;            //Este lo uso para ir uno atras entonces cuando aux llega al null con este agrego el nuevo nodo.

nuevo_elemento = (DATO *) malloc (sizeof(DATO));
if(nuevo_elemento == NULL){
 printf("Error en memoria");
	return(-1);
}

printf("Introduzca el nuevo dato: ");
scanf("%d",&nuevo_elemento->valor);
nuevo_elemento->siguiente = NULL; //Mando siguiente a null (por el momento solo para rellenar la estructura)

if(*lista == NULL){               //Si no hay una lista todavia armada...

		*lista = nuevo_elemento;
		return(1);
}else{                            //Si hay lista creada lo agrego al final.
		aux = *lista;
		
		while(aux != NULL){
			ant = aux;
			aux = aux->siguiente;
		}
		ant->siguiente = nuevo_elemento;
		nuevo_elemento->siguiente = NULL;
}
getchar();
return(1);
}

/**
 * \fn int agregar_principio(DATO **lista)
 * \brief Inserta elemento al principio de la lista
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \param **lista contiene la direccion de lista
 * \return 1 si salio bien, -1 si salio mal.
 */

int agregar_principio(DATO **lista){
	
	DATO *nuevo_elemento; //En esta estructura guardo mi nuevo dato.
	
	nuevo_elemento = (DATO*) malloc (sizeof(DATO));
	if(nuevo_elemento == NULL){
		printf("Error en memoria");
		return(-1);
	}
	
	printf("Introduzca el nuevo dato: ");
	scanf("%d",&nuevo_elemento->valor);
	nuevo_elemento->siguiente = NULL; //Mando siguiente a null (por el momento solo para rellenar la estructura)

if(*lista == NULL){ //Si no hay una lista todavia armada...

		*lista = nuevo_elemento;
		return(1);
}else{  //Si hay lista creada.

		nuevo_elemento->siguiente = *lista;
		*lista = nuevo_elemento;
}
getchar();
return(1);
}

/**
 * \fn int borrar_elemento(DATO **lista)
 * \brief Borra un elemento de la lista
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \param **lista contiene la direccion de lista
 * \return 1 si salio bien, -1 si salio mal.
 */

int borrar_elemento(DATO **lista){
	
	int valor;
	DATO *aux, *ant;  //ant y aux son punteros al anterior nodo y al nodo posicionado.
	DATO *aux_borrar; //para no tener problemas con: *lista = lista->siguiente.
	
	if(*lista == NULL){
		printf("Lista vacia");
		return(-1);
	}
	
	printf("Ingrese el valor a borrar: ");
	scanf("%d",&valor);
	
	aux = *lista;                 //Me copio lista para no perder la direccion.
	aux_borrar = aux;
	if(aux->valor == valor){      //Si es el primer elemento de la lista.
		aux = aux->siguiente;
		free(aux_borrar);          //Libero el primer elemento.
      *lista = aux;
	}
	else{                                   //si no es el primer elemento..
		while((aux!=NULL)&&(aux->valor!=valor)){
			ant = aux;                  //Me guardo un puntero al bloque anterior por si lo tengo que borrar.
			aux = aux->siguiente;
		}
		if(aux == NULL){
			printf("No se encontro el elemento\r\n");
			return(1);
		}
		else{
			ant->siguiente = aux->siguiente;
			free(aux);
			printf("Nodo eliminado\r\n");
		}
	}
	getchar();
	return(1);
}

/**
 * \fn int cantidad_elementos(DATO *lista)
 * \brief Muestra la cantidad de nodos que tiene la lista
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \param *lista contiene lista.
 * \return contador cantidad de elementos
 */

int cantidad_elementos(DATO *lista){
	
	int contador=0; //contador donde guardo nodos contados.
	
	if(lista == NULL){
		printf("No hay elementos en la lista\r\n");
		return(0);
	}
	else{
		do{
			contador += 1;
			lista = lista->siguiente;
		}while(lista != NULL);
	}
	printf("La lista contiene: %d datos\n\r",contador);
	return(contador);
	getchar();
	getchar();
}

/**
 * \fn void listar(DATO *lista)
 * \brief Muestra el contenido de la lista.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \param *lista contiene lista.
 */

void listar(DATO *lista){
	
	if(lista == NULL){
		printf("No hay elementos en la lista\r\n");
	}
	else{
		do{
			printf("Dato: %d\r\n",lista->valor);
			lista = lista->siguiente;
		}while(lista != NULL);
	}
	getchar();
}

/**
 * \fn void salir(DATO **lista)
 * \brief Libera espacio de memoria.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \param **lista puntero a la lista.
 * \return 0 si vacia la memoria de forma correcta.
 */

int salir(DATO **lista){
	
	DATO *aux,*aux_liberar;
	
	aux = *lista;
	if(aux == NULL){
		return(0);
	}
	do{
		aux_liberar = aux;
		aux = aux->siguiente;
		free(aux_liberar);
	}while(aux!=NULL);
	
	return(0);
}


/**
 * \fn void buscar_max(DATO *lista)
 * \brief Busca el maximo elemento de la lista.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \param *lista lista de elementos.
 */

void buscar_max(DATO *lista){
	
	int aux; //contengo el valor maximo de la lista.
	
	if(lista!=NULL){
		aux = lista->valor;
		while(lista != NULL){
			if(lista->valor > aux)
				aux = lista->valor;
			lista = lista->siguiente;
		}
		printf("El maximo valor encontrado es: %d\r\n",aux);
	}
	else{
		printf("No existen elementos en la lista\r\n");
	}
	getchar();
}

/**
 * \fn void buscar_min(DATO *lista)
 * \brief Busca el minimo elemento de la lista.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \param *lista lista de elementos.
 */

void buscar_min(DATO *lista){
	
	int aux; //contengo el valor maximo de la lista.
	
	if(lista!=NULL){
		aux = lista->valor;
		while(lista != NULL){
			if(lista->valor < aux)
				aux = lista->valor;
			lista = lista->siguiente;
		}
		printf("El menor valor encontrado es: %d\r\n",aux);
	}
	else{
		printf("No existen elementos en la lista\r\n");
	}
	getchar();
}


/**
 * \fn void ordenar_lista(DATO **lista)
 * \brief Ordena la lista.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \param **lista lista de elementos.
 */

void ordenar_lista(DATO **lista){
	
	DATO *listaordenada = NULL; //aca guardo la lista como la voy ordenando.
	DATO *aux;           //Este es para recorrer la lista y no perder la referencia.
	int contenido;       //contiene el valor que saco de la lista para ubicar en la nueva ordenada.
	
	aux = *lista;
	while(aux!=NULL){
		contenido = eliminar_primer_nodo(&aux);
		insertar_ordenado(&listaordenada, contenido);
	}
	*lista = listaordenada;
	
}


/**
 * \fn int insertar_ordenado(DATO **listaordenada,int contenido)
 * \brief Inserta en una nueva lista el valor que voy recibiendo en los nodos.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \param **listaordenada puntero a la lista que esta ordenada
 * \param contenido contenido a guardar en el nodo de la lista ordenada
 * \return -1 si salio mal, 1 si salio bien.
 */

int insertar_ordenado(DATO **listaordenada,int contenido){
	
	DATO *nuevo_nodo = NULL;  //nodo para el nuevo dato.
	DATO *aux = NULL;         //para recorrer la lista sin perder la referencia de la lista.
	DATO *ant = NULL;         //para recorrer la lista y poder realizar el agregado de nodo.
	
	nuevo_nodo = (DATO *) malloc(sizeof(DATO));
	if(nuevo_nodo == NULL){
		printf("Error al pedir memoria");
		return(-1);
	}
	
	nuevo_nodo->valor = contenido;
	nuevo_nodo->siguiente = NULL;
	
	if(*listaordenada == NULL){  //Si todavia no ingrese ningun nodo..
		*listaordenada = nuevo_nodo;
		return(1);
	}
	else{  //Si ya habia ingresado nodos...
		aux = *listaordenada;
		
		while((aux != NULL)&&((aux->valor) < contenido)){  //mientras contenido no supere al valor del nodo actual.
			ant = aux;
			aux = aux->siguiente;     //apunto al siguiente nodo.
		}
		
		if(ant == NULL){                     //Si se mete al principio de la lista.
			nuevo_nodo->siguiente = *listaordenada;
			*listaordenada = nuevo_nodo;
		}
		
		else{                               //Si se mete en el medio de la lista.
			ant->siguiente = nuevo_nodo;
			nuevo_nodo->siguiente = aux;
		}
		return(1);
	}
}


/**
 * \fn int eliminar_primer_nodo(DATO **aux)
 * \brief Elimina el primer nodo de la lista a ordenar.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \param **aux direccion de memoria contenida por la direccin de lista.
 * \return contenido del primer nodo.
 */

int eliminar_primer_nodo(DATO **aux){
	
	DATO *cambio_posicion = NULL; //para no tener problemas con el asterisco de aux.
	DATO *temp = NULL;            //para el free.
	int contenido;                //contenido del nodo de lista.
	
	cambio_posicion = *aux;
	temp = *aux;
	contenido = cambio_posicion->valor;
	*aux = cambio_posicion->siguiente;
	free(temp);
	return(contenido);
}


/**
 * \fn void BorrarPantalla(void)
 * \brief Borra la pantalla
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 */

void BorrarPantalla(void){

	system("clear");
}


/**
 * \fn void BorrarPantalla(void)
 * \brief Borra la pantalla
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 */

void Pausa(void){

	//Comento esta línea de abajo y me ocupo de limpiar los Enters que sobren después de cada scanf
	//getchar();	//Por si me quedó algún Enter colgado

	printf("\n\nPresione una tecla para continuar...");
	getchar();
}


/**
 * \fn DATO* LeerArchivo(void)
 * \brief Lee la lista del archivo.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \return Devuelve un puntero a la lista.
 */

DATO* LeerArchivo(void){

	FILE *fp;            // Defino puntero al archivo.
	DATO nodo;           // Almacena los nodos que voy levantando del archivo.
	DATO *lista = NULL;  // Lista que contiene los nodos que levanto del archivo.

	fp = fopen(PATH_DATOS,"r");      //Abro el archivo en modo lectura.
	if(fp==NULL){              //Si no existe entonces no hay libros en la lista.
	    return NULL;
	}
	do {
		if (fread(&nodo,sizeof(DATO),1,fp))  //Si la lectura fue exitosa.
	    {
		    agregar_nodo(&lista,nodo);  //Agrego el nodo a la lista.
	    }
	} while(!feof(fp));     //Lo hago mientras me tire false(que lo niego) el fin del archivo.
	fclose(fp);             //Cierro archivo.
	return(lista);          //Devuelvo la posicion de la lista.
}


/**
 * \fn void agregar_nodo(DATO** lista,DATO nodo)
 * \brief Crea un nodo donde se agrega un nuevo elemento levantado del archivo.
 * \author Fernando Pose (fernandoepose@gmail.com)
 * \date 29/08/14
 * \param lista - Para moverme por la lista y agregar el nodo.
 * \param nodo - Elemento a agregar.
 */

void agregar_nodo(DATO** lista,DATO nodo){

	DATO *nuevo = NULL;
	DATO *aux = *lista;

	nuevo = (DATO *) malloc(sizeof(DATO)); //Creo nuevo nodo.
	nuevo->valor = nodo.valor;             //Cargo datos en nuevo nodo.
	if(*lista == NULL){                    //Si lista vacia entonces:
	    nuevo->siguiente = NULL;           //Apunto siguiente al NULL
	    *lista = nuevo;                    //Lo adjunto al principio de la lista.
	}
	else{ 		                           //De lo contrario.
	    while(aux->siguiente != NULL){
             aux = aux->siguiente;

       }
	    aux->siguiente = nuevo;
       nuevo->siguiente = NULL;
	}
}


/**
 * \fn int GuardarArchivo(void)
 * \brief Guarda la lista en el archivo.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/14
 * \param *lista lista de nodos a guardar en el archivo .
 */

void GuardarArchivo(DATO *lista){

	FILE *fp;
	DATO nodo;
	DATO *aux = lista;

	fp = fopen(PATH_DATOS,"w+");
	if(fp == NULL){
		printf("%s",strerror(errno));
	}
	if((lista == NULL)){                   //Si la lista esta vacia.
		puts("No hay datos a almacenar");
		fclose(fp);                          //Cierro el archivo
		return;
	}
	while(aux != NULL){                  //Mientras hay nodos
           
           fwrite(aux,sizeof(DATO),1,fp); //Guardo los nodos en el archivo.
		   aux = aux->siguiente;        //Paso al siguiente nodo
 	}
	fclose(fp);                            //Cierro el archivo.
}




