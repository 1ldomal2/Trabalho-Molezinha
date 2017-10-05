#ifndef _Pesquisa_
#define _Pesquisa_
/*
PESQUISA Tipo_Pesquisa();
void Pesquisa(PESQUISA Pesquisa);
int Valida_Codigo_Categoria(int Codigo, int Modo_de_Abertura);


*/
PESQUISA Tipo_Pesquisa(){
	PESQUISA Pesquisa;
	int  Data,Categoria_Acomodacao,Quantidade_Pessoas,Facilidade;
	Verde("Digite '1' no campo  pelo qual deseja pesquisar:\n");
	do{
		do{
			 printf("\nData");
			 scanf("%d",&Pesquisa.Data);
			if(Pesquisa.Data!=0 && Pesquisa.Data!=1){
				printf("Porfavor digite apenas ");
				Vermelho("0 para desativado ");
				printf("ou ");
				Verde("1 para ativado");
			}
		}while(Pesquisa.Data != 1 && Pesquisa.Data !=0);
		//valida aceitando apenas 1 ou 0

		do{
			 printf("Categoria de Acomodação:");
			 scanf("%d",&Pesquisa.Categoria_Acomodacao);
			if(Pesquisa.Categoria_Acomodacao!=0 && Pesquisa.Categoria_Acomodacao!=1){
				printf("Porfavor digite apenas ");
				Vermelho("0 para desativado ");
				printf("ou ");
				Verde("1 para ativado");
			}
		}while(Pesquisa.Categoria_Acomodacao != 1 && Pesquisa.Categoria_Acomodacao !=0);
		//valida aceitando apenas 1 ou 0

		do{
			 printf("Quantidade de Pessoas:");
			 scanf("%d",&Pesquisa.Quantidade_Pessoas);
			if(Pesquisa.Quantidade_Pessoas != 1 && Pesquisa.Quantidade_Pessoas !=0){
				printf("Porfavor digite apenas ");
				Vermelho("0 para desativado ");
				printf("ou ");
				Verde("1 para ativado");
			}
		}while(Pesquisa.Quantidade_Pessoas != 1 && Pesquisa.Quantidade_Pessoas !=0);
		//valida aceitando apenas 1 ou 0

		do{
			 printf("Facilidades:");
			 scanf("%d",&Pesquisa.Facilidade);
			if(Pesquisa.Facilidade != 1 && Pesquisa.Facilidade !=0){
				printf("Porfavor digite apenas ");
				Vermelho("0 para desativado ");
				printf("ou ");
				Verde("1 para ativado");
			}
		}while(Pesquisa.Facilidade != 1 && Pesquisa.Facilidade !=0);
		//valida aceitando apenas 1 ou 0
		printf("\n");

	}while(Pesquisa.Data+Pesquisa.Categoria_Acomodacao+Pesquisa.Quantidade_Pessoas+Pesquisa.Facilidade==0);
	//Se for tudo 0


	return Pesquisa;

}

void Pesquisa(PESQUISA Pesquisa){

	int Modo_Abertura=Configuracoes();
	int Ok=0;



	if(Pesquisa.Data==1){
		printf("\nDigite  a Data:");
		scanf("%s",Pesquisa.Datas);
	}
	//Pega dados sobre a Data

	if(Pesquisa.Categoria_Acomodacao==1){
		do{
			printf("Digite a categoria da Acomodação");
			scanf("%d",&Pesquisa.Codigo_Categoria);

			Ok = Valida_Codigo_Categoria(Pesquisa.Codigo_Categoria,Modo_Abertura);

			if(Ok==0){
				Vermelho("O codigo não está cadastrado \n");
			}
		}while(Ok==0);
		//Validar acomodação;
		//Olhar no arquivo se está cadastrp
	}
	//Pega dados sobre a categoria da acomodação

	if(Pesquisa.Quantidade_Pessoas==1){
		do{
			printf("Digite a Quantidade de Adultos:");
			scanf("%d",&Pesquisa.Quantidade_Adultos);
			if(Pesquisa.Quantidade_Adultos <= 0){
				Vermelho("\nDigite um numero maior que zero\n");
			}
		}while(Pesquisa.Quantidade_Adultos<=0);
		//Valida para não colocar um numero negativo
		do{
			printf("Digite a Quantidade de Crianças ");
			scanf("%d",&Pesquisa.Quantidade_Criancas);
			if(Pesquisa.Quantidade_Criancas){
				Vermelho("\nDigite um numero maior ou igual a zero\n");
			}
		}while(Pesquisa.Quantidade_Criancas<0);
		//Valida para não colocar um numero negativo
	}
	//Pega dados referente a quantidade de pessoas tanto criança quanto adultos

	if(Pesquisa.Facilidade==1){
		do{
			printf("Digite a quantidade de Televisoes:");
			scanf("%d",&Pesquisa.Facilidades.Televisao);
			if(Pesquisa.Facilidades.Televisao<0){
				Vermelho("0 não é um valor valido");
			}
		}while(Pesquisa.Facilidades.Televisao<0);
		
		do{
			printf("Digite a quantidade de Ar Condicionado:");
			scanf("%d",&Pesquisa.Facilidades.Ar_Condicionado);
			if(Pesquisa.Facilidades.Ar_Condicionado<0){
				Vermelho("0 não é um valor valido");
			}
			}while(Pesquisa.Facilidades.Ar_Condicionado<0);
		
		do{
			printf("Digite a quantidade de Frigobar:");
			scanf("%d",&Pesquisa.Facilidades.Frigobar);
			if(Pesquisa.Facilidades.Frigobar<0){
				Vermelho("0 não é um valor valido");
			}
			}while(Pesquisa.Facilidades.Frigobar<0);
		
		do{
			printf("Possui Internet ?:");
			scanf("%d",&Pesquisa.Facilidades.Internet);
			if(Pesquisa.Facilidades.Internet<0){
				Vermelho("0 não é um valor valido");
			}
			}while(Pesquisa.Facilidades.Internet<0);
		
		do{
			printf("Digite a quantidade de Banheiras:");
			scanf("%d",&Pesquisa.Facilidades.Banheira);
			if(Pesquisa.Facilidades.Banheira<0){
				Vermelho("0 não é um valor valido");
			}
		}while(Pesquisa.Facilidades.Banheira<0);

	}
	//pega dados sobre as Facilidades(coisas que a acomodaçao possui)

	//Pega os dados necessários

}



int Valida_Codigo_Categoria(int Codigo, int Modo_de_Abertura){
	//Procura nas acomodacoes pelo codigo da categoria para que assim nao apague os que sao vinculados
	FILE *Arquivo;
	char Temporario[9999];
		//Ponteiro para Arquivo
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen("Arquivos/Codigo_Categoria.txt","r");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Categoria cadastradas\n");
			return 0;
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen("Arquivos/Codigo_Categoria.bin","rb");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Categoria cadastradas\n");
			return 0;		
		}
		break;
	}		

	int Contador1=0, Vetor_Codigos[9999];
		//Evita lixo de memoria
	if (Modo_de_Abertura == Arquivo_Texto)
	{
		while(!feof(Arquivo)){

			fscanf(Arquivo,"%d",&Vetor_Codigos[Contador1]);
				//Lê o Codigo
			getc(Arquivo);
				//lê/pula ';'
			if(feof(Arquivo)){
				//Verifica se chegou a ao fim do arquivo
				break;
				//sai do while
			}
			fscanf(Arquivo,"%[^\n]s",Temporario);
			getc(Arquivo);
			//Move o ponteiro até o proximo codigo
			Contador1++;
			//Adicione 1 ao contador ou seja adicione um ao numero do indice
			
		}

	}else if (Modo_de_Abertura == Arquivo_Binario)
	{
		CODIGO_CATEGORIA Codigo_Categoria;
		Contador1=0;
		//Zera contador de Codigos
		while(!feof(Arquivo)){
			fread(&Codigo_Categoria, sizeof(CODIGO_CATEGORIA),1,Arquivo);
			//Le arquivo e passac para a struct
			if(feof(Arquivo)){
				break;
				//Se estiver no fim do arquivo sai do loop
			}

			Vetor_Codigos[Contador1] = Codigo_Categoria.Codigo;
			Contador1++;
			//Soma no contador de contador
		}
	}
	if(Contador1!=1){
		Quick_Sort(Vetor_Codigos,0,Contador1);
		//Ordena o Vetor;
	}
		for (int i = 0; i < Contador1; ++i)
		{
			if (Codigo == Vetor_Codigos[i])
			{
				return 1;
			}
		}
	return 0;
}



#endif