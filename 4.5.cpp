
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <time.h>

	int main(void) {
	  
	   float irand_max = 1.0/RAND_MAX;
	   float *lista; // ponteiro
	   int i, j; // contadores
	   int dim; // dimensao de lista

	   srand(time(NULL));

	   for ( i=0; i<10; i++ ) {
	     
	      printf ("Rodada %d\n",i);
	      dim = 1+rand()%100; // 1<=dim<=100
	      printf("\tComprimento sorteado: %d\n",dim);
	      lista = (float*)malloc(dim*sizeof(float));  // em cpp: lista = (float*) new float[dim];

	      printf("\tEndereco de lista:%p\n",lista);
	      for ( j=0; j<dim; j++ ) {
	         lista[j] = rand()*irand_max;
	         printf("\t%7.4f",lista[j]);
	      }
	      printf("\n");
	      free(lista);  // delete [] ptr;
	   }
	   return 0;
	}

       // Na declaração se coloca: double *ptr; // esta sendo declarado que ptr é um ponteiro
       // Em cpp ao invés de calloc ou malloc, usa-se: ptr = new tipo[n]; new + natureza dos dados + número de memória que preciso alocar
       // Em cpp para liberar a memória da alocação que foi solicitada: ptr = (   ) new tipo[]; delete [] ptr;

	
	// Uerj - 06 de dezembro de 2022
