
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <time.h>

	int main(void) {

	/* inicio numero aleatorio */

	int eps;

	/* variavel auxiliar */

	int i;

	int n;

	printf("Entre com o numero de sorteios: ");
	scanf("%d",&n);

	srand(time(NULL));

	/* funcao geradora de numeros aleatorios inteiros: rand() */

	/* a funcao rand() gera inteiro entre 0 e a constante RAND_MAX */

	printf("RAND_MAX: %d\n\n",RAND_MAX);

	for ( i=0; i<n; i++ ) {

	eps = rand();

	if (eps<RAND_MAX/10)

	  { printf("\t (%d) eps=%5d menor que RAND_MAX/10\n\n", i, eps); }

	else if (eps<RAND_MAX/2)

	  { printf("\t (%d) eps=%5d menor que RAND_MAX/2\n\n", i, eps); }

	else
	
	  { printf("\t (%d) eps=%5d\n\n", i, eps); }

	}

	return 0;

	} /* fim */

       /* Uerj - 22 de novembro de 2022*/
