#ifndef _Pesquisa_
#define _Pesquisa_
/*
int Tipo_Pesquisa();

*/
PESQUISA Tipo_Pesquisa(){
	PESQUISA Pesquisa;
	int  Data,Categoria_Acomodacao,Quantidade_Pessoas,Facilidade;
	Verde("Digite 1 no campo em que deseja pesquisar\n");
	do{
		do{
			 printf("\nData");
			 scanf("%d",&Pesquisa.Data);
		}while(Pesquisa.Data != 1 && Pesquisa.Data !=0);
		do{
			 printf("Categoria de Acomodação":);
			 scanf("%d",&Pesquisa.Categoria_Acomodacao);
		}while(Pesquisa.Categoria_Acomodacao != 1 && Pesquisa.Categoria_Acomodacao !=0);
		do{
			 printf("Quantidade de Pessoas:");
			 scanf("%d",&Pesquisa.Quantidade_Pessoas);
		}while(Pesquisa.Quantidade_Pessoas != 1 && Pesquisa.Quantidade_Pessoas !=0);
		do{
			 printf("Facilidades:");
			 scanf("%d",&Pesquisa.Facilidade);
		}while(Pesquisa.Facilidade != 1 && Pesquisa.Facilidade !=0);

	}while(Data+Categoria_Acomodacao+Quantidade_Pessoas+Facilidades==0);


	return Pesquisa;
	//Pesquisa Simples será 1 2 4 8

	//Pesquisa Avançada será os demais numeros


}

void Nivel_Pesquisa(PESQUISA Pesquisa){


	if(Pesquisa.Data==1){
		printf("\n");
		scanf("%d",&)
	}
	if(Pesquisa.Categoria_Acomodacao==1){
		printf("\n");
		scanf("%d",&)
	}
	if(Pesquisa.Quantidade_Pessoas==1){
		printf("\n");
		scanf("%d",&)
		printf("\n");
		scanf("%d",&)
	}
	if(Pesquisa.Facilidade==1){
		printf("\n");
		scanf("%d",&)
	}
}

#endif