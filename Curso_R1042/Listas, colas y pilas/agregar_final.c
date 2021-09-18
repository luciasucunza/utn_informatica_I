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
	DATO *aux; 		    //Este puntero lo uso para recorrer la lista sin perder el inicio de la misma en el main.
	DATO *ant;            //Este lo uso para ir uno atras entonces cuando aux llega al null con este agrego el nuevo nodo.
	
	nuevo_elemento = (DATO *) malloc (sizeof(DATO));
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
	}else{ //Si hay lista creada lo agrego al final.
		aux = *lista;
		
		while(aux!=NULL){  
			ant = aux;   
			aux = aux->siguiente;
		}
		ant->siguiente = nuevo_elemento;
		nuevo_elemento->siguiente = NULL;
	}
	getchar();
	return(1);
}

