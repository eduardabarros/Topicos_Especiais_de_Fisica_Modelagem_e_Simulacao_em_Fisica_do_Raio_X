
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
	   char   simb[3];
	   int    Z;
	   double A, rho;
	   double coer[6], incoer[6];
	   subnivel sn;
	  
	}  dbase;

	int main(void)

	{	  
	   FILE  *fp;
	   //   char   simb[3];
	   char   lixo[128];
	   int    pos;
	   int    i;
	   // int Z;
	   // double A, rho;
	   // double coer[6], incoer[6];

	   dbase db;
	   subnivel sn;

	   fp = fopen("./database/H.MU","rt");
	   if (fp==NULL) {
 	     printf("Problema ao acessar o arquivo!!!\n");
	      exit(0);
	      
 	  }
	   
	   fscanf(fp,"%s",db.simb);		// fscanf = abre arquivos (pega o arquivo onde ele esta guardado e abre no programa que estou usando)
	   printf("simb: %s\n",db.simb);

	   fgets( lixo, 127, fp );              //printf("lixo: %s\n",lixo);

	   fscanf(fp," %d %lf %lf ",&db.Z,&db.A,&db.rho); 	// O ultimo espaço em branco, lê a linha debaixo e ignora o \n
	   printf("Z: %d\tA: %lf\trho: %e\n",db.Z,db.A,db.rho);
	
	   fgets( lixo, 127, fp );		// Resolve um problema em relação as strings (torna espaços em branco como caracter valido)
						// (string que vai armazenar os dados, quantidade máxima de caracteres, o ponteiro que vai armazenar o arquivo)
 	                                        //printf("lixo: %s\n",lixo);

	   for ( i=0; i<6; i++ ) fscanf(fp," %lf ",&db.coer[i]);
 	   for ( i=0; i<6; i++ ) fscanf(fp," %lf ",&db.incoer[i]);

	   for ( i=0; i<6; i++ ) printf(" %e ",db.coer[i]);   printf("\n");
	   for ( i=0; i<6; i++ ) printf(" %e ",db.incoer[i]); printf("\n");

	   fgets( lixo, 127, fp );              //printf("lixo: %s\n",lixo);

	   fscanf(fp," %s %lf %lf ",db.sn.simb,&db.sn.Eb,&db.sn.rs); 	// O ultimo espaço em branco, lê a linha debaixo e ignora o \n
	   for ( i=0; i<6; i++ ) fscanf(fp," %lf ",&db.sn.coef[i]);
		   
	   printf("Simb: %s\tEb: %lf\trs: %lf\n",db.sn.simb,db.sn.Eb,db.sn.rs);
	   for ( i=0; i<6; i++ ) printf(" %e ",db.sn.coef[i]);   printf("\n");

	   pos = ftell(fp);			// ftell = me diz onde estou dentro do meu arquivo de dados (pos = posição)
	   printf("pos: %d\n",pos);

 	  fclose(fp);
 	  return 0;
	  
	}

        // Uerj - 16 de dezembro de 2022
