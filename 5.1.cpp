
	#include <iostream>
	#include <cstdlib>
	#include <cstdio>
	#include <cmath>
	#include <string>
	
	using namespace std;
	
	class XYZ {
	
	private: double x,y,z;
	
	public:	//construtores
		XYZ(void){x=y=z=0;}
		XYZ(double ix, double iy, double iz)
		{x=ix; y=iy; z=iz;}
		
		//destrutor
		~XYZ(void){}
		
		//métodos públicos
		void imprimir(void)
		{printf("%lf %lf %lf\n", x, y, z);}
		
		// somar um objeto XYZ
		XYZ operator +(XYZ v)
		{return XYZ(x+v.x, y+v.y, z+v.z);}
		
		// subtrair um objeto XYZ
		XYZ operator -(XYZ v)
		{return XYZ(x-v.x, y-v.y, z-v.z);}
	
		// trocar sinal
		XYZ operator -(void)
		{return XYZ(-x,-y,-z);}
		
		// produto vetorial
		XYZ operator ^(XYZ v)
		{return XYZ(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x);}
		
		// produto escalar
		double operator *(XYZ v)
		{return (x*v.x) + (y*v.y) + (z*v.z);}
		
		// produto por um escalar
		XYZ operator *(double f)
		{return XYZ(f*x, f*y, f*z);}

		// produto por um escalar
		friend // <------
		XYZ operator *(double f, XYZ v)
		{return XYZ(f*v.x, f*v.y, f*v.z);}

		// comprimento do vetor
		double comprimento(void)
		{return sqrt((x*x)+(y*y)+(z*z));}

		// vetor unitario
		XYZ unitario(void){
		double l=sqrt((x*x)+(y*y)+(z*z));
		return XYZ(x/l,y/l,z/l);}

		// acessos de escrita
		void X(double ix){x=ix;}
		void Y(double iy){y=iy;}
		void Z(double iz){z=iz;}

		// acessos de leitura
		double X(void){return x;}
		double Y(void){return y;}
		double Z(void){return z;}

		};

		int main(void)
		
		{
		
		XYZ p1(2,0,-3), p2(1,2,3), p3;
		
		double d;
		
		cout << endl << endl;

		//imprimir p1 e p2
		printf("\tp1: "); p1.imprimir();
		
		cout << endl;
		
		printf("\tp2: "); p2.imprimir();
		
		cout << endl;

		// soma
		p3 = p1+p2;
		printf("\tp3 = p1 + p2: "); p3.imprimir();
		
		cout << endl;

		// subtracao
		p3 = p2-p1;
		printf("\tp3 = p2 - p1: "); p3.imprimir();
		
		cout << endl;

		//produto escalar
		d = p3*p2;
		printf("\td = p3*p2: %lf\n",d);
		
		cout << endl;

		//produto por um escalar
		p3 = p2*3.4;
		printf("\tp3 = p2*3.4: "); p3.imprimir();
		
		cout << endl;

		//produto por um escalar
		p1 = 0.3*p1;
		printf("\tp1 = 0.3*p1: "); p1.imprimir();
		
		cout << endl;

		//produto vetorial
		p3 = p1^p2;
		printf("\tp3 = p1^p2: "); p3.imprimir();
		
		cout << endl;

		//norma de p2
		d = p3.comprimento();
		printf("\td = p3.comprimento(): %lf\n",d);
		
		cout << endl;

		//vetor unitario de p3
		p1 = p3.unitario();
		printf("\tp1 = p3.unitario(): ");
		p1.imprimir();
		
		cout << endl;

		//complemento de p1
		p3 = -p1;
		printf("\tp3 = -p1: "); p3.imprimir();
		
		cout << endl << endl;
		
		return 0;
		
		}
