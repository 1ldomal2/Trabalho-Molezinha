#ifndef _Produtos_ 
	//Se não estiver definido entra no if
#define _Produtos_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

	//Inclui arquivos de cabeçalho
/*
void Ler_Produtos_Txt(char Url[99]);
void Ler_Produtos_Bin();
void Ler_Produtos_Memoria(PRODUTOS Produtos);
void Gravar_Produtos_Txt(char Url[99],PRODUTOS *Produtos);
void Gravar_Produtos_Bin(char Url[99],PRODUTOS *Produtos);
void Criar_Modificar_Produtos(int Modo_de_Abertura,int Manter_Codigo);
int Retorna_Campo_Struct_Produtos(char Url[99], int Codigo);
void Apagar_Modificar_Produtos_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
PRODUTOS Retorna_Struct_Produtos_Grava_Memoria(PRODUTOS *Produtos);
*/
void Main_Produtos(MODO Modo){
	OrdenaValoresTxt();
	PRODUTOS Produtos;
	
	int Acao,Codigo=0;
	Verificacao_Arquivo("Arquivos/Produtos.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Produtos.txt",Arquivo_Texto);
	
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
						Ler_Produtos_Bin("Arquivos/Produtos.bin");
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						Ler_Produtos_Txt("Arquivos/Produtos.txt");
					}else if(Modo.Modo_de_Abertura==Memoria){
						if(Produtos.Codigo == 1){
							Ler_Produtos_Memoria(Produtos);
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
							Retorna_Struct_Produtos_Grava_Memoria(&Produtos);
							printf("Salvo com sucesso na memória");
						}
						
						break;
					}else{
						Criar_Modificar_Produtos(Modo.Modo_de_Abertura,0);	
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
						Apagar_Modificar_Produtos_Bin("Arquivos/Produtos.bin",Codigo,1,Modo);
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						printf("Digite o codigo a ser editado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar("Arquivos/Produtos.txt",Codigo,1,Modo,Dados_Produtos);
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
						Apagar_Modificar_Produtos_Bin("Arquivos/Produtos.bin",Codigo,0,Modo);
					}else if(Modo.Modo_de_Abertura == Arquivo_Texto){
						printf("Digite o codigo a ser apagado: ");
						scanf("%d",&Codigo);
						Apagar_Modificar("Arquivos/Produtos.txt",Codigo,0,Modo,Dados_Produtos);
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
void Ler_Produtos_Txt(char Url[99]){
	PRODUTOS Produtos;
		//Cria uma variavel do tipo DADOS Produtos;

	FILE *Arquivo;
		//Ponteiro para o arquivo

	Arquivo=fopen(Url,"r");
		//Abre o Arquivo
	int Arquivo_Vazio=0;

	
	if(Arquivo==NULL){
		printf("O Arquivo não foi aberto corretamente\n");
	}else{
		do{
			fscanf(Arquivo,"%d",&Produtos.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%u",&Produtos.Estoque);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%u",&Produtos.Estoque_Minimo);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Produtos.Descricao);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%f",&Produtos.Preco_Custo);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%f",&Produtos.Preco_Venda);
				//Expreção Regular
			getc(Arquivo);
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caracte (pula o \n)
			Ler_Produtos_Memoria(Produtos);
			
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

void Ler_Produtos_Memoria(PRODUTOS Produtos){
	//Recebe por parametro Struct de Produtos
	printf("Codigo:\t\t\t%d\n",Produtos.Codigo);
	printf("Estoque:\t\t%u\n",Produtos.Estoque);
	printf("Estoque Mínimo:\t\t%u\n",Produtos.Estoque_Minimo);
	printf("Descrição:\t\t%s\n",Produtos.Descricao);
	printf("Preço de Custo:\t\tR$%.2f\n",Produtos.Preco_Custo);
	printf("Preço de Venda:\t\tR$%.2f\n",Produtos.Preco_Venda);
	printf("____________________________________________________\n");
	//Mostra dados do Produtos cadastrado na memoria
}

void Ler_Produtos_Bin(char Url[99]){
	FILE *Arquivo;
	//Cria ponteiro de arquivo
	PRODUTOS Produtos;
	Arquivo = fopen(Url,"rb");
	int Arquivo_Vazio=0;
	if(Arquivo == NULL){
		printf("\nNao foi possivel abrir o arquivo!");
	}else{
		while(!feof(Arquivo)){
			fread(&Produtos, sizeof(PRODUTOS),1,Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			Ler_Produtos_Memoria(Produtos);
			Arquivo_Vazio++;
			//Contador para verificar se o arquivo está em branco
		}
		fclose(Arquivo);
		if(Arquivo_Vazio==0){
			printf("O Arquivo está vazio\n");
		}
	}
}

void Gravar_Produtos_Txt(char Url[99],PRODUTOS *Produtos){
	//Colocar com parametro não " " mas sim ;
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	Arquivo=fopen(Url,"a+");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo
	if(Arquivo == NULL){
		printf("\nNao foi possivel abrir o arquivo!");
	}
	fprintf(Arquivo,"%d;",Produtos->Codigo);
	fprintf(Arquivo,"%u;",Produtos->Estoque);
	fprintf(Arquivo,"%u;",Produtos->Estoque_Minimo);
	fprintf(Arquivo,"%s;",Produtos->Descricao);
	fprintf(Arquivo,"%.2f;",Produtos->Preco_Custo);
	fprintf(Arquivo,"%.2f;",Produtos->Preco_Venda);
		//Salva um struct por Linha

	fclose(Arquivo);
		//Fecha o o arquivo para evitar erros
	

	printf("\nArquivo Salvo em : %s",Url);
}


void Gravar_Produtos_Bin(char Url[99],PRODUTOS *Produtos){
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	
	Arquivo=fopen(Url,"ab");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo

	if(Arquivo == NULL){
		printf("\nNao foi possivel abrir o arquivo!");
	}
	fwrite(Produtos, sizeof(PRODUTOS), 1, Arquivo); 
   		//Primeiro argumento é um ponteiro .... como proceder

	fclose(Arquivo);
   		//Fecha o Arquivo Para evitar erro
	printf("\nArquivo Salvo 'Produtos.bin'");
   		//Mensagem de Confirmação
}
void Recebe_PRODUTOS(PRODUTOS *Produtos){
	printf("\nEstoque:");
	scanf("%u",&Produtos->Estoque);
	printf("Estoque Minimo:");
	scanf("%u",&Produtos->Estoque_Minimo);
	printf("Descrição:");
	scanf("%s",Produtos->Descricao);
	printf("Preço de Custo:R$");
	scanf("%f",&Produtos->Preco_Custo);
	printf("Preço de Venda:R$");
	scanf("%f",&Produtos->Preco_Venda);
	//Le os outros dados
}

PRODUTOS Retorna_Struct_Produtos_Grava_Memoria(PRODUTOS *Produtos){
	//Metodo do tipo PRODUTOS e recebe por parametro ponteiro de Dados de Produtos
	Produtos->Codigo = 1;
	//Como salva so 1 dado na memoria coloca como codigo 1
	Recebe_PRODUTOS(Produtos);
	return *Produtos;
	//Retorna ponteiro de hotel
}

void Criar_Modificar_Produtos(int Modo_de_Abertura, int Manter_Codigo){
	char Url[99];
	PRODUTOS Produtos;
		//Variavel Local
		//Obedecendo o principio do privilegio mínimo
		//Usada somente para transição do buffer para o arquivo ou do arquivo para a tela
	switch (Modo_de_Abertura){
		case Arquivo_Texto:
		strcpy(Url,"Arquivos/Produtos.txt");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Produtos.Codigo = Valida_Codigo(Url,15,Arquivo_Texto,Dados_Produtos);
		}else{
			Produtos.Codigo = Manter_Codigo;
		}
		break;

		case Arquivo_Binario:
		strcpy(Url,"Arquivos/Produtos.bin");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Produtos.Codigo = Valida_Codigo(Url,15,Arquivo_Binario,Dados_Produtos);
		}else{
			Produtos.Codigo = Manter_Codigo;
		}
		break;
		case Banco_De_Dados:
			//Não está implementado
		break;
		case Nuvem:
			//Não está implementado
		break;

	}
	Recebe_PRODUTOS(&Produtos);
	//Mostra Dados de Produtos salvos na struct
	switch(Modo_de_Abertura){			
		case Arquivo_Texto:
			Gravar_Produtos_Txt(Url,&Produtos);
			//Grava em TXT
			break;

		case Arquivo_Binario:
			Gravar_Produtos_Bin(Url,&Produtos);
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


int Retorna_Campo_Struct_Produtos(char Url[99], int Codigo){
	//Funcao para procurar hotel com base no codigo digitado pelo usuario
	FILE *Arquivo;
	MODO Modo;
	Modo = Modo_Bin_ou_Txt(Arquivo_Binario);
	//Ponteiro do tipo File
	char Temporario[9999];
	PRODUTOS Produtos;
	Arquivo = fopen(Url,Modo.Leitura);
	//Abre o arquivo em modo de leitura
	int Validador = -1, Numero_Structs = 1;
	
	//Armazena o codigo lido no arquivo Bin
	do{
		fread(&Produtos, sizeof(PRODUTOS),1,Arquivo);
		Validador = Produtos.Codigo;
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

void Apagar_Modificar_Produtos_Bin(char Url[99], int Codigo,int Modificar,MODO Modo){
	if(Modo.Modo_de_Abertura == Arquivo_Binario){
		PRODUTOS Produtos;
		//Cria uma Variavel do tipo PRODUTOS
		FILE *Arquivo, *Arquivo_Temporario;
		//Cria 2ponteiros do tipo FILE
		Arquivo=fopen(Url,Modo.Leitura);
		//Abre o aqruivo principal em modo leitura
		Arquivo_Temporario = fopen("Arquivos/Temp",Modo.Concatenacao);
		//Abre o arquivo que sera apagado em modo de concatenacao
		int Campo_Struct = Retorna_Campo_Struct_Produtos(Url, Codigo);
		//Variavel Campo_Struct recebe quantas structs teve que pular para achar o codigo
		if(Campo_Struct == -1){//Se for retornado -1 mostra que nao foi encotrado o codigo digitado
			printf("O codigo digitado não foi encontrado");
		}else{
			if(Confirmacao()){//Se a confirmacao retornar 1 
				for(int i=1;i<Campo_Struct;i++){
					//Vai ate o campo do codigo
					fread(&Produtos, sizeof(PRODUTOS),1,Arquivo);
					fwrite(&Produtos, sizeof(PRODUTOS),1,Arquivo_Temporario); 
					//Escreve no Arquivo temporario
				}

				fread(&Produtos, sizeof(PRODUTOS),1,Arquivo); 
				//Le o arquivo Arquivo Binario e passa dados para struct
				if(Modificar==1){
					//Entra no modo Editar
					Criar_Modificar_Produtos(Arquivo_Binario, Codigo);
					//Chama a funcao para editar o arquivo
					printf("\nEditado com Sucesso");
					system("clear");
					//Limpa tela
				}
				//Se nao entrar no if so apaga o dado
				while(!feof(Arquivo)){
					//Vai ate o Final do Arquivo
					fread(&Produtos, sizeof(PRODUTOS),1,Arquivo);
					if(feof(Arquivo)){
						//Sai caso esteja no fim do arquivo;
						break;
					}
					fwrite(&Produtos, sizeof(PRODUTOS),1,Arquivo_Temporario); 
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

