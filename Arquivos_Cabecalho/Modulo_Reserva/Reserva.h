#ifndef _Reserva_ 
	//Se não estiver definido entra no if
#define _Reserva_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

	//Inclui arquivos de cabeçalho
/*
int Retorna_Campo_Struct_Reserva(char Url[99], int Codigo);
void Apagar_Modificar_Reserva_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
void Criar_Modificar_Reserva(int Modo_de_Abertura,int Manter_Codigo);
void Gravar_Reserva_Bin(char Url[99],RESERVA *Reserva);
void Gravar_Reserva_Txt(char Url[99],RESERVA *Reserva);
void Ler_Reserva_Bin();
void Ler_Reserva_Memoria(RESERVA Reserva);
void Ler_Reserva_Txt(char Url[99]);
void Main_Reserva(MODO Modo);
int Valida_Acomadacao_Reserva(int Codigo, int Modo_de_Abertura);
void Mostra_Se_Conta_Paga(int Pago);
void Modo_De_Pagamento(int Modo);
int Valida_Hospede_Reserva(int Codigo, int Modo_de_Abertura);
*/
void Ler_Reserva_Memoria(RESERVA Reserva){
	//Recebe por parametro Struct de Reserva
	printf("Codigo:\t\t\t%d\n",Reserva.Codigo);
	printf("Nome Hospede:\t\t%s\n",Reserva.Nome_Hospede);
	printf("Codigo Hospede:\t\t%d\n",Reserva.Codigo_Hospede);
	printf("Codigo Acomodacao\t%d\n",Reserva.Cod_Acomodacao);
	printf("Data de entrada:\t\t\t%s\n",Reserva.Data_Entrada);
	printf("Data de saida:\t\t%s\n",Reserva.Data_Saida);
	printf("Data de vencimento da fatura:\t\t\t%s\n",Reserva.Data_Vencimento_Fatura);
	printf("Valor Fatura:\t\t\tR$%.2f\n",Reserva.Valor_Fatura);
	printf("Pagamento:\t\t\t");
	Mostra_Se_Conta_Paga(Reserva.Pago);
	printf("Valor Conta:\t\tR$%.2f\n",Reserva.Valor_Conta);
	printf("Modo de Pagamento:\t\t");
	Modo_De_Pagamento(Reserva.Modo_Pagamento);
	//Fazer Funcao Para Pegar produtos consumidos
	printf("____________________________________________________\n");
	//Mostra dados do Reserva cadastrado na memoria
}
void Mostra_Se_Conta_Paga(int Pago){
	//Funcao para mostrar se a conta esta paga
	if(Pago == 0){//Se 0 esta pendente
		Vermelho("Pendente\n");//Mostra na tela colorindo de vermelho
	}else{//Se nao pago
		Verde("Pago\n");//Mostra na tela colorindo de verde
	}
}
void Modo_De_Pagamento(int Modo){
	//Funcao para Mostrar o modo de pagamento
	switch(Modo){//Switch para verificar cada caso
		case Especie:
			printf("Dinheiro\n");
		break;
		case Debito:
			printf("Debito\n");
		break;
		case Credito:
			printf("Credio\n");
		break;
		case Cheque:
			printf("Cheque\n");	
		break;
		//Verifica o Caso definido no enum de registro e mostra o modo para o usuario
	}
}
void Gravar_Reserva_Txt(char Url[99],RESERVA *Reserva){
	//Colocar com parametro não " " mas sim ;
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	Arquivo=fopen(Url,"a+");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo
	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}
	fprintf(Arquivo,"%d;",Reserva->Codigo);
	fprintf(Arquivo,"%s;",Reserva->Nome_Hospede);
	fprintf(Arquivo,"%d;",Reserva->Codigo_Hospede);
	fprintf(Arquivo,"%d;",Reserva->Cod_Acomodacao);
	fprintf(Arquivo,"%s;",Reserva->Data_Entrada);
	fprintf(Arquivo,"%s;",Reserva->Data_Saida);
	fprintf(Arquivo,"%s;",Reserva->Data_Vencimento_Fatura);
	fprintf(Arquivo,"%f;",Reserva->Valor_Fatura);
	fprintf(Arquivo,"%d;",Reserva->Pago);
	fprintf(Arquivo,"%f;",Reserva->Valor_Conta);
	fprintf(Arquivo,"%d;",Reserva->Modo_Pagamento);
	//Fazer funcao para salvar produtos no TXT
		//Salva um struct por Linha
	fclose(Arquivo);
		//Fecha o o arquivo para evitar erros
	

	printf("\nArquivo Salvo em : %s",Url);
}
void Ler_Reserva_Txt(char Url[99]){
	RESERVA Reserva;
		//Cria uma variavel do tipo DADOS HOTEL;

	FILE *Arquivo;
		//Ponteiro para o arquivo

	Arquivo=fopen(Url,"r");
		//Abre o Arquivo
	int Arquivo_Vazio=0;

	
	if(Arquivo==NULL){
		Vermelho("O Arquivo não foi aberto corretamente\n");
	}else{
		do{
			fscanf(Arquivo,"%d",&Reserva.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			fscanf(Arquivo,"%[^;]s",Reserva.Nome_Hospede);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
				//Expreção Regular
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%d",&Reserva.Codigo_Hospede);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%d",&Reserva.Cod_Acomodacao);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%[^;]s",Reserva.Data_Entrada);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%[^;]s",Reserva.Data_Saida);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%[^;]s",Reserva.Data_Vencimento_Fatura);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%f",&Reserva.Valor_Fatura);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%d",&Reserva.Pago);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%f",&Reserva.Valor_Conta);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			fscanf(Arquivo,"%d",&Reserva.Modo_Pagamento);
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o ;)
			//FAZER METODO PARA LER MATRIZ NO TXT
			getc(Arquivo);//Pula o Ponteiro para o proximo caracte (pula o \n)
				
			Ler_Reserva_Memoria(Reserva);
			
			Arquivo_Vazio++;
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		if(Arquivo_Vazio==0){
			Vermelho("O Arquivo está vazio\n");
		}
	}

	fclose(Arquivo);
		//Fecha o Arquivo;
}

void Recebe_Dados_Reserva(RESERVA *Reserva){
	int Modo_de_Abertura=0;
	Modo_de_Abertura=Configuracoes();
	printf("\nNome Hospede:");
	scanf("%s",Reserva->Nome_Hospede);
	int Codigo_Hospede_A_Ser_Validado,Codigo_Acomodacao_A_Ser_Validado,Auxiliar=0,Sair_Da_Validacao = 0;
	//Codigos a serem validados
	while(Auxiliar == 0){//Repete loop enquanto auxiliar se mantem no 0
		printf("Codigo do Hospede:");
		scanf("%d",&Codigo_Hospede_A_Ser_Validado);
		//Recebe codida categoria
		if (Valida_Hospede_Reserva(Codigo_Hospede_A_Ser_Validado,Modo_de_Abertura))
		{
			//Chama funcao para validar e ja verifica se retornou verdadeiro 1
			Reserva->Codigo_Hospede = Codigo_Hospede_A_Ser_Validado;
			Auxiliar = 1;			
			//Coloca codigo da categoria na struct e auxiliar recebe 1 para sair do loop sem erros
		}else{
			Vermelho("\nCodigo não cadastrado\n");//Mostra que o codigo nao esta cadastrado
			printf("Deseja sair sem efetuar o cadastro?(1 - Sim | 2 - Não)");
			scanf("%d",&Sair_Da_Validacao);
			//Recebe valor para sair do loop sem efetuar cadastro
			if(Sair_Da_Validacao == 1){
				break;//sai do loop com auxiliar 0 indicando que nao efetuara o cadastro
			}
		}
	}
	if(Auxiliar==1){//Se auxiliar sair como 1 indica que validou
		Auxiliar = 0;//zera auxiliar
		while(Auxiliar == 0){//Loop enquanto auxiliar for 0
			printf("Codigo da Acomodacao:");
			scanf("%d",&Codigo_Acomodacao_A_Ser_Validado);
			//Recebe codigo do hotel a ser validado
			if (Valida_Acomadacao_Reserva(Codigo_Acomodacao_A_Ser_Validado,Modo_de_Abertura))
			{
				//Chamafuncao para validar codigo hotel e ja verifica retorno verdadeiro
				Reserva->Cod_Acomodacao = Codigo_Acomodacao_A_Ser_Validado;	
				Auxiliar = 1;		
				//Joga codigo para struct e auxiliar recebe 1 indicando que validou com sucesso
			}else{
				Vermelho("\nCodigo não cadastrado\n\n");
				printf("Deseja sair sem efetuar o cadastro?(1 - Sim | 2 - Não)");
				scanf("%d",&Sair_Da_Validacao);
				//Caso contrario pergunta se deseja sair sem efetuar cadastro
				if(Sair_Da_Validacao == 1){
					break;//Se verdadeiro sai sem validar auxiliar
				}	
			}
		}
	}
	printf("Data de Entrada:");
	scanf("%s",Reserva->Data_Entrada);
	printf("Data de Saida:");
	scanf("%s",Reserva->Data_Saida);
	printf("Data Vencimento da Fatura:");
	scanf("%s",Reserva->Data_Vencimento_Fatura);
	printf("Valor da Fatura:");
	scanf("%f",&Reserva->Valor_Fatura);
	printf("Digite");
	Verde("\t1 para valor pago");
	Vermelho("\t0 para pendente");
	scanf("%d",&Reserva->Pago);
	printf("1- Pagamento Dinheiro\n"
			"2- Pagamento Debito\n"
			"3- Pagamento Credito\n"
			"4- Pagamento Cheque");
	scanf("%d",&Reserva->Modo_Pagamento);
	//RECEBER DADOS PRODUTOS
	//os outros dados
}

void Main_Reserva(MODO Modo){
	RESERVA Reserva;
	int Acao,Codigo=0;

	Verificacao_Arquivo("Arquivos/Reserva.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Reserva.txt",Arquivo_Texto);
	//Verifica se ja existe os arquivos

	while(1){
		OrdenaValoresTxt();
		Acao = Opcao_Acoes();
		//Retorna um inteiro referente a Ação (Case)
		//limpa a tela
		switch (Acao){
			case Ler:
				if(Modo.Nivel_De_Permissao>=8 && Modo.Nivel_De_Permissao <=15){
					if (Modo.Modo_de_Abertura == Arquivo_Binario)
					{
						Ler_Reserva_Bin("Arquivos/Reserva.bin");
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						Ler_Reserva_Txt("Arquivos/Reserva.txt");
					}
				}else{
					Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;
			case Criar:
				if ((Modo.Nivel_De_Permissao >=4 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=12 && Modo.Nivel_De_Permissao <=15)){
						Criar_Modificar_Reserva(Modo.Modo_de_Abertura,0);	
				}else{
					Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;	

			case Editar:
				if ((Modo.Nivel_De_Permissao >=2 && Modo.Nivel_De_Permissao <=3)||(Modo.Nivel_De_Permissao >=6 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=10 && Modo.Nivel_De_Permissao <=11)||(Modo.Nivel_De_Permissao >=14 && Modo.Nivel_De_Permissao <=15)){
					if(Modo.Modo_de_Abertura == Arquivo_Binario){
						printf("Digite o codigo a ser editado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar_Reserva_Bin("Arquivos/Reserva.bin",Codigo,1,Modo);
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						printf("Digite o codigo a ser editado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar("Arquivos/Reserva.txt",Codigo,1,Modo,Dados_Reserva);
					}
				}else{
					Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;

			case Apagar:
				if ((Modo.Nivel_De_Permissao%2)){//Se for impar retorna 1 e somente numeros impares tem a permissao de Apagar
					if(Modo.Modo_de_Abertura == Arquivo_Binario){
						printf("Digite o codigo a ser apagado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar_Reserva_Bin("Arquivos/Reserva.bin",Codigo,0,Modo);
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						printf("Digite o codigo a ser apagado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar("Arquivos/Reserva.txt",Codigo,0,Modo,Dados_Reserva);
					}
				}else{
					Vermelho("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;
			default:
				return;
				break;
		}
	}
}


void Ler_Reserva_Bin(char Url[99]){
	FILE *Arquivo;
	//Cria ponteiro de arquivo
	RESERVA Reserva;
	Arquivo = fopen(Url,"rb");
	int Arquivo_Vazio=0;
	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}else{
		while(!feof(Arquivo)){
			fread(&Reserva, sizeof(RESERVA),1,Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			Ler_Reserva_Memoria(Reserva);
			Arquivo_Vazio++;
			//Contador para verificar se o arquivo está em branco
		}
		fclose(Arquivo);
		if(Arquivo_Vazio==0){
			Vermelho("O Arquivo está vazio\n");
		}
	}
}



void Gravar_Reserva_Bin(char Url[99],RESERVA *Reserva){
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	
	Arquivo=fopen(Url,"ab");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo

	if(Arquivo == NULL){
		Vermelho("\nNao foi possivel abrir o arquivo!");
	}
	fwrite(Reserva, sizeof(RESERVA), 1, Arquivo); 
   		//Primeiro argumento é um ponteiro .... como proceder

	fclose(Arquivo);
   		//Fecha o Arquivo Para evitar erro
	printf("\nArquivo Salvo 'Reserva.bin'");
   		//Mensagem de Confirmação
}

int Valida_Acomadacao_Reserva(int Codigo, int Modo_de_Abertura){
	//Procura nas acomodacoes pelo codigo da categoria para que assim nao apague os que sao vinculados
	FILE *Arquivo;
	char Temporario[9999];
		//Ponteiro para Arquivo
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen("Arquivos/Acomodacoes.txt","r");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Acomodacoes cadastradas\n");
			return 0;
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen("Arquivos/Acomodacoes.bin","rb");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Acomodacoes cadastradas\n");
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
		ACOMODACOES Tipo_Acomodacoes;
		ACOMODACOES Acomodacoes;
		Contador1=0;
		//Zera contador de Codigos
		while(!feof(Arquivo)){
			fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
			//Le arquivo e passac para a struct
			if(feof(Arquivo)){
				break;
				//Se estiver no fim do arquivo sai do loop
			}

			Vetor_Codigos[Contador1] = Acomodacoes.Codigo;
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
int Valida_Hospede_Reserva(int Codigo, int Modo_de_Abertura){
	//Procura nas acomodacoes pelo codigo da categoria para que assim nao apague os que sao vinculados
	FILE *Arquivo;
	char Temporario[9999];
		//Ponteiro para Arquivo
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen("Arquivos/Hospede.txt","r");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Hospedes cadastradas\n");
			return 0;
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen("Arquivos/Hospede.bin","rb");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Vermelho("Não há Hospedes cadastradas\n");
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
		DADOS_HOSPEDE Hospede;
		Contador1=0;
		//Zera contador de Codigos
		while(!feof(Arquivo)){
			fread(&Hospede, sizeof(DADOS_HOSPEDE),1,Arquivo);
			//Le arquivo e passac para a struct
			if(feof(Arquivo)){
				break;
				//Se estiver no fim do arquivo sai do loop
			}

			Vetor_Codigos[Contador1] = Hospede.Codigo;
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
void Criar_Modificar_Reserva(int Modo_de_Abertura, int Manter_Codigo){
	char Url[99];
	RESERVA Reserva;
		//Variavel Local
		//Obedecendo o principio do privilegio mínimo
		//Usada somente para transição do buffer para o arquivo ou do arquivo para a tela
	switch (Modo_de_Abertura){
		case Arquivo_Texto:
		strcpy(Url,"Arquivos/Reserva.txt");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Reserva.Codigo = Valida_Codigo(Url,15,Arquivo_Texto,Dados_Reserva);
		}else{
			Reserva.Codigo = Manter_Codigo;
		}
		break;

		case Arquivo_Binario:
		strcpy(Url,"Arquivos/Reserva.bin");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Reserva.Codigo = Valida_Codigo(Url,15,Arquivo_Binario,Dados_Reserva);
		}else{
			Reserva.Codigo = Manter_Codigo;
		}
		break;
		case Banco_De_Dados:
			//Não está implementado
		break;
		case Nuvem:
			//Não está implementado
		break;

	}
	Recebe_Dados_Reserva(&Reserva);
	//Mostra Dados de Reserva salvos na struct
	switch(Modo_de_Abertura){			
		case Arquivo_Texto:
			Gravar_Reserva_Txt(Url,&Reserva);
			//Grava em TXT
			break;

		case Arquivo_Binario:
			Gravar_Reserva_Bin(Url,&Reserva);
			//Grava em BIN
			break;

		case Banco_De_Dados:
			Vermelho("Banco de Dados não foi implentado\n");
			break;
		case Nuvem:
			Vermelho("Nuvem não foi implementado\n");
			break;
	}
		//Para Grava o Buffer da String no Arquivo
}


int Retorna_Campo_Struct_Reserva(char Url[99], int Codigo){
	//Funcao para procurar hotel com base no codigo digitado pelo usuario
	FILE *Arquivo;
	MODO Modo;
	Modo = Modo_Bin_ou_Txt(Arquivo_Binario);
	//Ponteiro do tipo File
	char Temporario[9999];
	RESERVA Reserva;
	Arquivo = fopen(Url,Modo.Leitura);
	//Abre o arquivo em modo de leitura
	int Validador = -1, Numero_Structs = 1;
	
	//Armazena o codigo lido no arquivo Bin
	do{
		fread(&Reserva, sizeof(RESERVA),1,Arquivo);
		Validador = Reserva.Codigo;
		if(feof(Arquivo)){
			return -1;
			break;
		}
		if(Validador == Codigo){
			//Verifica se o codigo é igual ao lido
			return Numero_Structs;
			//Retorna a linha que tem o codigo
			break;
			//Confirma se saiu do loop
		}
		Numero_Structs++;
		//Soma no contac
	}while(!feof(Arquivo));
	//Le ate o fim do arquivo
	fclose(Arquivo);
	//Fecha o arquvio
	return -1;
}

void Apagar_Modificar_Reserva_Bin(char Url[99], int Codigo,int Modificar,MODO Modo){
	if(Modo.Modo_de_Abertura == Arquivo_Binario){
		RESERVA Reserva;
		//Cria uma Variavel do tipo Dados_Reserva
		FILE *Arquivo, *Arquivo_Temporario;
		//Cria 2ponteiros do tipo FILE
		Arquivo=fopen(Url,Modo.Leitura);
		//Abre o aqruivo principal em modo leitura
		Arquivo_Temporario = fopen("Arquivos/Temp",Modo.Concatenacao);
		//Abre o arquivo que sera apagado em modo de concatenacao
		int Campo_Struct = Retorna_Campo_Struct_Reserva(Url, Codigo);
		//Variavel Campo_Struct recebe quantas structs teve que pular para achar o codigo
		if(Campo_Struct == -1){//Se for retornado -1 mostra que nao foi encotrado o codigo digitado
			Vermelho("O codigo digitado não foi encontrado");
		}else{
			if(Confirmacao()){//Se a confirmacao retornar 1 
				for(int i=1;i<Campo_Struct;i++){
					//Vai ate o campo do codigo
					fread(&Reserva, sizeof(RESERVA),1,Arquivo);
					fwrite(&Reserva, sizeof(RESERVA),1,Arquivo_Temporario); 
					//Escreve no Arquivo temporario
				}

				fread(&Reserva, sizeof(RESERVA),1,Arquivo); 
				//Le o arquivo Arquivo Binario e passa dados para struct
				if(Modificar==1){
					//Entra no modo Editar
					Criar_Modificar_Reserva(Arquivo_Binario, Codigo);
					//Chama a funcao para editar o arquivo
					Verde("\nEditado com Sucesso");
					system("clear");
					//Limpa tela
				}
				//Se nao entrar no if so apaga o dado
				while(!feof(Arquivo)){
					//Vai ate o Final do Arquivo
					fread(&Reserva, sizeof(RESERVA),1,Arquivo);
					if(feof(Arquivo)){
						//Sai caso esteja no fim do arquivo;
						break;
					}
					fwrite(&Reserva, sizeof(RESERVA),1,Arquivo_Temporario); 
						//Printa no Arquivo Temporario
				}
				fclose(Arquivo_Temporario);
				fclose(Arquivo);
					//Fecha ambos os Arquivos
				remove(Url);
					//Remove o Arquivo Original
				rename("Arquivos/Temp",Url);
					//Renomeia o Arquivo
				if(Modificar==0){
					Verde("\nExcluído com Sucesso");
					//Mostra que foi apagado com sucesso
				}
			}
		}
	}
}

/*
#ifdef Debug
printf("");
#endif
*/

#endif

