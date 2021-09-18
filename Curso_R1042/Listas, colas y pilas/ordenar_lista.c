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
 * \date 8/04/12
 * \param **listaordenada puntero a la lista que esta ordenada
 * \param contenido contenido a guardar en el nodo de la lista ordenada
 * \return -1 si salio mal, 1 si salio bien.
 * \TODO Rompe en: ant->siguiente = nuevo_nodo;
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
 * \date 8/04/12
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

