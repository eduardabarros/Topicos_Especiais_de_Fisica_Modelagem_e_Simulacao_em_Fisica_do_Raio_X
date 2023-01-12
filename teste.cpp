
	// Dados:
	
	// Delta_P	   P            N
	// 4.5	   	   14.5		2
	// 13.0	      	   23.0		3
	// 16.0	      	   26.0		4
	// 19.0	      	   29.0		5
	// 22.0	      	   32.0		6
	// 26.0	      	   36.0		7
	// 30.0	      	   40.0		8
	// 35.5	      	   45.5		9
	// 38.0	      	   48.0		10
	// 41.0	      	   51.0		11
	
	//--------------------------------------------------------------
	
	#include <iostream>
	#include <math.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	using namespace std;
	
	//--------------------------------------------------------------
	
	class dados
	
	{
	
	private: float P, Delta_P;
		 int N;
	
	// Interface para atribuicao de dados
		 
	public: void p       (float val) { P = val; }
		void delta_p (float val) { Delta_P = val; }
		void n       (int val)   { N = val; }
		
	// Interface para leitura de dados
	
	float p       (void) { return P; }
	float delta_p (void) { return Delta_P; }
	int n         (void) { return N; }
	
	friend
	Delta_P operator *(float d, Delta_P)
	{return Delta_P*d;}
	
	};
	
	//--------------------------------------------------------------
	
	int main ()
	
	{
	
	float n, m, Delta_P, P;
	float lambda_zero = 6.328e-5; // centimetro
	int d = 3; // centimetro
	int N, i, j;
	
	for (i=0; i<10; i++) {
	
	n = (((lambda_zero*N)/(2*Delta_P*d))*P) + 1;
	
	cout << endl << "\tn = " << n << endl;
	 
	}
	
	for (j=0; j<10; j++) {
	
	m = (2*d*(n-1))/(lambda_zero*P);
	
	cout << endl << "\tm = " << m << endl << endl;
	
	}
	
	return 0;
	
	}
	
	
