/**
 * \fn int void right_trim(char *palabra);
 * \brief Sobreescribe a la palaabra con espacios en blanco.
 * \author Pose, Fernando Ezequiel.
 * \date 2010.06.12
 * \param Entrada de la palabra.
 * \return No retorna parametros.
 */

void right_trim(char *palabra){
     
     int i,j,fin;
     
     fin = my_strlen (palabra);     
     for (i=fin,j=fin;palabra[i]<=fin;i--){	    
	    if(palabra[i]!=' '){		   
		   palabra[j]=palabra[i];
		   j--;
	    }
     }
     palabra[j]=0;
}

