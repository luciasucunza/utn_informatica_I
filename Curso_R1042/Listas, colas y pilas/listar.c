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

