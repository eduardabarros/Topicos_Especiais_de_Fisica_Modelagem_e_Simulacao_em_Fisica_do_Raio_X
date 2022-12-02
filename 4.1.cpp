	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>

	int main(void)
	
	{
	
   	 unsigned dado = 10;
   	 unsigned *dptr; // ponteiro unsigned dptr
    
    	printf("\n");
    	
    	dptr = &dado;   // recupera o endereco da variavel dado
    	 
    	printf("Conteudo apontado por dptr: %d\n",*dptr);
    	
    	printf("Endereço da variável dado: %p\n",&dado);
    	
    	printf("Endereco apontado por dptr: %p\n",dptr); // endereço da variável dado
    	
    	printf("Endereco dptr: %p\n",&dptr);
    	
    	*dptr = 20;   // -> dado = 20;    modifica indiretamente a variavel dado 
    	
  	printf("Conteudo de dado: %d\n",dado);
  	  
   	printf("\n");
	
	}
	
	// Uerj - 02 de dezembro de 2022
