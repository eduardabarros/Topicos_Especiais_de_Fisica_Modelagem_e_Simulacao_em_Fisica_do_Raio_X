
        #include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <time.h>

        using namespace std;

	int main()

	{

	float eps;	// numero aleatorio
	
	int i;		// variavel auxiliar

	int n;

	cout << endl << "Entre com o número de sorteios: ";
        cin >> n;
		
	srand(time(NULL));

	printf("RAND_MAX: %d \n",RAND_MAX);

	for ( i=0; i<n; i++ ) {
	  
	  eps = (float)rand()/RAND_MAX;

	  cout << i;
	  
	  if (eps<0.1) {
	    printf("\t eps = %5.3f menor que 0.1 \n",eps);    }

	  else if (eps<0.5) {
	    printf("\t eps = %5.3f menor que 0.5 \n",eps);    }

	  else {
	    printf("\t eps = %5.3f \n",eps);    }
	  
	}

	cout << "\n";

	return 0;

	}

	// Uerj - 25 de novembro de 2022
