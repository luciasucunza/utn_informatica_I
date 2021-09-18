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
