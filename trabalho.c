#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50
//entidade jogador
struct tp_jogador{
		  int id;
		  char nome[20];
		   int ngolo;
		   char activo[4];
		   char dataInicioContrato[12];
		   char dataFimContrato[12];
		   char apelido[20];
		   int idE;
		   
		  
	   }jogador;
	  /*entidade equipa*/
	struct tp_equipe{
			int id;
		char nome[20];
		}equipe;
	
	int vtIdE[SIZE];
	int vtngolo[SIZE];
	int vtidJ[SIZE];
	int contador=0;
	char verfica();
	
	
	void insertDatabase();
	void inDatabase();
	void menuj();
	void menu();
	void criar();
	void listar();
	void remover();
 	void listarj();
 	void cadastrarj();
 	void listarJdE();
 	void carregardadosE(); 
 	void carregardadosJ();
 	void eliminar();
 	//=================================================================================================
 	int main(int argc, char** argv)
	 {
	     carregardadosE();
		 carregardadosJ();
		 menu();
         menuj();

		 return 0;
	 }
	 // menu para equipes===================================================================================
	 void menu(){
		 int op;
	system("cls");
	
	
 	do{
 		printf("........menu equipa...........\n");
	printf("\n1-para criar equipa\n2-listar equipa \n");
	printf("0-sair \n");
	scanf("%d",&op);
	switch(op){
		case 1:
			criar();
			carregardadosE();
			break;
        case 2:
			listar();
			break;
            }
	}while(op!=0);
}
//criacao de equipes===============================================================================================
	void criar(){
    printf("............dados da equipa.........\n");
	printf("\n nome....\n");
	fflush(stdin);
	fgets(equipe.nome,20,stdin);
	printf("\n id \n");
	fflush(stdin);
	scanf("%i",&equipe.id);
	insertDatabase(equipe);
		 
}

	 // insercao da equipe no arquivo=========================================================================================
	void insertDatabase( struct tp_equipe equipe ){
		FILE *arquivo;
	//	int i=0;
	arquivo=fopen("dadoequipe.txt","a");
	if(arquivo==NULL){
		printf("ERRO FILLE NOT FOUND");
	}
	else
	{
		fprintf(arquivo,"%d %s\n",equipe.id,equipe.nome);
		printf("feito com sucesso");
	//	i++;
		
	}
	
	
	fclose(arquivo);
	
			
}
//======================================================================================================
void carregardadosE(struct tp_equipe equipe){
	system("cls");
		FILE *arquivo;
		int i=0;
	arquivo=fopen("dadoequipe.txt", "r");
	
	if(arquivo==NULL){
		printf("ERRO FILLE NOT LOADED");
	}
	
	else
	{ while(fscanf(arquivo,"%d %s\n",&equipe.id,equipe.nome)!=EOF)
	  {
		//printf("o id e o nome sao %d %s\n",equipe.id,equipe.nome);
		vtIdE[i]=equipe.id;
		i++;
		
		//fscanf(arquivo,"%d %s\n",&levar.id,levar.nome);
	  }
	}
	
	fclose(arquivo);
}
//========================================================================================================
	void listar( struct tp_equipe equipe){
	printf("............dados da equipa.........\n");
	
		FILE *arquivo;
//	int i=0;
	arquivo=fopen("dadoequipe.txt", "r");
	
	if(arquivo==NULL){
		printf("ERRO FILLE NOT LOADED");
	}
	
	else
	{ 
		printf("---id-----nome\n");
	while(fscanf(arquivo,"%d %s\n",&equipe.id,equipe.nome)!=EOF)
	  {
		printf("---%d----%s\n",equipe.id,equipe.nome);
	//	vtIdE[i]=equipe.id;
		//i++;
		
		//fscanf(arquivo,"%d %s\n",&levar.id,levar.nome);
	  }
	}
	
	fclose(arquivo);
		
}
//===================================================================================================	
void menuj(){
		int op;
	

	
 	do{
 			printf("\n..........menu jogador..........\n");
	printf("\n o numero de jogadores %d \n",contador);
	printf("\n1-cadastrar jogador\n2-listar todos jogadores  \n");
	printf("3-listar jogador de uma equipe\n4-voltar\n5-eliminar\n0-sair \n");
	scanf("%d",&op);
	switch(op){
		case 1:
			cadastrarj();
			break;
        case 2: 
			listarj();
			break;
       case 3:
			listarJdE();
			break;
		case 4:
			menu();
			break;
		case 5:
			eliminar();
			break;
	}
	}while(op!=0);
	system("cls");
} //===================================================================================================
 void cadastrarj(){
 	
	  //carregardadosJ();
	  system("cls");
		printf("\n\n...preenchimento de dados de jogadores da equipa...\n\n");
 	
		int v=0;
	    int i;
		do{
			
        printf("\n id da equipa... \n");
		fflush(stdin);
    	scanf("\n %d",&jogador.idE);
	
	    for(i=0;i<SIZE;i++){
            if(vtIdE[i]==jogador.idE){
			v=vtIdE[i];
		
		//	printf("existe equipa\n");
			}
		}
		}while(v==0);

		int v1=0;
		int j;
		int val;
		
		do{
			
		printf("\n id do jogador... \n");
		fflush(stdin);
        scanf("\n%d",&val);
			
				
        for(j=0;j<contador;j++){
		    if(vtidJ[j]==val){
			     v1=vtidJ[j];
   
			printf("existe jogador%d \n",vtidJ[j]);
			}
		
			  // v1=0;	
			  }
			  
			
		}
		while(v1!=0);
	//	v1=0;
		jogador.id=val;
		
	
	printf("\n nome... \n");
	fflush(stdin);
	fgets(jogador.nome,20,stdin);
	
	printf("\n esta ativo\n");
    fflush(stdin);
	fgets(jogador.activo,4,stdin);
	
	printf("\n data de inicio de contrato\n");
	fflush(stdin);
	fgets(jogador.dataInicioContrato,12,stdin);
	
	printf("\n numero de golo \n");
	fflush(stdin);
  	scanf("\n %d",&jogador.ngolo);
  	
    printf("\n data de fim de contrato\n");
    fflush(stdin);
	fgets(jogador.dataFimContrato,12,stdin);
	
	printf("\n apelido\n");
	fflush(stdin);
	fgets(jogador.apelido,20,stdin);
	
	inDatabase(jogador);
	
	
}
//=======================================================================================================
void inDatabase(struct tp_jogador jogador){
	FILE *arquivo;
	arquivo=fopen("dadojogador.txt","a");
	if(arquivo == NULL){
		printf("ERRO FILLE NOT FOUND");
		exit(1);
	}
	else
	{
		fprintf(arquivo,"%d %d %s %d %s %s %s %s \n",jogador.idE,jogador.id,jogador.nome,jogador.ngolo,
		jogador.activo,jogador.dataInicioContrato,jogador.dataFimContrato,jogador.apelido);
		printf("feito com sucesso\n");
	
		
		
	}
	fclose(arquivo);
	
	
	
}
//====================================================================================================================
void listarj(struct tp_jogador jogador){
	printf("............dados do jogador.........\n");
	
    FILE *arquivo;
	arquivo=fopen("dadojogador.txt", "r");
	
	if(arquivo==NULL){
		printf("ERRO FILLE NOT LOADED \n");
	}
	
	else
	{
		printf("\nidEq---id---nome---nr golo---ativo---dainicio---datafim---apelido\n");
	 while(fscanf(arquivo,"%d %d %s %d %s %s %s %s \n",&jogador.idE,&jogador.id,jogador.nome,&jogador.ngolo,
		jogador.activo,jogador.dataInicioContrato,jogador.dataFimContrato,jogador.apelido)!=EOF)
	  {
	  	
	  	
			 printf("--%d--- -%d--- -%s--- -%d--- -%s--- -%s--- -%s--- %s\n",jogador.idE,jogador.id,jogador.nome,jogador.ngolo,
		jogador.activo,jogador.dataInicioContrato,jogador.dataFimContrato,jogador.apelido); 
		 
	  }
	} 
	
	fclose(arquivo);
		
	
}
//========================================================================================================================
 	void listarJdE(struct tp_jogador jogador){
		 
     printf("............dados do jogador.........\n");
	
     FILE *arquivo;
     int i=0;
	arquivo=fopen("dadojogador.txt", "r");
	
	printf("digite o id da equipa\n");
	int v;
	scanf("%d",&v);
	if(arquivo==NULL){
		printf("ERRO FILLE NOT LOADED");
	}
	
	else
	{
		printf("\nidEq---id---nome---nr golo---ativo---dainicio---datafim---apelido\n");
	 while(fscanf(arquivo,"%d %d %s %d %s %s %s %s \n",&jogador.idE,&jogador.id,jogador.nome,&jogador.ngolo,
		jogador.activo,jogador.dataInicioContrato,jogador.dataFimContrato,jogador.apelido)!=EOF)
	  {
         
	  	for(i=0;i<SIZE;i++){
	  	if(vtIdE[i]==jogador.idE && vtIdE[i]==v){
	  		
		  	
			 printf("--%d--- -%d--- -%s--- -%d--- -%s--- -%s--- -%s--- %s\n",jogador.idE,jogador.id,jogador.nome,jogador.ngolo,
		jogador.activo,jogador.dataInicioContrato,jogador.dataFimContrato,jogador.apelido); 
		
		  }
       }	
	  }
	}
	
	fclose(arquivo);
		
	
}
//=========================================================================================================================
void carregardadosJ(){
	
		FILE *arquivo;
		int i=0;
		int j=0;
	    arquivo=fopen("dadojogador.txt", "r");
	
	if(arquivo==NULL){
		printf("ERRO FILLE NOT LOADED");
		
	}
	
	else
	{
	 while(fscanf(arquivo,"%d %d %s %d %s %s %s %s \n",&jogador.idE,&jogador.id,jogador.nome,&jogador.ngolo,
		jogador.activo,jogador.dataInicioContrato,jogador.dataFimContrato,jogador.apelido)!=EOF)
	  {
         
	  	
		  	
			// printf("o idEq, id, nome, nr golo, ativo, dainicio, datafim,apelido %d %d %s %d %s %s %s %s \n",jogador.idE,jogador.id,jogador.nome,jogador.ngolo,
		//jogador.activo,jogador.dataInicioContrato,jogador.dataFimContrato,jogador.apelido);
		vtngolo[i]=jogador.ngolo; 
		vtidJ[j]=jogador.id;
		i++;
		j++;
		
  		}
       }
       contador=i;
       fclose(arquivo);
	
}
//====================================================================================================================================

void eliminar(){
	int i;
	for(i=0;i<contador;i++){
		printf("vetor%d\n",vtngolo[i]);
	}
	int aux=0,j;
	for(i=0;i<contador;i++){
		for(j=i+1;i<contador;j++){
			if(vtngolo[i]>vtngolo[j]){
				aux=vtngolo[i];
				vtngolo[i]=vtngolo[j];
				vtngolo[j]=aux;
				
			}
		}
	}
	/*FILE *arquivo,*tempo;
	    arquivo=fopen("dadojogador.txt", "r");
	   // tempo=fopen("tempo.txt","w");
        if(arquivo==NULL){
	/*	printf("ERRO FILLE NOT LOADED");
	}
	else
	{
	 while(fscanf(arquivo,"%d %d %s %d %s %s %s %s \n",&jogador.idE,&jogador.id,jogador.nome,&jogador.ngolo,
		jogador.activo,jogador.dataInicioContrato,jogador.dataFimContrato,jogador.apelido)!=EOF)
	  {
         if(verfica(vtngolo,contador)){
	  	printf("--%d--- -%d--- -%s--- -%d--- -%s--- -%s--- -%s--- %s\n",jogador.idE,jogador.id,jogador.nome,jogador.ngolo,
		jogador.activo,jogador.dataInicioContrato,jogador.dataFimContrato,jogador.apelido);
	  }
	  }
	  fclose(arquivo);
	  //fclose(tempo);
	 //  remove("dadojogador.txt");
	  //rename("tempo.txt","dadojogador.txt");
	  
	
}

} 

char verfica(int vet[], int n  ){
	int i;
	for(i=0;i<n;i++){
		if(vet[i]==jogador.ngolo){
		return '1';
		}
	}
	return '1';
	
*/
}