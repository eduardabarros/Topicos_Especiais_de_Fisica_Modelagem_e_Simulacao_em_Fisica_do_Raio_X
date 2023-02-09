	
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <stdio.h>
	#include <time.h>

	class XYZ {
	
	protected: double x, y, z;

	public:
		   XYZ(void) { x = y = z = 0; } // construtor XYZ()
		   XYZ(double ix, double iy, double iz) { // construtor XYZ(x,y,z)
		      x = ix; y = iy; z = iz;
		   }
		   XYZ operator +(XYZ v) { // soma vetorial
		      return XYZ( x+v.x, y+v.y, z+v.z );
		   }
		   XYZ operator -(XYZ v) { // subtracao vetorial
		      return XYZ( x-v.x, y-v.y, z-v.z );
		   }
		   XYZ operator -(void) { // negativo
		      return XYZ( -x, -y, -z );
		   }
		   double operator *(XYZ v) { // produto escalar
		      return x*v.x + y*v.y + z*v.z;
		   }
		   XYZ operator *(double d) { // escala: XYZ*double
		      return XYZ(x*d, y*d, z*d);
		   }
		   friend XYZ operator *(double d,XYZ v) { // escala: double*XYZ
		      return v*d;
		   }
		   XYZ operator /(double d) { // escala
		      return XYZ(x/d, y/d, z/d);
		   }
		   XYZ operator ^(XYZ v) { // produto vetorial
		      return XYZ(y*v.z-v.y*z, z*v.x-v.z*x, x*v.y-v.x*y);
		   }
		   double Norma(void) {
		      return sqrt((*this)*(*this));
		   }
		   XYZ Unitario(void) {
		      double d = Norma();
		      return (*this)/d;
		   }
		   XYZ Rotacao(double ang, XYZ n) {
		      XYZ r(x,y,z);
		      XYZ v, res;
		      double s;
		      // usando quaternions
		      s = cos(0.5*ang);
		      v = n.Unitario()*sin(0.5*ang);
		      res = (r*(s*s)) - (r*(v*v)) + (v*(2*(v*r))) + ((v*(2*s))^r);
		      // versao usando *this
		      //res = ((*this)*(s*s)) - ((*this)*(v*v)) + (v*(2*(v*(*this)))) + ((v*(2*s))^(*this));
		      return res; 
		   }
		   void Imprimir(void) {
		      printf("( %lf, %lf, %lf )\n",x, y, z);
		   }
		};

	class foton {
	
	private:   double hv;    // energia
	  	   XYZ    p, d;  // posicao e direcao

	public:
		   foton(void)                     { hv=0;                   }
		   foton(double e, XYZ ip, XYZ id) { hv = e; p = ip; d = id; }
		   // atribuir valores
		   void Hv(double e) { hv = e; } // atribuir energia ao foton
		   void Pos(XYZ ip)  { p = ip; } // atribuir posicao ao foton
		   void Dir(XYZ id)  { d = id; } // atribuir direcao ao foton
		   // retornar valores
		   double Hv(void)  { return hv; } // retorna energia do foton
		   XYZ    Pos(void) { return p;  } // retorna posicao do foton
		   XYZ    Dir(void) { return d;  } // retorna direcao do foton
		   // translacao
		   void Translacao(XYZ dist) { p = p + dist; }
		   // rotacao
		   void Rotacao(double ang, XYZ n) { d = d.Rotacao(ang,n); }
		   void Imprimir(void) {
		      printf("hv = %lf\n",hv);
		      printf("p = "); p.Imprimir();
		      printf("d = "); d.Imprimir();
		      printf("\n");
		   }
		};

	typedef struct { double pabs, pee, pei, s; } Info;

	class subnivel {
	
	private:
	
		   char   simb[6];
		   double Eb, rs;
		   double coef[6];
	   
	public:    subnivel(void) {}
	   
		   // interface para atribuicao de dados
		   void Simb(char *nome)            { strcpy(simb,nome); }
		   void Ene(double val)             { Eb = val; }
		   void Rs(double val)              { rs = val; }
		   void Coef(int idx, double val)   { coef[idx] = val; }
		   
		   // interface para leitura de dados
		   char  *Simb(void)    { return simb; }
		   double Ene(void)     { return Eb; }
		   double Rs(void)      { return rs; }
		   double Coef(int idx) { return coef[idx]; }

		   double SC_AbsFoto(double e) {
		      int    i;
		      double lnE = log(e);
		      double sec = 0;
		      double sum = 0;
		      if (e>Eb) {
			 for ( i=0; i<6; i++ ) { sum += coef[i]*pow(lnE,i); }
			 sec = exp(sum); }
		         return sec; }
		};

	class dbase {
	
	private:
	  
		   char     simb[3];
		   int      Z;
		   double   A, rho;
		   double   coer[6], incoer[6];
		   int      ns;
		   subnivel *sn;

	public:
	
		   dbase(void) {}
		   double Den(void) { return rho; }

		   double SC_AbsFoto(double e) {
		      int i;
		      double sum = 0;
		      for ( i=0; i<ns; i++ ) { sum += sn[i].SC_AbsFoto(e); }
		      return sum; }
		   
		   double SC_Elastico(double e) {
		      int    i;
		      double lnE = log(e);
		      double sum = 0;
		      for ( i=0; i<6; i++ ) { sum += coer[i]*pow(lnE,i); }
		      return exp(sum); }
		      
		   double SC_Inelastico(double e) {
		      int    i;
		      double lnE = log(e);
		      double sum = 0;
		      for ( i=0; i<6; i++ ) { sum += incoer[i]*pow(lnE,i); }
		      return exp(sum); }

		   Info Informacao(double e) {
		   
		      Info info;
		      double tau = SC_AbsFoto(e);
		      double sigma_e = SC_Elastico(e);
		      double sigma_i = SC_Inelastico(e);
		      double mu = tau + sigma_e + sigma_i;
		      double eps = rand()/(double)RAND_MAX;

		      info.pabs = tau/mu;
		      info.pee = sigma_e/mu;
		      info.pei = sigma_i/mu;
		      info.s = -log(eps)/(mu*rho);

		      return info;
		   }

	   void Ler_Dados(char *nome_atomo) {
	   
	      FILE  *fp;
	      char   sb[6],lixo[128];
	      int    pos;
	      int    i, j;
	      double Eb, coef, rs;

	      fp = fopen(nome_atomo,"rt");
	      if (fp==NULL) {
		 printf("Problema ao acessar o arquivo!!!\n");
		 exit(0);
	      }
	      fscanf(fp,"%s",simb);

	      fgets( lixo, 127, fp );
	      //printf("lixo: %s\n",lixo);

	      // Ler numero atomico, massa atomica e densidade
	      fscanf(fp," %d %lf %lf ",&Z,&A,&rho);

	      // Pular linha de dados desnecessarios
	      fgets( lixo, 127, fp );
	      //printf("lixo: %s\n",lixo);

	      // Ler coeficientes do espalhamento elastico
	      for ( i=0; i<6; i++ ) fscanf(fp," %lf ",&coer[i]);
	      // Ler coeficientes do espalhamento inelastico
	      for ( i=0; i<6; i++ ) fscanf(fp," %lf ",&incoer[i]);

	      // Pular linha de dados desnecessarios
	      fgets( lixo, 127, fp );
	      //printf("lixo: %s\n",lixo);

	      pos = ftell(fp);
	      // printf("pos: %d\n",pos);

	      ns = 0;
	      for (;;) {
		 ns++;
		 fgets( lixo, 127, fp );
		 if (lixo[0]=='g') break;
	      }
	      ns /= 3;
	      // printf("ns: %d\n",ns);

	      // sn = (subnivel *) malloc(ns*sizeof(subnivel));
	      sn = (subnivel*) new subnivel[ns];

	      fseek(fp,pos,SEEK_SET);
	      for ( j=0; j<ns; j++ ) {
		 fscanf(fp," %s %lf %lf ",sb,&Eb,&rs);
		 sn[j].Simb(sb);
		 sn[j].Ene(Eb);
		 sn[j].Rs(rs);
		 for ( i=0; i<6; i++ ) {
		    fscanf(fp," %lf ",&coef);
		    sn[j].Coef(i,coef);
		 }
	      }
	    fclose(fp);
	  }

	   void Imprimir(void) {
	   
	      int i, j;
	      printf("=============================================================\n");
	      printf("Simb: %s\n",simb);
	      printf("=============================================================\n");
	      printf("Z: %d\tA: %lf\trho: %e\n",Z,A,rho);
	      for ( i=0; i<6; i++ ) printf(" %+7.3e ",coer[i]);   printf("\n");
	      for ( i=0; i<6; i++ ) printf(" %+7.3e ",incoer[i]); printf("\n");
	      for ( j=0; j<ns; j++ ) {
		 printf("-------------------------------------------------------------\n");
		 printf("Simb: %s\tEb: %lf\trs: %lf\n",
		                    sn[j].Simb(), sn[j].Ene(), sn[j].Rs());
		 for ( i=0; i<6; i++ )
		    printf(" %+7.3e ",sn[j].Coef(i));
		 printf("\n");
	      }
	      printf("=============================================================\n");
	      printf("\n");
	   }
	};

	int main(int argc, char *argv[]) {

	   dbase    db;
	   int      i;
	   double   E0 = 50; // keV
	   double   x, x0 = 1.0; // cm
	   Info     prob;
	   double   eps;

	   foton f(E0,XYZ(1,0,0),XYZ(0,0,1));
	   f.Imprimir();
	   f.Translacao(XYZ(2,1,1));
	   f.Imprimir();
	   f.Rotacao(M_PI,XYZ(0,1,0));
	   f.Imprimir();

	   return 0;
	}

	// Uerj - 09 de fevereiro de 2023
