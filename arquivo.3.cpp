
        // Segunda estratégia 

	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <stdio.h>

	typedef struct

	{
	   char   simb[6];
	   double Eb, rs;
	   double coef[6];
	  
	}  subnivel;

	typedef struct

	{
	   char      simb[3];
	   int       Z;
	   double    A, rho;
	   double    coer[6], incoer[6];
	   int ns;
	   subnivel *sn;
	  
	}  dbase;

       int main(int argc, char *argv[])

	{	  
	   FILE    *fp;
	   char     lixo[128];
	   int      pos;
	   int      i,j;
	   //  int      ns;

	   dbase    db;
	   //  subnivel sn;

	   if (argc!=2) {
	     printf("Parametros errados!!!\n");
	     printf("\tUsar:\n");
	     printf("\t./nome_do_programa <argumento>\n");
	     exit (0);

	   }

	   fp = fopen(argv[1],"rt");
	   if (fp==NULL)

	  {
 	     printf("Problema ao acessar o arquivo!!!\n");
	      exit(0);
	   }
	   
	   fscanf(fp,"%s",db.simb);
	   printf("simb: %s\n",db.simb);

	   fgets( lixo, 127, fp );

	   fscanf(fp," %d %lf %lf ",&db.Z,&db.A,&db.rho);
	   printf("Z: %d\tA: %lf\trho: %e\n",db.Z,db.A,db.rho);
	
	   fgets( lixo, 127, fp );

	   for ( i=0; i<6; i++ ) fscanf(fp," %lf ",&db.coer[i]);
 	   for ( i=0; i<6; i++ ) fscanf(fp," %lf ",&db.incoer[i]);

	   for ( i=0; i<6; i++ ) printf(" %e ",db.coer[i]);   printf("\n");
	   for ( i=0; i<6; i++ ) printf(" %e ",db.incoer[i]); printf("\n");

	   fgets( lixo, 127, fp );



	  //--------------------------------------------------------------------------------------------------------------------------------------

	   pos = ftell(fp);
	   printf("pos: %d\n",pos);	   
 
	 db. ns = 0;
	  
	  for (;;)

	    {
	      db.ns++;
	      fgets( lixo, 127, fp );

	      if (lixo[0] == 'g') break;

	    }
	
	  db.ns /= 3;
	  printf("ns: %d\n",db.ns);

	  db.sn = (subnivel*) new subnivel[db.ns];   // new = malloc (db.sn = (subnivel *)malloc(ns*sizeof(subnivel));

	  fseek(fp,pos,SEEK_SET);                  // Fazendo o arquivo voltar para a posição inicial (volta para a linha '9' onde esta K)
	                                           // Uma vez voltando para essa posição (onde esta K), vamos ler de 3 em 3 linhas, 15 dados

	   for (j=0; j<db.ns; j++)

	      {
		
	     fscanf(fp," %s %lf %lf ",db.sn[j].simb,&db.sn[j].Eb,&db.sn[j].rs);
	    
	     for (i=0; i<6; i++)

	     fscanf(fp," %lf ",&db.sn[j].coef[i]);
		   
             printf("Simb: %s\tEb: %lf\trs: %lf\n",db.sn[j].simb,db.sn[j].Eb,db.sn[j].rs);

	   for (i=0; i<6; i++)
	     
	     printf(" %e ",db.sn[j].coef[i]);
	     printf("\n");

	   //--------------------------------------------------------------------------------------------------------------------------------------

	      }

 	  fclose(fp);
 	  return 0;
	  
	}

        // Uerj - 16 de dezembro de 2022
