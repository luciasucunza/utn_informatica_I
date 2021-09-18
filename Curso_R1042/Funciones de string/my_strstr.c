/**
 *	\fn bool my_strstr(char *big, char *sub);
 *	\brief Compara el conjunto y el posible subconjunto.
 *	\author Pose, Fernando Ezequiel.
 *	\date 2010.06.12
 *	\param Entradas de s1 y s2.
 *	\return Retorna un valor segun su condicion de verdad.
 */

bool my_strstr(char *big, char *sub){
     
     int i,j;
     int ret=0;
     
     for (i=0,j=0;big[i]!=0 && sub[j]!=0;i++){                            	    
	    if(big[i] == sub[j]){		   
		   ret = true;
		   j++;
	    }
	    else{
		   j = 0;
		   ret = false;
	    }
     }
     return (ret);
}



