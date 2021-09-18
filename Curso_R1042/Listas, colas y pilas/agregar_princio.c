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
