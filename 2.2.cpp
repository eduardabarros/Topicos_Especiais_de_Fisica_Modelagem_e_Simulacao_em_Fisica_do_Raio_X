
	
	#include <iostream>
        #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <time.h>

        using namespace std;

	int main()

	{

	// Declaração de variáveis

	int eps;	

	int i;		

	// Início da instrução do programa

	srand(time(NULL));	
	
	// Condição para execução do programa
	
	for ( i=0; i<10; i++ )  

	{
	  
	eps = rand();		

	if (eps < RAND_MAX/10) {

	  cout << endl << i << "\t" << eps << " menor que " << RAND_MAX/10 << endl << endl;

	}
	
	else if (eps < RAND_MAX/2) {

	  cout << endl << i << "\t" <<  eps << " menor que " << RAND_MAX/2 << endl << endl;

	}

	else {

	  cout << endl << i << "\t" <<  eps << " = " << eps << endl << endl;

	}

	}

	return 0;
	
	}

        // Uerj - 22 de novembro de 2022

