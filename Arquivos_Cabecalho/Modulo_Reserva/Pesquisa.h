#ifndef _Pesquisa_
#define _Pesquisa_
/*
PESQUISA Tipo_Pesquisa();
void Pesquisa(PESQUISA Pesquisa);
int Retorna_Acomodacao_Disponiveis_Por_Periodo(int Acomodacao_Disponiveis[],PESQUISA Pesquisa_Entrada,PESQUISA Pesquisa_Saida);
void Pequisa_Quantidade(int Acomodacao_Invalida[],int Inicio_Vetor,int Quantidade);
void Pequisa_Facilidades(int Acomodacao_Invalida[],int Inicio_Vetor);
void Pequisa_Categoria_Acomodacao(int Acomodacao_Invalida[],int Inicio_Vetor);
int Valida_Codigo_Acomodacao(int Codigo, int Modo_de_Abertura);
void Recebe_Data(DATA *Data);
int Pequisa_Periodo(int Acomodacao_Invalida[],int Inicio_Vetor,DATA Entrada,DATA Saida);
void Verifica_Fluxo(char Url[999], DATA Data_Entrada,DATA Data_Saida, int Acomodacao_Indisponiveis[]);
int Todas_Acomodacoes_TXT(char Url[99], int Acomodacoes_Disponiveis[],int Acomodacoes_Indisponiveis[], int Contador_Acomodacao_Indisponiveis);
*/
int Todas_Acomodacoes_TXT(char Url[99], int Acomodacoes_Disponiveis[],int Acomodacoes_Indisponiveis[], int Contador_Acomodacao_Indisponiveis){
	ACOMODACOES Acomodacoes;
		//Cria uma variavel do tipo DADOS HOTEL;

	FILE *Arquivo;
		//Ponteiro para o arquivo
	
	Arquivo=fopen(Url,"r");
		//Abre o Arquivo
	int Contador=0;
	char Temporario[999];

	
	if(Arquivo==NULL){
		Vermelho("O Arquivo não foi aberto corretamente\n");
	}else{
		do{

			fscanf(Arquivo,"%d",&Acomodacoes.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			Acomodacoes_Disponiveis[Contador] = Acomodacoes.Codigo;
			Contador++;
			fscanf(Arquivo,"%[^\n]s",Temporario);
			getc(Arquivo);			
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		
	}
	fclose(Arquivo);
		//Fecha o Arquivo;
	for(int i = 0; i < Contador; i++){
		for(int j = 0; j < Contador_Acomodacao_Indisponiveis; j++){
			if(Acomodacoes_Disponiveis[i] == Acomodacoes_Indisponiveis[j]){
				Acomodacoes_Disponiveis[i] = 0;
			}
		}
	}
	return Contador;
}
void Main_Pesquisa(){
	int Acomodacao_Disponiveis[999] = {0},Acomodacao_Indisponiveis[999] = {0};
	int Contador_Acomodacao_Indisponiveis = 0, Contador_Acomodacao_Disponiveis = 0;
	char Arquivo_Fluxo[999];
	DATA Data_Entrada,Data_Saida,Data;
	do{
		Verde("\nDigite a data referente a Entrada");
		Recebe_Data(&Data_Entrada,1);
		Verde("\nDigite a data referente a Saida");
		Data_Saida.Ano = Data_Entrada.Ano;
		Data_Saida.Mes = Data_Entrada.Mes;		
		Recebe_Data(&Data_Saida,2);
		Data.Dia = Data_Entrada.Dia;
		Data.Mes = Data_Entrada.Mes;
		Data.Ano = Data_Entrada.Ano;
		Data.Dia_Saida = Data_Saida.Dia;
		if(Data.Dia_Saida <Data_Entrada.Dia){
			Vermelho("O dia de entrada não pode ser anterior ao dia de saida");
		}
	}while(Data.Dia_Saida < Data.Dia);
	//Equanto a data de entrada for menor que a data de saida repete o loop
	//Recebe dados da Data
	//PESQUISA Tipo_Pesquisa(); IMPLEMENTAR DPS
	sprintf(Arquivo_Fluxo,"Arquivos/Reserva/");
	Cria_Pasta(Arquivo_Fluxo);
	sprintf(Arquivo_Fluxo,"Arquivos/Reserva/%u",Data_Entrada.Ano);
	printf("%s",Arquivo_Fluxo);
	Cria_Pasta(Arquivo_Fluxo);
	//Cria Pasta	
	system("clear");
	sprintf(Arquivo_Fluxo,"Arquivos/Reserva/%u/%u",Data_Entrada.Ano,Data_Entrada.Mes);
	Verificacao_Arquivo(Arquivo_Fluxo,Arquivo_Binario);
	//Cria arquivo
	if(Arquivo_Binario_Vazio(Arquivo_Fluxo) == 0){
		Contador_Acomodacao_Indisponiveis = Verifica_Fluxo(Arquivo_Fluxo, Data_Entrada, Data_Saida,Acomodacao_Indisponiveis);
		
	}
	if(Configuracoes() == Arquivo_Binario){

	}else if(Configuracoes() == Arquivo_Texto){
		Contador_Acomodacao_Disponiveis = Todas_Acomodacoes_TXT("Arquivos/Acomodacoes.txt", Acomodacao_Disponiveis, Acomodacao_Indisponiveis, Contador_Acomodacao_Indisponiveis);
		Mostra_Acomodacoes_TXT(Contador_Acomodacao_Disponiveis, Acomodacao_Disponiveis, "Arquivos/Acomodacoes.txt");
		Verde("\nDigite 1 para continuar\n");
		PAUSA;
		
		//Mostra todas Acomodacoes Disponiveis da pesquisa
	}
//	Verifica_Fluxo(char Url[999], DATA Data_Entrada,DATA Data_Saida, int Acomodacao_Indisponiveis[]){
		
}
void Mostra_Acomodacoes_TXT(int Contador_Acomodacoes, int Codigos[], char Url[]){
	ACOMODACOES Acomodacoes;
	//Cria uma variavel do tipo DADOS HOTEL;

	FILE *Arquivo;
	//Ponteiro para o arquivo

	Arquivo=fopen(Url,"r");
	//Abre o Arquivo
	int Arquivo_Vazio=0;
	char Temporario[999];
	int Aux=0;

	if(Arquivo==NULL){
		Vermelho("O Arquivo não foi aberto corretamente\n");
	}else{
			
		do{
			fscanf(Arquivo,"%d",&Acomodacoes.Codigo);
			Aux=-1;
			for(int i = 0; i < Contador_Acomodacoes; i++){
				if(Codigos[i] == 0){
					///SE FOR IGUAL A 0 Nao faz nada...
				}else if(Acomodacoes.Codigo == Codigos[i]){
					Aux=i;
					break;
				}
			}
			if(!(Aux == -1)){
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
				getc(Arquivo);
				if(Acomodacoes.Codigo = Codigos[Aux]){
					if(feof(Arquivo)){
						//Verifica se esta no fim do arquivo
						break;
						//Sai do loop
					}
					Verde("\nAcomodacao disponivel\n");
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Acomodacoes.Descricao);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Televisao);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Ar_Condicionado);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Frigobar);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Internet);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes.Facilidades.Banheira);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%d",&Acomodacoes.Cod_Categoria);
						//Expreção Regular
					getc(Arquivo);
					fscanf(Arquivo,"%d",&Acomodacoes.Cod_Hotel);
					//Expreção Regular
					getc(Arquivo);
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caracte (pula o \n)
					Ler_Acomodacoes_Memoria(Acomodacoes);
					
					Arquivo_Vazio++;
				}
			}else{
				if(feof(Arquivo)){
					//Verifica se esta no fim do arquivo
					break;
					//Sai do loop
				}
				fscanf(Arquivo,"%[^\n]s",Temporario);
				//Expreção Regular
				getc(Arquivo);
				Arquivo_Vazio++;
			}
		}while(!feof(Arquivo));
		//Entra no loop se não estiver apontando para o final do arquivo;
	if(Arquivo_Vazio==0){
		Vermelho("O Arquivo está vazio\n");
	}
	PAUSA;
}

fclose(Arquivo);
	//Fecha o Arquivo;
}
int Verifica_Fluxo(char Url[999], DATA Data_Entrada,DATA Data_Saida, int Acomodacao_Indisponiveis[]){
	FLUXO Fluxo;
	FILE *Arquivo;
	int Tamanho_Vetor = Data_Saida.Dia - Data_Entrada.Dia + 1;
	int Contador_Acomodacao_Indisponiveis = 0;
	int Periodo[Tamanho_Vetor];
	for(int i = 0; i < Tamanho_Vetor; i++){
		Periodo[i] = Data_Entrada.Dia + i;
	}
	Arquivo=fopen(Url,"rb");
	while(!feof(Arquivo)){
		fread(&Fluxo, sizeof(FLUXO),1,Arquivo);		
		if(feof(Arquivo)){
			//Verifica se esta no fim do arquivo
			break;
			//Sai do loop
		}
		int Tamanho_Vetor_Fluxo_Lido_Binario = Fluxo.Data_Saida.Dia - Fluxo.Data_Entrada.Dia + 1;
		for(int i = 0; i <Tamanho_Vetor; i++){
			for(int j = 0; j <Tamanho_Vetor_Fluxo_Lido_Binario; j++){
				if(Periodo[i] == Fluxo.Vetor_Dias[j]){
					Acomodacao_Indisponiveis[Contador_Acomodacao_Indisponiveis] = Fluxo.Codigo_Acomodacao;
					Contador_Acomodacao_Indisponiveis++;
					i = Tamanho_Vetor + 1;
					// i recebe o tamanho do vetor somado 1 para sair do for superior
					break;
					//sai do for atual
				}
			}
		}
		//Contador para verificar se o arquivo está em branco
	}
	fclose(Arquivo);
	return Contador_Acomodacao_Indisponiveis;
}
PESQUISA Tipo_Pesquisa(){
	//Retorna em binario o tipo de pesquisa dentro da struct
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
DATA Pesquisa(PESQUISA Pesquisa){
	int Modo_Abertura=Configuracoes();
	int Ok=0;
	int Contador=0;
	int Vetor_Acomodacoes_Invalidas[Tamanho2];
	int Tamanho_Acomodacoes_disponiveis = 0;
	int Acomodacao_Disponiveis[999], Acomodacao_Indisponiveis[9999];
	char Arquivo_Fluxo[999];
	int Contador_Acomodacao_Indisponiveis = 0;
	int Acomodacao_Existentes[999]={0};
	DATA Data;
	if(Pesquisa.Data==1){
		do{
			Verde("\nDigite a data referente a Entrada");
			Recebe_Data(&Pesquisa.Data_Entrada,1);
			Verde("\nDigite a data referente a Saida");
			Pesquisa.Data_Saida.Ano = Pesquisa.Data_Entrada.Ano;
			Pesquisa.Data_Saida.Mes = Pesquisa.Data_Entrada.Mes;		
			Recebe_Data(&Pesquisa.Data_Saida,2);
			Data.Dia = Pesquisa.Data_Entrada.Dia;
			Data.Mes = Pesquisa.Data_Entrada.Mes;
			Data.Ano = Pesquisa.Data_Entrada.Ano;
			Data.Dia_Saida = Pesquisa.Data_Saida.Dia;
			if(Data.Dia_Saida < Pesquisa.Data_Entrada.Dia){
				Vermelho("O dia de entrada não pode ser anterior ao dia de saida");
			}
		}while(Data.Dia_Saida < Pesquisa.Data_Entrada.Dia);
		//Equanto a data de entrada for menor que a data de saida repete o loop
		//Recebe dados da Data
					
		sprintf(Arquivo_Fluxo,"Arquivos/Reserva/");
		Cria_Pasta(Arquivo_Fluxo);
		sprintf(Arquivo_Fluxo,"Arquivos/Reserva/%u",Pesquisa.Data_Entrada.Ano);
		printf("%s",Arquivo_Fluxo);
		Cria_Pasta(Arquivo_Fluxo);
			
		system("clear");
		sprintf(Arquivo_Fluxo,"Arquivos/Reserva/%u/%u",Pesquisa.Data_Entrada.Ano,Pesquisa.Data_Entrada.Mes);
		Verificacao_Arquivo(Arquivo_Fluxo,Arquivo_Binario);
		Contador_Acomodacao_Indisponiveis = Verifica_Fluxo(Arquivo_Fluxo, Pesquisa.Data_Entrada,Pesquisa.Data_Saida, Acomodacao_Indisponiveis);
		//quando chamo a função verifica fluxo eu retorno o contador e o vetor com os codigos das acomodações indisponiveis
	}
	if(Pesquisa.Categoria_Acomodacao==1){
		do{
			printf("Digite a categoria da Acomodação");
			scanf("%d",&Pesquisa.Codigo_Categoria);

			Ok = Valida_Codigo_Acomodacao(Pesquisa.Codigo_Categoria,Modo_Abertura);

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
	
	Todas_Acomodacoes_TXT("Arquivos/Acomodacoes.txt",Acomodacao_Disponiveis,Acomodacao_Indisponiveis,Contador_Acomodacao_Indisponiveis);
	//agora temos que subistituir as acomodações existentes 

return Data;

}



void Pequisa_Quantidade(int Acomodacao_Invalida[],int Inicio_Vetor,int Quantidade){
	
	
	}
	
void Pequisa_Facilidades(int Acomodacao_Invalida[],int Inicio_Vetor){
	
	
	}
	
void Pequisa_Categoria_Acomodacao(int Acomodacao_Invalida[],int Inicio_Vetor){
	
	
	}


int Valida_Codigo_Acomodacao(int Codigo, int Modo_de_Abertura){
	//Procura nas acomodacoes pelo codigo da acomodacao
	FILE *Arquivo;
	char Temporario[9999];
		//Ponteiro para Arquivo
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen("Arquivos/Acomodacoes.txt","r");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Categoria cadastradas\n");
			return 0;
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen("Arquivos/Acomodacoes.bin","rb");
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
		ACOMODACOES Codigo_Categoria;
		Contador1=0;
		//Zera contador de Codigos
		while(!feof(Arquivo)){
			fread(&Codigo_Categoria, sizeof(ACOMODACOES),1,Arquivo);
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

void Recebe_Data(DATA *Data, int Auxiliar){
	if(Auxiliar == 1){
		do{
			printf("\nDigite o Ano ");
			scanf("%u",&Data->Ano);
			if(Data->Ano<2017){
				Vermelho("\nAno invalido");
			}
		}while(Data->Ano<2017);
		do{
			printf("\nDigite o numero referente ao Mes ");
			scanf("%u",&Data->Mes);
			if(Data->Mes<1 || Data->Mes>12){
				Vermelho("\nMes invalido");
			}
		}while(Data->Mes<1 || Data->Mes>12);
	
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
	}else{
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
	
		
}



#endif