
        #include<iostream>    // Define os objetos de fluxo (entrada e saída padrão)
        #include<stdio.h>     // Executa operações de entrada e saída 
        #include<string.h>    // Define várias funções para manipular strings e arrays
        #include<math.h>      // Declara um conjunto de funções para computar operações matemáticas comuns

        using namespace std;

	int main ()

	{

        // Declarando variáveis

	int a;
	float b,c;

	// Pedindo valores ao usuário

	cout << endl << "Digite um valor inteiro: ";
	cin >> a;

	cout << endl << "Digite um valor real: ";
	cin >> b;

	// Operação

	c = a + b;

	// Resultado

	cout << endl << "O resultado da soma dos números digitados é:  " << c << endl << endl;

	return 0;

	}

        // Variáveis:
	// Caracter: char (8 bits)
	// Inteiro: short int (16 bits), int (32 bits), long int (64 bits)
	// Real: float (32 bits), double (64 bits), long double (80 bits)
		
	// Uerj - 08 de novembro de 2022

        // Definições retiradas do site cplusplus e dos slides das aulas do professor Luis Fernando
