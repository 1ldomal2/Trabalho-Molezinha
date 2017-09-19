//#define Debug
/*
Falta fazer :
			
*/
#ifndef _Funcoes_ 
	//Se não estiver definido entra no if
#define _Funcoes_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Registros.h"
#include "Prototipos.h"
	//Inclui arquivos de cabeçalho

//Prototipos de Função
/*
void Apagar_Modificar(char Url[99], int Codigo,int Modificar);
int Confirmacao();
int Intervalo_Vetor(int Vetor[],int Ultimo);
int Modo_Manipulacao();
void Quick_Sort(int vetor[], int inicio, int fim);
int Retorna_Linha_Codigo(char Url[99], int Codigo);
int Valida_Codigo(char Url[99],int Numero_De_Registros,int Modo_de_Abertura);
void Verificacao_Arquivo(char Url[99],int Modo_de_Abertura);
*/

//Funçoes
int Opcao_Acoes(){
	int Acao;
	printf("\nDigite:"
			"\n\t1\tPara Ler"
			"\n\t2\tPara Criar"
			"\n\t3\tPara Editar"
			"\n\t4\tPara Apagar"
			"\n\t?\tSair\n\t");
		scanf("%d",&Acao);

		system("clear");
	return Acao;
}

int Main_All(){
	int Registro = 0;
	do{
		printf("\nDigite:"
			"\n\t1\tPara Hotel"
			"\n\t2\tPara Hospedes"
			"\n\t3\tPara Acomodações"
			"\n\t4\tPara Categoria"
			"\n\t5\tPara Produtos"
			"\n\t6\tPara Fornecedores"
			"\n\t7\tPara Funcionários"
			"\n\t0\tSair\n\t");
		scanf("%d",&Registro);
		if (Registro <0 || Registro > 7)
		{
			if (Registro == 666)
			{
				system("clear");
				printf(""
"             ____________________________________________________\n"
"            /                                                    \\\n"
"           |    _____________________________________________     |\n"
"           |   |                                             |    |\n"
"           |   |  C:\\>Mint < Ubunto                          |    |\n"
"           |   |                                             |    |\n"
"           |   |                                             |    |\n"
"           |   |                                             |    |\n"
"           |   |                                             |    |\n"
"           |   |                                             |    |\n"
"           |   |                                             |    |\n"
"           |   |                                             |    |\n"
"           |   |                                             |    |\n"
"           |   |                   #Da 50 Manuel             |    |\n"
"           |   |_____________________________________________|    |\n"
"           |                                                      |\n"
"            \\_____________________________________________________/\n"
"                   \\_______________________________________/\n"
"                _______________________________________________\n"
"             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n"
"          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n"
"       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n"
"    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n"
" _-'.-.-.-.-.-. .---.-. .-----------------------------. .-.---. .---.-.-.-.`-_\n"
":-----------------------------------------------------------------------------:\n"
"`---._.-----------------------------------------------------------------._.---'\n");

			}else{
				printf("Digite uma opção válida\n");
			}
		}
	}while(Registro <0 || Registro > 7);
	system("clear");
	return Registro;
}
void Apagar_Modificar(char Url[99], int Codigo,int Modificar,MODO Modo,int Registro){
	int Linha = Retorna_Linha_Codigo(Url,Codigo);
		//Retorna qual linha deve ser apagada
	if(Linha == -1){
		//Caso o codigo nãp esteja presente dentro do arquivo
		printf("Codigo inexistente");
	}else{
		if(Confirmacao()){
			char Temporario[9999];
					//Somente é declara para alocação do ponteiro dentro do arquivo		
			FILE *Arquivo, *Arquivo_Temporario;
					//Ponteiros para Arquivos
			Arquivo = fopen(Url,Modo.Leitura);
					//Abre em modo Leitura
			Arquivo_Temporario = fopen("Arquivos/Temp",Modo.Concatenacao);
					//Abre para Editar

			for(int i=1;i<Linha;i++){
					//Vai ate a linha do codigo
				fscanf(Arquivo,"%[^\n]s",Temporario);
				fprintf(Arquivo_Temporario,"%s\n",Temporario);
				getc(Arquivo);
			}

			fscanf(Arquivo,"%[^;]s",Temporario);
				//Pula a Linha do Codigo

			if(Modificar==1){
					//Se for 1 a função serve para modificar caso contraria apenas apaga
					//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1!!!!!!!!!!!!!!!!!!SWITCH GRANDAO
				switch(Registro){
					case Dados_Hotel:
						Criar_Modificar_Hotel(Arquivo_Texto, Codigo);
						printf("\nEditado com Sucesso");
						system("clear");
					break;
					case Dados_Hospede:
						Criar_Modificar_Hospede(Arquivo_Texto, Codigo);
						printf("\nEditado com Sucesso");
						system("clear");
					break;
					case Dados_Acomodacoes:
						Criar_Modificar_Acomodacoes(Arquivo_Texto, Codigo);
						printf("\nEditado com Sucesso");
						system("clear");
					break;
					case Dados_Codigo_Categoria:
						Criar_Modificar_Codigo_Categoria(Arquivo_Texto, Codigo);
						printf("\nEditado com Sucesso");
						system("clear");
					break;
					case Dados_Produtos:
					break;
					case Dados_Fornecedores:
					break;
					case Dados_Funcionarios:
					break;

				}
				
			}
			fscanf(Arquivo,"%[^\n]s",Temporario);
			getc(Arquivo);

			while(!feof(Arquivo)){
					//Vai ate o Final do Arquivo
				fscanf(Arquivo,"%[^\n]s",Temporario);
				if(feof(Arquivo)){
						//Sai caso esteja no fim do arquivo;
					break;
				}
				fprintf(Arquivo_Temporario,"%s\n",Temporario);
						//Printa no Arquivo Temporario
				getc(Arquivo);
						//Pula o \n
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
			}
		}
	}
}

int Confirmacao(){
	int Confirmacao;
		//Declaração variavel

	printf("\nDigite '1' para confirmar: ");
	scanf("%d%*c",&Confirmacao);
	//system("clear");
	if(Confirmacao ==1){
		return 1;
	}else{	
		return 0;
	}
	return 0;
}

int Intervalo_Vetor(int Vetor[],int Ultimo){
	int Intervalo=0;
		//variavel que mostrará onde esta o intervalo 

	for (int i = 0; i < Ultimo; i++)																			
	{	//for que vai de 0 ate o ultimo numero do vetor
		
		if(Vetor[i+1]!=(Vetor[i]+1)){
			//Verifica se tem um intervalo entre o primeiro e a ultima posicao do vetor

			Intervalo=i;
			//Variavel intervalo recebe posicao do vetor que tem intervalo)
			
			return Intervalo;
			//Retorna o intervalo
		}
	}
	
	return -1;
	//Retorna -1 se nao tiver nenhum intervalo

}

int Modo_Manipulacao(){
	int Modo_de_Abertura;
		//Variavel usada para validar o switch

	system("clear");
		//limpa a tela 

	do{
		printf("\nDigite o modo de manipulação dos arquivos\n" );
		printf("\n1-Memoria"
			"\n2-Arquivo Texto"
			"\n3-Arquivo Binario"
			"\n4-Banco de Dados"
			"\n5-Nuvem"
			"\n");
			//Legenda

		scanf("%d",&Modo_de_Abertura);

		system("clear");
			//Limpa a tela

		//OBS Olhar Enum no arquivo de cabeçalho Registro.h

		switch(Modo_de_Abertura){
			case Memoria:
			return Memoria;
			break;

			case Arquivo_Texto:
			return Arquivo_Texto;

			case Arquivo_Binario:
			return Arquivo_Binario;

			case Banco_De_Dados:
			printf("Banco de Dados não foi implentado\n");
			break;
			case Nuvem:
			printf("Nuvem não foi implementado\n");
			break;
			default:
			printf("Digite um codigo valido!\n");
			break;
		}

	}while(Modo_de_Abertura>=1 || Modo_de_Abertura<=5);
		//Validando o numero digitado

	system("clear");
			//Limpa a tela
}


void Quick_Sort(int vetor[], int inicio, int fim){
   //Algoritmo Auxiliar para a Ordenação de um Roll;
	int pivo, aux, i, j, meio;

	i = inicio;
	j = fim;

	meio = (int) ((i + j) / 2);
	pivo = vetor[meio];

	do{
		while (vetor[i] < pivo) i = i + 1;
		while (vetor[j] > pivo) j = j - 1;

		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i = i + 1;
			j = j - 1;
		}
	}while(j > i);

	if(inicio < j){
		Quick_Sort(vetor, inicio, j);
	}

	if(i < fim) {
		Quick_Sort(vetor, i, fim);  
	} 
	

}


int Retorna_Linha_Codigo(char Url[99], int Codigo){
	//Funcao para procurar com base no codigo digitado pelo usuario
	FILE *Arquivo;
	//Ponteiro do tipo File
	char Temporario[9999];
	Arquivo = fopen(Url,"r");
	//Abre o arquivo em modo de leitura
	int Validador = -1, Contador = 1;
	
	//Armazena o codigo lido no arquivo TXT
	do{
		fscanf(Arquivo,"%d",&Validador);
		if(feof(Arquivo)){
			return -1;
			break;
		}
		if(Validador == Codigo){
			//Verifica se o codigo é igual ao lido
			return Contador;
			//Retorna a linha que tem o codigo
			break;
			//Confirma se saiu do loop
		}
		Contador++;
		fscanf(Arquivo,"%[^\n]s",Temporario);
		//Le o arquivo ate a quebra de linha
		getc(Arquivo);
		//Pula a quebra de linha

	}while(!feof(Arquivo));
	//Le ate o fim do arquivo
	fclose(Arquivo);
	//Fecha o arquvio
	return -1;
}


int Valida_Codigo(char Url[99],int Numero_De_Registros,int Modo_de_Abertura, int Tipo_DADO){
	char Temporario[9999];
	int Vetor_Codigos[9999],Codigo;
	DADOS_HOTEL Tipo_Hotel;
	DADOS_HOSPEDE Tipo_Hospedes;
	ACOMODACOES Tipo_Acomodacoes;
	CODIGO_CATEGORIA Tipo_Codigo_Categoria;
	PRODUTOS Tipo_Produtos;
	FORNECEDORES Tipo_Fornecedores;
	FUNCIONARIOS Tipo_Funcionarios;
	//Declaraçao de variaveis
	FILE *Arquivo;
		//Ponteiro para o arquivo
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen(Url,"r");
		break;
		case Arquivo_Binario:
		Arquivo=fopen(Url,"rb");
		break;
		//Abre o Arquivo
	}

	int Contador1=0;
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
		

		Quick_Sort(Vetor_Codigos,0,Contador1);
		//Ordena o Vetor;

		int Auxiliar = Intervalo_Vetor(Vetor_Codigos,Contador1);
		//Variavel Auxiliar recebe retorno da Funcao intervalor 
		
		if (Auxiliar != -1)
			//Se diferente de -1
		{
			
			Codigo = (Vetor_Codigos[Auxiliar])+1;
			//Codigo recebe o valor do Vetor Codigos na posicao Auxiliar somado 1

		}else{
			Codigo = Vetor_Codigos[Contador1]+1;
			//Se Nao Codigo recebe vetor na ultima posicao somado 1
			
		}
	}else if (Modo_de_Abertura == Arquivo_Binario)
	{
		Contador1=0;
		//Zera contador de Codigos
		while(!feof(Arquivo)){

			switch (Tipo_DADO){
				case Dados_Hotel:
					fread(&Tipo_Hotel, sizeof(DADOS_HOTEL),1,Arquivo);
				break;
				case Dados_Hospede:
					fread(&Tipo_Hospedes, sizeof(DADOS_HOSPEDE),1,Arquivo);
				break;
				case Dados_Acomodacoes:
					fread(&Tipo_Acomodacoes, sizeof(ACOMODACOES),1,Arquivo);
				break;
				case Dados_Codigo_Categoria:
					fread(&Tipo_Codigo_Categoria, sizeof(CODIGO_CATEGORIA),1,Arquivo);
				break;
				case Dados_Produtos:
					fread(&Tipo_Produtos, sizeof(PRODUTOS),1,Arquivo);
				break;
				case Dados_Fornecedores:
					fread(&Tipo_Fornecedores, sizeof(FORNECEDORES),1,Arquivo);
				break;
				case Dados_Funcionarios:
					fread(&Tipo_Funcionarios, sizeof(FUNCIONARIOS),1,Arquivo);
				break;
			}
			//Le arquivo e passac para a struct
			if(feof(Arquivo)){
				break;
				//Se estiver no fim do arquivo sai do loop
			}
			switch (Tipo_DADO){
				case Dados_Hotel:
					Vetor_Codigos[Contador1] = Tipo_Hotel.Codigo;
			//Atribui o codigo no  vetor de codigos
				break;
				case Dados_Hospede:
					Vetor_Codigos[Contador1] = Tipo_Hospedes.Codigo;
			//Atribui o codigo no  vetor de codigos
				break;
				case Dados_Acomodacoes:
					Vetor_Codigos[Contador1] = Tipo_Acomodacoes.Codigo;
			//Atribui o codigo no  vetor de codigos
				break;
				case Dados_Codigo_Categoria:
					Vetor_Codigos[Contador1] = Tipo_Codigo_Categoria.Codigo;
			//Atribui o codigo no  vetor de codigos
				break;
				case Dados_Produtos:
					Vetor_Codigos[Contador1] = Tipo_Produtos.Codigo;
			//Atribui o codigo no  vetor de codigos
				break;
				case Dados_Fornecedores:
				Vetor_Codigos[Contador1] = Tipo_Fornecedores.Codigo;
			//Atribui o codigo no  vetor de codigos
				break;
				case Dados_Funcionarios:
					Vetor_Codigos[Contador1] = Tipo_Funcionarios.Codigo;
			//Atribui o codigo no  vetor de codigos
				break;
			}
			
			Contador1++;
			//Soma no contador de contador
		}

		Quick_Sort(Vetor_Codigos,0,Contador1);
			//Ordenamento do Vetor;

		int Auxiliar = Intervalo_Vetor(Vetor_Codigos,Contador1);
		//Variavel Auxiliar recebe retorno da Funcao intervalor 

		if (Auxiliar != -1)
			//Se diferente de -1
		{
			Codigo = (Vetor_Codigos[Auxiliar])+1;
			//Codigo recebe o valor do Vetor Codigos na posicao Auxiliar somado 1

		}else{
			Codigo = Vetor_Codigos[Contador1]+1;
			//Se Nao Codigo recebe vetor na ultima posicao somado 1
			
		}	

	}



}

void Verificacao_Arquivo(char Url[99],int Modo_de_Abertura){
	FILE *Arquivo;
		//Ponteiro para Arquivo
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		Arquivo=fopen(Url,"r");
			//Abre o Arquivo em Modo Leitura

		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe
			Arquivo=fopen(Url,"w");
					//Abre no modo leitura e caso não exista ele vai criar o arquivo
		}
		break;
		case Arquivo_Binario:
		Arquivo=fopen(Url,"rb");
			//Abre o Arquivo em Modo Leitura

		if(Arquivo==NULL){
				//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe

			Arquivo=fopen(Url,"wb");
					//Abre no modo leitura e caso não exista ele vai criar o arquivo
			
		}
		break;
	}
	
	fclose(Arquivo);
		//Fecha o Arquivo
}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


MODO Modo_Bin_ou_Txt(int Modo_de_Abertura){
	MODO Modo;
	switch(Modo_de_Abertura){
		case Arquivo_Texto:
		strcpy(Modo.Leitura,"r");
			//Modo leitura Txt
		strcpy(Modo.Escrita,"w");
			//Modo escrita Txt
		strcpy(Modo.Concatenacao,"a");
			//Modo concatenação Txt
		Modo.Modo_de_Abertura = Arquivo_Texto;
			//Modo de Abertura
		break;
		
		case Arquivo_Binario:
		strcpy(Modo.Leitura,"rb");
			//Modo leitura Bin
		strcpy(Modo.Escrita,"wb");
			//Modo escrita Bin
		strcpy(Modo.Concatenacao,"ab");
			//Modo concatenação Bin
		Modo.Modo_de_Abertura = Arquivo_Binario;
		break;

		case Memoria:
			Modo.Modo_de_Abertura = Memoria;
		break;
	}
	return Modo;
	//Retorna a Struct
}

#endif