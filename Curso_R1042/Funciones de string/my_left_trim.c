/**
 * \fn int void left_trim(char *palabra);
 * \brief Elimina el espacio al principio de la palabra.
 * \author Pose, Fernando Ezequiel.
 * \date 2010.06.11
 * \param Entrada de la palabra.
 * \return No retorna parametros.
 */

void left_trim(char *palabra){
     
     int i,j;
     
     for (i=0,j=0;*(palabra+i)!=0;i++){	    
	    if(*(palabra+i)!=' '){
		   
		   *(palabra+j) = *(palabra+i);
		   j++;
	    }
     }
     *(palabra+j) = 0;
}
