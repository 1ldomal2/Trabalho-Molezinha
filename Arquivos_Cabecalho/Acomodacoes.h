#ifndef _Acomodacoes_ 
	//Se não estiver definido entra no if
#define _Acomodacoes_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

	//Inclui arquivos de cabeçalho
/*
void Ler_Acomodacoes_Txt(char Url[99]);
void Ler_Acomodacoes_Bin();
void Ler_Acomodacoes_Memoria(ACOMODACOES Acomodacoes);
void Recebe_Dados_Acomodacoes(ACOMODACOES *Acomodacoes, int Modo_de_Abertura)
void Gravar_Acomodacoes_Txt(char Url[99],ACOMODACOES *Acomodacoes);
void Gravar_Acomodacoes_Bin(char Url[99],ACOMODACOES *Acomodacoes);
void Criar_Modificar_Acomodacoes(int Modo_de_Abertura,int Manter_Codigo);
int Retorna_Campo_Struct_Acomodacoes(char Url[99], int Codigo);
void Apagar_Modificar_Acomodacoes_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
ACOMODACOES Retorna_Struct_Acomodacoes_Grava_Memoria(ACOMODACOES *Acomodacoes);
*/
void Main_Acomodacoes(MODO Modo){
	ACOMODACOES Acomodacoes;
	int Acao,Codigo=0;

	Verificacao_Arquivo("Arquivos/Acomodacoes.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Acomodacoes.txt",Arquivo_Texto);
	
	while(1){

		Acao = Opcao_Acoes();
		//Retorna um inteiro referente a Ação (Case)
		//limpa a tela

		switch (Acao){
			case Ler:
			if(Modo.Nivel_De_Permissao>=8 && Modo.Nivel_De_Permissao <=15){
				if (Modo.Modo_de_Abertura == Arquivo_Binario)
				{
					Ler_Acomodacoes_Bin("Arquivos/Acomodacoes.bin");
				}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
					Ler_Acomodacoes_Txt("Arquivos/Acomodacoes.txt");
				}else if(Modo.Modo_de_Abertura==Memoria){
					if(Acomodacoes.Codigo == 1){
						Ler_Acomodacoes_Memoria(Acomodacoes);
					}else{
						printf("Não existe nenhum dado na memória");
					}
				}
			}else{
					printf("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;

			case Criar:
				if ((Modo.Nivel_De_Permissao >=4 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=12 && Modo.Nivel_De_Permissao <=15)){
					if(Modo.Modo_de_Abertura == Memoria){
						printf("!!!ATENÇÂO!!!\n"
						"Se existir algum dado na mémoria será peridido, so é possivel salvar 1 dado por vez na memoria\n");
						if(Confirmacao()){
							Retorna_Struct_Acomodacoes_Grava_Memoria(&Acomodacoes,Modo.Modo_de_Abertura);
							printf("Salvo com sucesso na memória");
						}
						
						break;
					}else{
						Criar_Modificar_Acomodacoes(Modo.Modo_de_Abertura,0);	
					}
				}else{
					printf("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;	

			case Editar:
			if ((Modo.Nivel_De_Permissao >=2 && Modo.Nivel_De_Permissao <=3)||(Modo.Nivel_De_Permissao >=6 && Modo.Nivel_De_Permissao <=7)||(Modo.Nivel_De_Permissao >=10 && Modo.Nivel_De_Permissao <=11)||(Modo.Nivel_De_Permissao >=14 && Modo.Nivel_De_Permissao <=15)){
				if(Modo.Modo_de_Abertura == Arquivo_Binario){
					printf("Digite o codigo a ser editado: ");
					scanf("%d",&Codigo);
					Apagar_Modificar_Acomodacoes_Bin("Arquivos/Acomodacoes.bin",Codigo,1,Modo);
				}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
					printf("Digite o codigo a ser editado: ");
					scanf("%d",&Codigo);
					Apagar_Modificar("Arquivos/Acomodacoes.txt",Codigo,1,Modo,Dados_Acomodacoes);
				}
			}else{
					printf("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
				}
				break;

			case Apagar:
				if ((Modo.Nivel_De_Permissao%2)){//Se for impar retorna 1 e somente numeros impares tem a permissao de Apagar

					if(Modo.Modo_de_Abertura == Arquivo_Binario){
						printf("Digite o codigo a ser apagado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar_Acomodacoes_Bin("Arquivos/Acomodacoes.bin",Codigo,0,Modo);
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						printf("Digite o codigo a ser apagado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar("Arquivos/Acomodacoes.txt",Codigo,0,Modo,Dados_Acomodacoes);
					}
					
				}else{
						printf("O Usuario não tem o nivel de permissão adequado para realizar esta ação.");
					}
				break;

			default:
				return;
				break;
		}
	}
}
void Ler_Acomodacoes_Txt(char Url[99]){
	ACOMODACOES Acomodacoes;
		//Cria uma variavel do tipo DADOS HOTEL;

	FILE *Arquivo;
		//Ponteiro para o arquivo

	Arquivo=fopen(Url,"r");
		//Abre o Arquivo
	int Arquivo_Vazio=0;

	
	if(Arquivo==NULL){
		printf("O Arquivo não foi aberto corretamente\n");
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
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caracte (pula o \n)
			Ler_Acomodacoes_Memoria(Acomodacoes);
			
			Arquivo_Vazio++;
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		if(Arquivo_Vazio==0){
			printf("O Arquivo está vazio\n");
		}
	}

	fclose(Arquivo);
		//Fecha o Arquivo;
}

void Ler_Acomodacoes_Memoria(ACOMODACOES Acomodacoes){
	//Recebe por parametro Struct de Acomodacoes
	printf("Codigo:\t\t%d\n",Acomodacoes.Codigo);
	printf("Descricao:\t%s\n",Acomodacoes.Descricao);
	printf("Televisao \t%d\n",Acomodacoes.Facilidades.Televisao);
	printf("Ar Condicionado 	%d\n",Acomodacoes.Facilidades.Ar_Condicionado);
	printf("Frigobar\t%d\n",Acomodacoes.Facilidades.Frigobar);
	printf("Banheira\t%d\n",Acomodacoes.Facilidades.Banheira);
	printf("Internet\t%d\n",Acomodacoes.Facilidades.Internet);
	printf("Cod_Categoria:\t%d\n",Acomodacoes.Cod_Categoria);
	printf("____________________________________________________\n");
	//Mostra dados do Acomodacoes cadastrado na memoria
}

void Ler_Acomodacoes_Bin(char Url[99]){
	FILE *Arquivo;
	//Cria ponteiro de arquivo
	ACOMODACOES Acomodacoes;
	Arquivo = fopen(Url,"rb");
	int Arquivo_Vazio=0;
	if(Arquivo == NULL){
		printf("\nNao foi possivel abrir o arquivo!");
	}else{
		while(!feof(Arquivo)){
			fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			Ler_Acomodacoes_Memoria(Acomodacoes);
			Arquivo_Vazio++;
			//Contador para verificar se o arquivo está em branco
		}
		fclose(Arquivo);
		if(Arquivo_Vazio==0){
			printf("O Arquivo está vazio\n");
		}
	}
}

void Gravar_Acomodacoes_Txt(char Url[99],ACOMODACOES *Acomodacoes){
	//Colocar com parametro não " " mas sim ;
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	Arquivo=fopen(Url,"a+");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo
	if(Arquivo == NULL){
		printf("\nNao foi possivel abrir o arquivo!");
	}
	
	printf("%d\n",Acomodacoes->Cod_Categoria);

	if(Acomodacoes->Cod_Categoria==0){
		printf("Erro\n");
	}else{
		fprintf(Arquivo,"%d;",Acomodacoes->Codigo);
		fprintf(Arquivo,"%s;",Acomodacoes->Descricao);
		fprintf(Arquivo,"%d;",Acomodacoes->Facilidades.Televisao);
		fprintf(Arquivo,"%d;",Acomodacoes->Facilidades.Ar_Condicionado);
		fprintf(Arquivo,"%d;",Acomodacoes->Facilidades.Frigobar);
		fprintf(Arquivo,"%d;",Acomodacoes->Facilidades.Internet);
		fprintf(Arquivo,"%d;",Acomodacoes->Facilidades.Banheira);
		fprintf(Arquivo,"%d;\n",Acomodacoes->Cod_Categoria);
			//Salva um struct por Linha

		fclose(Arquivo);
			//Fecha o o arquivo para evitar erros
		

		printf("\nArquivo Salvo em : %s",Url);
	}
}


void Gravar_Acomodacoes_Bin(char Url[99],ACOMODACOES *Acomodacoes){
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	
	Arquivo=fopen(Url,"ab");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo

	if(Arquivo == NULL){
		printf("\nNao foi possivel abrir o arquivo!");
	}
	fwrite(Acomodacoes, sizeof(ACOMODACOES), 1, Arquivo); 
   		//Primeiro argumento é um ponteiro .... como proceder

	fclose(Arquivo);
   		//Fecha o Arquivo Para evitar erro
	printf("\nArquivo Salvo 'Acomodacoes.bin'");
   		//Mensagem de Confirmação
}
void Recebe_Dados_Acomodacoes(ACOMODACOES *Acomodacoes, int Modo_de_Abertura){
	printf("Descrição:");
	scanf("%s",Acomodacoes->Descricao);
	printf("Televisao:");
	scanf("%d",&Acomodacoes->Facilidades.Televisao);
	printf("Ar Condicionado:");
	scanf("%d",&Acomodacoes->Facilidades.Ar_Condicionado);
	printf("Frigobar:");
	scanf("%d",&Acomodacoes->Facilidades.Frigobar);
	printf("Internet:");
	scanf("%d",&Acomodacoes->Facilidades.Internet);
	printf("Banheira:");
	scanf("%d",&Acomodacoes->Facilidades.Banheira);
	int Codigo_Categoria_A_Ser_Validado,Auxiliar=0;

	while(Auxiliar == 0){
		printf("Cod_Categoria:");
		scanf("%d",&Codigo_Categoria_A_Ser_Validado);
		if (Valida_Codigo_Categoria_Acomodacoes(Codigo_Categoria_A_Ser_Validado,Modo_de_Abertura))
		{
			Auxiliar = 1;
		}else{
			printf("\nCodigo não cadastrado\n\n");
		}
	}
	Acomodacoes->Cod_Categoria = Codigo_Categoria_A_Ser_Validado;
}

int Valida_Codigo_Categoria_Acomodacoes(int Codigo, int Modo_de_Abertura){

	FILE *Arquivo;
	char Temporario[9999];
		//Ponteiro para Arquivo
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen("Arquivos/Acomodacoes.txt","r");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			printf("Não há categorias cadastradas\n");
			return -1;
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen("Arquivos/Acomodacoes.bin","rb");
			//Abre o Arquivo em Modo Leitura
		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			printf("Não há categorias cadastradas\n");
			return -1;		
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
		Contador1=0;
		//Zera contador de Codigos
		while(!feof(Arquivo)){
			fread(&Tipo_Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
			//Le arquivo e passac para a struct
			if(feof(Arquivo)){
				break;
				//Se estiver no fim do arquivo sai do loop
			}

			Vetor_Codigos[Contador1] = Tipo_Acomodacoes.Cod_Categoria;
			Contador1++;
			//Soma no contador de contador
		}
	}

	Quick_Sort(Vetor_Codigos,0,Contador1);
		//Ordena o Vetor;
		for (int i = 0; i < Contador1; ++i)
		{
			if (Codigo == Vetor_Codigos[i])
			{
				return 1;
			}
		}
		return 0;
}

ACOMODACOES Retorna_Struct_Acomodacoes_Grava_Memoria(ACOMODACOES *Acomodacoes,int Modo_de_Abertura){
	//Metodo do tipo Dados_Hotel e recebe por parametro ponteiro de Dados de Hotel
	Acomodacoes->Codigo = 1;
	//Como salva so 1 dado na memoria coloca como codigo 1
	Recebe_Dados_Acomodacoes(Acomodacoes,Modo_de_Abertura);
	return *Acomodacoes;
	//Retorna ponteiro de hotel
}


void Criar_Modificar_Acomodacoes(int Modo_de_Abertura, int Manter_Codigo){
	char Url[99];

	ACOMODACOES Acomodacoes;
		//Variavel Local
		//Obedecendo o principio do privilegio mínimo
		//Usada somente para transição do buffer para o arquivo ou do arquivo para a tela

	switch (Modo_de_Abertura){

		case Arquivo_Texto:

			strcpy(Url,"Arquivos/Acomodacoes.txt");
			 //Coloca o caminho na URL

			if (Manter_Codigo == 0)
			{
				Acomodacoes.Codigo = Valida_Codigo(Url,15,Arquivo_Texto,Dados_Acomodacoes);
			}else{
				Acomodacoes.Codigo = Manter_Codigo;
			}
			break;

		case Arquivo_Binario:

			strcpy(Url,"Arquivos/Acomodacoes.bin");
			 //Coloca o caminho na URL

			if (Manter_Codigo == 0)
			{
				Acomodacoes.Codigo = Valida_Codigo(Url,15,Arquivo_Binario,Dados_Acomodacoes);
			}else{
				Acomodacoes.Codigo = Manter_Codigo;
			}
			break;

		case Banco_De_Dados:
			//Não está implementado
			break;

		case Nuvem:
			//Não está implementado
			break;

	}
	Recebe_Dados_Acomodacoes(&Acomodacoes,Modo_de_Abertura);

	switch(Modo_de_Abertura){			
		case Arquivo_Texto:
			Gravar_Acomodacoes_Txt(Url,&Acomodacoes);
			//Grava em TXT
			break;

		case Arquivo_Binario:
			Gravar_Acomodacoes_Bin(Url,&Acomodacoes);
			//Grava em BIN
			break;

		case Banco_De_Dados:
			printf("Banco de Dados não foi implentado\n");
			break;
		case Nuvem:
			printf("Nuvem não foi implementado\n");
			break;
	}
		//Para Grava o Buffer da String no Arquivo
}


int Retorna_Campo_Struct_Acomodacoes(char Url[99], int Codigo){
	//Funcao para procurar hotel com base no codigo digitado pelo usuario
	FILE *Arquivo;
	MODO Modo;
	Modo = Modo_Bin_ou_Txt(Arquivo_Binario);
	//Ponteiro do tipo File
	char Temporario[9999];
 	ACOMODACOES Acomodacoes;
	Arquivo = fopen(Url,Modo.Leitura);
	//Abre o arquivo em modo de leitura
	int Validador = -1, Numero_Structs = 1;
	
	//Armazena o codigo lido no arquivo Bin
	do{
		fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
		Validador = Acomodacoes.Codigo;
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

void Apagar_Modificar_Acomodacoes_Bin(char Url[99], int Codigo,int Modificar,MODO Modo){
	if(Modo.Modo_de_Abertura == Arquivo_Binario){
		ACOMODACOES Acomodacoes;
		//Cria uma Variavel do tipo Dados_Acomodacoes
		FILE *Arquivo, *Arquivo_Temporario;
		//Cria 2ponteiros do tipo FILE
		Arquivo=fopen(Url,Modo.Leitura);
		//Abre o aqruivo principal em modo leitura
		Arquivo_Temporario = fopen("Arquivos/Temp",Modo.Concatenacao);
		//Abre o arquivo que sera apagado em modo de concatenacao
		int Campo_Struct = Retorna_Campo_Struct_Acomodacoes(Url, Codigo);
		//Variavel Campo_Struct recebe quantas structs teve que pular para achar o codigo
		if(Campo_Struct == -1){//Se for retornado -1 mostra que nao foi encotrado o codigo digitado
			printf("O codigo digitado não foi encontrado");
		}else{
			if(Confirmacao()){//Se a confirmacao retornar 1 
				for(int i=1;i<Campo_Struct;i++){
					//Vai ate o campo do codigo
					fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
					fwrite(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo_Temporario); 
					//Escreve no Arquivo temporario
				}

				fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo); 
				//Le o arquivo Arquivo Binario e passa dados para struct
				if(Modificar==1){
					//Entra no modo Editar
					Criar_Modificar_Acomodacoes(Arquivo_Binario, Codigo);
					//Chama a funcao para editar o arquivo
					printf("\nEditado com Sucesso");
					system("clear");
					//Limpa tela
				}
				//Se nao entrar no if so apaga o dado
				while(!feof(Arquivo)){
					//Vai ate o Final do Arquivo
					fread(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
					if(feof(Arquivo)){
						//Sai caso esteja no fim do arquivo;
						break;
					}
					fwrite(&Acomodacoes, sizeof(ACOMODACOES),1,Arquivo_Temporario); 
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
					printf("\nExcluído com Sucesso");
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

