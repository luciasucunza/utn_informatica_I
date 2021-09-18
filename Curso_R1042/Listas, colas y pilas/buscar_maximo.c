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
