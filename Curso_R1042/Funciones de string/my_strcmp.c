/**
 * \fn void my_strcat(char *t, const char *s);
 * \brief Compara las palabras introducidas por teclado.
 * \author Pose, Fernando Ezequiel.
 * \date 2010.06.10
 * \param Entrada de las dos palabras.
 * \return Retorna la comparación.
 */

int my_strcmp(const char *t,const char *s){
     
     int i;
     for(i=0; t[i] == s[i] && s[i]!=0 && t[i]!=0; i++);     
     
     if (t[i]==s[i]){	    
	    return(0);	    
     }     
     else{	    
	    if(t[i]<s[i]){		   
		   return(1);		   
	    }	   	 
	    else{
		   return (-1);		   
	    }	    
     }     
}