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

