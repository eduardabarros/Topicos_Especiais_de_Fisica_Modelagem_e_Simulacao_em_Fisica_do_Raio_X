
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <time.h>

	int main (void) {

	float irand_max = 1.0/RAND_MAX;
	float *(*mat);  // ponteiro
	int i, j, k;    // contadores 
	int l, c;       // dimensoes de mat
	unsigned int m;
	

	srand(time(NULL));

	for ( i=0; i<10; i++ ) {
	printf ("Rodada %d\n",i);  // 1<=dim<=100
	l = 1+rand()%100;
	c = 1+rand()%100;

	printf("\tLinhas : %d\n",l);
	printf("\tColunas: %d\n",c);
	mat = (float**) new float*;
	printf("\tEndereco de mat:%p\n",mat);

	for ( j=0; j<l; j++ ) {
        mat [j] = (float*) new float [m];

	for ( k=0; k<c; k++ ) {
	mat[j][k] = rand()*irand_max; } }

	for ( j=0; j<l; j++ )
	delete [] mat [j];
	delete [] mat; }

	return 0;
 
	}

        // Uerj - 06 de dezembro de 2022
