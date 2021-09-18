/**
 * \fn int borrar_elemento(DATO **lista)
 * \brief Borra un elemento de la lista
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 29/08/12
 * \param **lista contiene la direccion de lista
 * \return 1 si salio bien, -1 si salio mal.
 */

int borrar_elemento(DATO **lista){
	
	int valor;
	DATO *aux, *ant; //ant y aux son punteros al anterior nodo y al nodo posicionado.
	DATO *aux_borrar; //para no tener problemas con: *lista = lista->siguiente.
	
	if(*lista == NULL){
		printf("Lista vacia");
		return(-1);
	}
	
	printf("Ingrese el valor a borrar: ");
	scanf("%d",&valor);
	
	aux = *lista;                           //Me copio lista para no perder la direccion.
	aux_borrar = aux;
	if(aux->valor == valor){                //Si es el primer elemento de la lista.
		aux = aux->siguiente;
		free(aux_borrar);                 //Libero el primer elemento.
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
