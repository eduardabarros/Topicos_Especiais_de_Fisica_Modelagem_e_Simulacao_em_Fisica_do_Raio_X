
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

	int a, b, c;

	cout << endl << "Entre com o número de sorteios: ";
        cin >> n;
		
	srand(time(NULL));

	a = b = c = 0;		// 'c' receb o valor zero, 'b' copia o valor de 'c', e 'a' copia o valor de 'b'.

	for ( i=0; i<n; i++ ) {

	 eps = (float)rand()/RAND_MAX;

	  if (eps<0.1)

	    {a++;}

	  else if (eps<0.5)

	    {b++;}
	    
	  else

	    {c++;}
	  
	}

	printf("\t a = %f \n", a*1.0/n);
	printf("\t b = %f \n", b*1.0/n);
	printf("\t c = %f \n", c*1.0/n);

	cout << "\n";

	return 0;

	}

	// Uerj - 25 de novembro de 2022
