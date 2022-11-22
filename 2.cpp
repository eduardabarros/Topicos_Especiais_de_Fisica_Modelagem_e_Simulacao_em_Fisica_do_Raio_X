
	#include <iostream>
        #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <time.h>

	// Os includes ajudam o compilador a checar se as instruções estão escritas corretamente

        using namespace std;

	int main()

	{

	// Declaração de variáveis

	int eps;	// variável que guarda o número aleatório que a função rand irá gerar

	int i;		// variável auxiliar

	// Início da instrução do programa

	srand(time(NULL));	// srand: recebe um número inteiro sem sinal
				// time: argumento da função srand que representa um tempo em segundos (um número inteiro)
				// NULL: faz o papel de ponteiro nulo (nenhum endereço em especial)
	                        // a funcao rand() gera um número inteiro aleatório entre 0 e a constante RAND_MAX
                        	// RAND_MAX: Representa no mínimo metade do maior número que um short int pode representar (2 bytes)
	
	// Condição para execução do programa
	
	for ( i=0; i<10; i++ )  // for é dividida em três partes:
			        // inicialização da variável de controle;
				// teste da variável que esta no controle, se verdadeiro executa o bloco e depois vai para pŕoxima etapa;
				// atualização da variável de controle, encremento ( i=0, i=1, i=2, ..., i=9)
				// fica no loop até i=10, o teste de continuídade vai dar falso e para a execução do programa

	{

	eps = rand();		// eps = (0, RAND_MAX)

	if (eps < RAND_MAX/10) {

	  cout << endl << eps << " menor que " << RAND_MAX/10 << endl << endl;

	}
	
	else if (eps < RAND_MAX/2) {

	  cout << endl << eps << " menor que " << RAND_MAX/2 << endl << endl;

	}

	else {

	  cout << endl << eps << " = " << eps << endl << endl;

	}

	}

	return 0;
	
	}

	// srand pega a semente do código (neste caso a hora do computador) e faz um sorteio dos valores que serão impressos na tela

        // Uerj - 22 de novembro de 2022
