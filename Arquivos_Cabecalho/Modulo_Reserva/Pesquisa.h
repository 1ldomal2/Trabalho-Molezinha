#ifndef _Pesquisa_
#define _Pesquisa_
/*
PESQUISA Tipo_Pesquisa();
void Pesquisa(PESQUISA Pesquisa);
int Valida_Codigo_Categoria(int Codigo, int Modo_de_Abertura);
void Recebe_Data(DATA *Data);
int Pequisa_Periodo(int Acomodacao_Invalida[],int Inicio_Vetor,DATA Entrada,DATA Saida);
void Pequisa_Quantidade(int Acomodacao_Invalida[],int Inicio_Vetor,int Quantidade);
void Pequisa_Facilidades(int Acomodacao_Invalida[],int Inicio_Vetor);
void Pequisa_Categoria_Acomodacao(int Acomodacao_Invalida[],int Inicio_Vetor);

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
	int Contador=0;
	int Vetor_Acomodacoes_Invalidas[Tamanho2];
	int Inicio_Vetor = 0;
	if(Pesquisa.Data==1){

		Recebe_Data(&Pesquisa.Data_Entrada);
		Recebe_Data(&Pesquisa.Data_Saida);
		//Recebe dados da Data

		Inicio_Vetor = Pequisa_Periodo(Vetor_Acomodacoes_Invalidas,Inicio_Vetor,Pesquisa.Data_Entrada,Pesquisa.Data_Saida);			
	}
	

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

int Valida_Reserva(){
	ACOMODACOES Acomodacoes;
	int Diferenca_A_B = 1;
	int Acomodacao_Invalida[999], Inicio_Vetor = 0;
	int Acomodacao_Registradas[999],Contador_Acomodacao_Registrada;
	char Temporario[999];
	DATA Entrada,Saida;
	FILE *Arquivo;

	int Modo_Abertura = Configuracoes();
	//TXT ou Binario


	if(Modo_Abertura == Arquivo_Texto){
		Arquivo = fopen("Arquivos/Acomodacoes.txt","r");
	}else{
		Arquivo = fopen("Arquivos/Acomodacoes.bin","rb");		
}
	//abre o arquivo 


	if(Arquivo == NULL){
		Vermelho("\nErro ao abrir arquivo\n");
	}else{
		//TEXTO
		if(Modo_Abertura == Arquivo_Texto){
			while(!feof(Arquivo)){
				fscanf(Arquivo,"%d",&Acomodacao_Registradas[Contador_Acomodacao_Registrada]);//Lê o Codigo e passa para o vetor
				getc(Arquivo);
				if(feof(Arquivo)){
					break;
				}//evita dup
				//lê/pula ';'
				Contador_Acomodacao_Registrada++;
				//Soma no contador de registrados
				fscanf(Arquivo,"%[^\n]s",Temporario);
				getc(Arquivo);
				//pula o \n
			}
	
	
		//BINARIO
		}else{
			while(!feof(Arquivo)){
				fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
				Acomodacao_Registradas[Contador_Acomodacao_Registrada] = Acomodacoes.Codigo;
				//Passa codigo de acomodacao para vetor
				if(feof(Arquivo)){
					break;
				}
				Contador_Acomodacao_Registrada++;
			}			
		}
	}
	//Passa todos codigos existentes de acomodacao para o vetor

	Inicio_Vetor = Pequisa_Periodo(Acomodacao_Invalida,Inicio_Vetor,Entrada,Saida);
	for(int i = 0; i < Inicio_Vetor; i++){
		for(int j = 0;j<Contador_Acomodacao_Registrada;j++){
			if(Acomodacao_Invalida[i]==Acomodacao_Registradas[j]){
				Diferenca_A_B = 0;
			}	//Caso entra no IF nao esta disponivel
		}
		if(Diferenca_A_B == 1){
			//FAZER TERCEIRO VETOR QUE é O A - B ou seja os valores que nao se chocam		
		}
	}

}

int Pequisa_Periodo(int Acomodacao_Invalida[],int Inicio_Vetor,DATA Entrada,DATA Saida){
	FILE *Arquivo;
	FLUXO Fluxo;
	int Contador_Periodo_Lido_Arquivo=0;
	char Url[999];
	int Vetor_Periodo_Pesquisar[999];//Declara vetor periodo a ser pesquisado 
	int Contador_Periodo_Input = Saida.Dia - Entrada.Dia + 1;//QUantidade de dias que hospede pretende ficar

	for(int i = 0; i <= Contador_Periodo_Input; i++){
		Vetor_Periodo_Pesquisar[i] = Entrada.Dia + i; 
	}
	//Passa o periodo em dias para um vetor por exemplo se começa no dia 1 e vai ate o 5 ele ficou 5 dias e sera setado no vetor os valores 1 2 3 4 e 5

	char Pasta[999];
	strcpy(Pasta,"mkdir /Arquivos/Reserva/");
	char Ano[10];
	sprintf(Ano,"%u",Entrada.Ano);
	strcat(Pasta,Ano);
	system(Pasta);
	char Mes[10];
	sprintf(Mes,"%u",Entrada.Mes);
	strcat(Pasta,Mes);
	system(Pasta);
	system("clear");
	//Criando pastas para evitar o erro de falha na segmentação

	strcpy(Url,"Arquivos/");
	strcat(Url,Ano);
	strcat(Url,"/");
	strcat(Url,Mes);
	Verificacao_Arquivo(Url,2);	
	Arquivo = fopen(Url,"rb");//sempre abre em binario 
	//Abre arquivo 

	if (Arquivo == NULL)
	{
		Vermelho("Erro Abrir arquivo");
	}else{
		while(!feof(Arquivo)){
			fread(&Fluxo, sizeof(FLUXO),1,Arquivo);//Por ser arquivo de fluxo decidimos ser sempre binario para facilitar
			if(feof(Arquivo)){
				break;
			}
			Contador_Periodo_Lido_Arquivo = Fluxo.Data_Saida.Dia - Fluxo.Data_Entrada.Dia + 1;
			//QUantidade de dias que hospede pretende ficar "Periodo"
			for(int i = 0; i < Contador_Periodo_Input; i++){
				for(int j = 0;j<Contador_Periodo_Lido_Arquivo;j++){
					if(Vetor_Periodo_Pesquisar[i] == Fluxo.Vetor_Dias[j]){
						Acomodacao_Invalida[Inicio_Vetor] = Fluxo.Codigo_Acomodacao;
						Inicio_Vetor++;
						//Caso entra no IF nao esta disponivel
					} 
				}
			}
			//Passa pro vetor as acomodações em que há sombreamento de datas ou seja, quando a data em que a pessoa pretende se hospedar ja tem alguma reserva	.....em outras palavras o vetor vai ser preenchido com as acomodacoes invalidas
		}
	}
	return Inicio_Vetor;
	//retorna o indice do vetor que sera usado na proxima pesquisa
}

void Pequisa_Quantidade(int Acomodacao_Invalida[],int Inicio_Vetor,int Quantidade){


}

void Pequisa_Facilidades(int Acomodacao_Invalida[],int Inicio_Vetor){


}

void Pequisa_Categoria_Acomodacao(int Acomodacao_Invalida[],int Inicio_Vetor){


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


void Recebe_Data(DATA *Data){

	do{
		printf("\nDigite o Ano ");
		scanf("%u",&Data->Ano);
		if(Data->Ano<2017){
			Vermelho("\nAno invalido");
		}
	}while(Data->Ano<2017);
	//Valida o Ano


	do{
		printf("\nDigite o numero referente ao Mes ");
		scanf("%u",&Data->Mes);
		if(Data->Mes<1 || Data->Mes>12){
			Vermelho("\nMes invalido");
		}
	}while(Data->Mes<1 || Data->Mes>12);
	//Valida o Mes;

	switch (Data->Mes){

		case Janeiro:
			do{
				printf("\nDigite o Dia ");
				scanf("%u",&Data->Dia);
			}while(Data->Dia>31 || Data->Dia<1);
		break;


		case Fevereiro:
			do{
				printf("\nDigite o Dia ");
				scanf("%u",&Data->Dia);
			}while(Data->Dia>28 || Data->Dia<1);
		break;


		case Marco:
			do{
				printf("\nDigite o Dia ");
				scanf("%u",&Data->Dia);
			}while(Data->Dia>31 || Data->Dia<1);
		break;


		case Abril:
			do{
				printf("\nDigite o Dia ");
				scanf("%u",&Data->Dia);
			}while(Data->Dia>30 || Data->Dia<1);
		break;


		case Maio:
			do{
				printf("\nDigite o Dia ");
				scanf("%u",&Data->Dia);
			}while(Data->Dia>31 || Data->Dia<1);
		break;


		case Junho:
			do{
				printf("\nDigite o Dia ");
				scanf("%u",&Data->Dia);
			}while(Data->Dia>30 || Data->Dia<1);
		break;


		case Julho:
			do{
				printf("\nDigite o Dia ");
				scanf("%u",&Data->Dia);
			}while(Data->Dia>31 || Data->Dia<1);
		break;


		case Agosto:
			do{
				printf("\nDigite o Dia ");
				scanf("%u",&Data->Dia);
			}while(Data->Dia>31 || Data->Dia<1);
		break;


		case Setembro:
			do{
				printf("\nDigite o Dia ");
				scanf("%u",&Data->Dia);
			}while(Data->Dia>30 || Data->Dia<1);
		break;


		case Outubro:
			do{
				printf("\nDigite o Dia ");
				scanf("%u",&Data->Dia);
			}while(Data->Dia>31 || Data->Dia<1);
		break;


		case Novembro:
			do{
				printf("\nDigite o Dia ");
				scanf("%u",&Data->Dia);
			}while(Data->Dia>30 || Data->Dia<1);
		break;

		case Dezembro:
			do{
				printf("\nDigite o Dia ");
				scanf("%u",&Data->Dia);
			}while(Data->Dia>31 || Data->Dia<1);
		break;
		//Valida dia do mes
	}

}
//Cria os vetores para as reservas

#endif