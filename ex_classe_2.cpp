
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <stdio.h>
        #include <ctime>

        class subnivel { 

	private:
  	  char   simb[6];
 	  double Eb, rs;
 	  double coef[6];

	public:

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
		 double sec = 0;      // variavel que vai guardar a seção de choque
	         double sum = 0;

		 if (e>Eb) {

	         for (i=0; i<6; i++) {

		   sum += coef[i]*pow(lnE, i); }
	      
	           sec = exp(sum);}

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

	  double Den(void) { return rho; }
	  
	  double SC_AbsFoto(double e) {

	         int i;
	         double sum = 0;

	         for (i=0; i<ns; i++) {

		   sum += sn[i].SC_AbsFoto(e); }
	      
	         return sum;
		 
	         }

	  double SC_Elastico(double e) {

	         int    i;
	         double lnE = log(e);
	         double sum = 0;

	         for (i=0; i<6; i++) {

		   sum += coer[i]*pow(lnE, i); }
	      
	         return exp(sum);

	         }

	   double SC_Ineslastico(double e) {

	         int    i;
	         double lnE = log(e);
	         double sum = 0;

	         for (i=0; i<6; i++) {

		   sum += incoer[i]*pow(lnE, i); }
	      
	         return exp(sum);

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

      fscanf(fp," %d %lf %lf ",&Z,&A,&rho); // Ler numero atomico, massa atomica e densidade

      fgets( lixo, 127, fp );

      for ( i=0; i<6; i++ ) fscanf(fp," %lf ",&coer[i]); // Ler coeficientes do espalhamento elastico

      for ( i=0; i<6; i++ ) fscanf(fp," %lf ",&incoer[i]); // Ler coeficientes do espalhamento inelastico

      fgets( lixo, 127, fp );
     
      pos = ftell(fp);
      
      ns = 0;
      for (;;) {
         ns++;
         fgets( lixo, 127, fp );
         if (lixo[0]=='g') break;
      }
      
      ns /= 3;

      sn = (subnivel*) new subnivel[ns];

      fseek(fp,pos,SEEK_SET);
      
      for ( j=0; j<ns; j++ ) {
	
         fscanf(fp," %s %lf %lf ", sb, &Eb, &rs);
	 
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
	    
	    printf("Simb: %s\n",simb);
	    printf("Z: %d\tA: %lf\trho: %e\n",Z,A,rho);
	    
	    for ( i=0; i<6; i++ ) printf(" %e ",coer[i]);   printf("\n");
	    for ( i=0; i<6; i++ ) printf(" %e ",incoer[i]); printf("\n");
	    for ( j=0; j<ns; j++ )

	    {
	      printf("Simb: %s\tEb: %lf\trs: %lf\n",  sn[j].Simb(), sn[j].Ene(), sn[j].Rs());

	      for ( i=0; i<6; i++ )
		
	      printf(" %e ",sn[j].Coef(i));
	      printf("\n");
	    }
	    
	  }
	  
	};

     int main (int argc, char *argv[]) {

     dbase  db;
     int i;
     double E0 = 5; //keV
     double x, x0 = 1e-4; // cm (espessura do meio)

     double mu, eps;
     srand(time(NULL));

     if (argc!=2) {
                     printf("Parametros errados!!!\n");
                     printf("\tUsar:\n");
                     printf("\t./p <argumento>\n");
                     exit(0);
                  }

     db.Ler_Dados(argv[1]);
     
     mu = (db.SC_AbsFoto(E0) + db.SC_Elastico(E0) + db.SC_Ineslastico(E0))*db.Den(); // mu = cm^2/g

     for (i=0; i<100; i++) {

     eps = rand()/(double)RAND_MAX;
     
     x = - log(eps)/mu;

     if (x>x0) { printf("\n\t %lf --------> Atravessou!\n\n", eps);  }

     else { printf("\n\t %lf XXXXXXXX Ficou!\n\n", eps); }

     }
     
     return 0;

     }

        // Versão orientada a objeto
        // Uerj - 13 de janeiro de 2023
