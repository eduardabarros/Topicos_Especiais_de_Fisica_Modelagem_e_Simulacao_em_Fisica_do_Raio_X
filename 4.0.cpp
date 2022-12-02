
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>

	int main(void)
	
	{
	
	// Declarando variáveis
	
    	unsigned dado = 10;
    	unsigned *dptr; // ponteiro unsigned dptr
    
   	 printf("\n");
   	 
   	 dptr = &dado;   // recupera o endereco da variavel dado
   	 
    	 printf("Conteudo apontado por dptr: %d\n",*dptr);
    	
   	 *dptr = 20;   // -> dado = 20;    modifica indiretamente a variavel dado
   	 
   	 printf("Conteudo de dado: %d\n",dado);
   	 
   	 printf("\n");
	
	}
	
	// Ponteiro: É uma variável que armazena endereços de memória
	
	// Uerj - 02 de dezembro de 2022
