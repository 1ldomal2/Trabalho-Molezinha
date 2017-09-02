#ifndef _Hotel_ 
	//Se não estiver definido entra no if
#define _Hotel_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Registros.h"
#include "Prototipos.h"
	//Inclui arquivos de cabeçalho


//Prototipos de Função 
/*
void Ler_Hotel_Txt(char Url[99]);
void Ler_Hotel_Bin();
void Gravar_Hotel_Txt(char Url[99],DADOS_HOTEL *Hotel);
void Gravar_Hotel_Bin(char Url[99],DADOS_HOTEL *Hotel);
void Criar_Modificar_Hotel(int Modo_de_Abertura,int Manter_Codigo);
*/

	

void Ler_Hotel_Txt(char Url[99]){
	DADOS_HOTEL Hotel;
		//Cria uma variavel do tipo DADOS HOTEL;

	FILE *Arquivo;
		//Ponteiro para o arquivo

	Arquivo=fopen(Url,"r");
		//Abre o Arquivo
	
	if(Arquivo==NULL){
		printf("O Arquivo não foi aberto corretamente\n");
	}else{
		do{
			fscanf(Arquivo,"%d",&Hotel.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Nome_Fantasia);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Razao_Social);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Inscricao_Estadual);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.CNPJ);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Endereco.Logradouro);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Endereco.Numero);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Endereco.Bairro);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Endereco.Cidade);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Telefone);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Email);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Dono_Gerente);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Telefone_Gerente);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Check_in);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Check_out);
				//Expreção Regular
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caractere
			fscanf(Arquivo,"%[^;]s",Hotel.Lucro);
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caracte (pula o ;)
			getc(Arquivo);
				//Pula o Ponteiro para o proximo caracte (pula o \n)

			printf("Codigo:\t\t\t%d\n",Hotel.Codigo);
			printf("Nome fantasia:\t\t%s\n",Hotel.Nome_Fantasia);
			printf("Razao social:\t\t%s\n",Hotel.Razao_Social);
			printf("Inscricao Estadual\t%s\n",Hotel.Inscricao_Estadual);
			printf("CNPJ:\t\t\t%s\n",Hotel.CNPJ);
			printf("Logradouro:\t\t%s\n",Hotel.Endereco.Logradouro);
			printf("Numero:\t\t\t%s\n",Hotel.Endereco.Numero);
			printf("Bairro:\t\t\t%s\n",Hotel.Endereco.Bairro);
			printf("Cidade:\t\t\t%s\n",Hotel.Endereco.Cidade);
			printf("Telefone:\t\t%s\n",Hotel.Telefone);
			printf("Email:\t\t\t%s\n",Hotel.Email);
			printf("Dono gerente:\t\t%s\n",Hotel.Dono_Gerente);
			printf("Telefone gerente:\t%s\n",Hotel.Telefone_Gerente);
			printf("Check in:\t\t%s\n",Hotel.Check_in);
			printf("Check out:\t\t%s\n",Hotel.Check_out);
			printf("%% de Lucro\t\t%s\n",Hotel.Lucro);
			printf("____________________________________________________\n");
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
	}

	fclose(Arquivo);
		//Fecha o Arquivo;
}

void Ler_Hotel_Bin(char Url[99]){
	FILE *Arquivo;
	DADOS_HOTEL Hotel;
	Arquivo = fopen(Url,"rb");
	if(Arquivo == NULL){
   		printf("\nNao foi possivel abrir o arquivo!");
   	}
   	while(!feof(Arquivo)){
	    fread(&Hotel, sizeof(DADOS_HOTEL),1,Arquivo);
		if(feof(Arquivo)){
			//Verifica se esta no fim do arquivo
			break;
			//Sai do loop
		}
	   	printf("Codigo:\t\t\t%d\n",Hotel.Codigo);
		printf("Nome fantasia:\t\t%s\n",Hotel.Nome_Fantasia);
		printf("Razao social:\t\t%s\n",Hotel.Razao_Social);
		printf("Inscricao Estadual\t%s\n",Hotel.Inscricao_Estadual);
		printf("CNPJ:\t\t\t%s\n",Hotel.CNPJ);
		printf("Logradouro:\t\t%s\n",Hotel.Endereco.Logradouro);
		printf("Numero:\t\t\t%s\n",Hotel.Endereco.Numero);
		printf("Bairro:\t\t\t%s\n",Hotel.Endereco.Bairro);
		printf("Cidade:\t\t\t%s\n",Hotel.Endereco.Cidade);
		printf("Telefone:\t\t%s\n",Hotel.Telefone);
		printf("Email:\t\t\t%s\n",Hotel.Email);
		printf("Dono gerente:\t\t%s\n",Hotel.Dono_Gerente);
		printf("Telefone gerente:\t%s\n",Hotel.Telefone_Gerente);
		printf("Check in:\t\t%s\n",Hotel.Check_in);
		printf("Check out:\t\t%s\n",Hotel.Check_out);
		printf("%% de Lucro\t\t%s\n",Hotel.Lucro);
		printf("____________________________________________________\n");
   	}
   	fclose(Arquivo);
}

void Gravar_Hotel_Txt(char Url[99],DADOS_HOTEL *Hotel){
	//Colocar com parametro não " " mas sim ;
	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	/*

	*/
	Arquivo=fopen(Url,"a+");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo
	if(Arquivo == NULL){
   		printf("\nNao foi possivel abrir o arquivo!");
   	}
   	fprintf(Arquivo,"%d;",Hotel->Codigo);
   	fprintf(Arquivo,"%s;",Hotel->Nome_Fantasia);
   	fprintf(Arquivo,"%s;",Hotel->Razao_Social);
	fprintf(Arquivo,"%s;",Hotel->Inscricao_Estadual);
	fprintf(Arquivo,"%s;",Hotel->CNPJ);
	fprintf(Arquivo,"%s;",Hotel->Endereco.Logradouro);
	fprintf(Arquivo,"%s;",Hotel->Endereco.Numero);
	fprintf(Arquivo,"%s;",Hotel->Endereco.Bairro);
	fprintf(Arquivo,"%s;",Hotel->Endereco.Cidade);
	fprintf(Arquivo,"%s;",Hotel->Telefone);
	fprintf(Arquivo,"%s;",Hotel->Email);
	fprintf(Arquivo,"%s;",Hotel->Dono_Gerente);
	fprintf(Arquivo,"%s;",Hotel->Telefone_Gerente);
	fprintf(Arquivo,"%s;",Hotel->Check_in);
	fprintf(Arquivo,"%s;",Hotel->Check_out);
	fprintf(Arquivo,"%s;\n",Hotel->Lucro);
		//Salva um struct por Linha

	fclose(Arquivo);
		//Fecha o o arquivo para evitar erros
	

		printf("\nArquivo Salvo em : %s",Url);
}


void Gravar_Hotel_Bin(char Url[99],DADOS_HOTEL *Hotel){

	FILE *Arquivo;
		//Um ponteiro que aponta para um arquivo
	
	Arquivo=fopen(Url,"ab");
		//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo

	if(Arquivo == NULL){
   		printf("\nNao foi possivel abrir o arquivo!");
   	}
   	fwrite(Hotel, sizeof(DADOS_HOTEL), 1, Arquivo); 
   		//Primeiro argumento é um ponteiro .... como proceder

   	fclose(Arquivo);
   		//Fecha o Arquivo Para evitar erro
   	printf("\nArquivo Salvo 'Hotel.bin'");
   		//Mensagem de Confirmação
}



void Criar_Modificar_Hotel(int Modo_de_Abertura, int Manter_Codigo){
	char Url[99];
	DADOS_HOTEL Hotel;
		//Variavel Local
		//Obedecendo o principio do privilegio mínimo
		//Usada somente para transição do buffer para o arquivo ou do arquivo para a tela
	switch (Modo_de_Abertura){
 			case Memoria:
			
			break;
			
		case Arquivo_Texto:
		 	strcpy(Url,"Arquivos/Hotel.txt");
		 	//Coloca o caminho na URL
		 	if (Manter_Codigo == 0)
		 	{
		 		Hotel.Codigo = Valida_Codigo(Url,15,Arquivo_Texto);
		 	}else{
		 		Hotel.Codigo = Manter_Codigo;
		 	}
			break;

		case Arquivo_Binario:
		 	strcpy(Url,"Arquivos/Hotel.bin");
		 	//Coloca o caminho na URL
		 	if (Manter_Codigo == 0)
		 	{
		 		Hotel.Codigo = Valida_Codigo(Url,15,Arquivo_Binario);
		 	}else{
		 		Hotel.Codigo = Manter_Codigo;
		 	}
			break;
		case Banco_De_Dados:
			//Não está implementado
			break;
		case Nuvem:
			//Não está implementado
			break;

	}
	printf("\nNome Fantasia:");
	scanf("%s",Hotel.Nome_Fantasia);
	printf("Razão Social:");
	scanf("%s",Hotel.Razao_Social);
	printf("Inscrição Estadual:");
	scanf("%s",Hotel.Inscricao_Estadual);
	printf("CNPJ:");
	scanf("%s",Hotel.CNPJ);
	printf("Logradouro:");
	scanf("%s",Hotel.Endereco.Logradouro);
	printf("Numero:");
	scanf("%s",Hotel.Endereco.Numero);
	printf("Bairro:");
	scanf("%s",Hotel.Endereco.Bairro);
	printf("Cidade:");
	scanf("%s",Hotel.Endereco.Cidade);
	printf("Telefone:");
	scanf("%s",Hotel.Telefone);
	printf("e-mail:");
	scanf("%s",Hotel.Email);
	printf("Dono/Gerente:");
	scanf("%s",Hotel.Dono_Gerente);
	printf("Telefone/Gente:");
	scanf("%s",Hotel.Telefone_Gerente);
	printf("Horário de check-in:");
	scanf("%s",Hotel.Check_in);
	printf("Horário de check-out:");
	scanf("%s",Hotel.Check_out);
	printf("Margen de lucro de produtos vendidos:");
	scanf("%s",Hotel.Lucro);
	
	/**

	

	OLHAR O O QUE FAZER PARA QUE a funçao fique mais modular e assim eu consiga fazer com que esta função sirva para criar e Editar
	o que atrapalha é as structs.......





	*/
	switch(Modo_de_Abertura){

		case Arquivo_Texto:
			Gravar_Hotel_Txt(Url,&Hotel);
			break;

		case Arquivo_Binario:
			Gravar_Hotel_Bin(Url,&Hotel);
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


int Retorna_Campo_Struct_Hotel(char Url[99], int Codigo){
	//Funcao para procurar hotel com base no codigo digitado pelo usuario
	FILE *Arquivo;
	MODO Modo;
	Modo = Modo_Nao_Sei(Arquivo_Binario);
	//Ponteiro do tipo File
	char Temporario[9999];
	DADOS_HOTEL Hotel;
	Arquivo = fopen(Url,Modo.Leitura);
	//Abre o arquivo em modo de leitura
	int Validador = -1, Numero_Structs = 1;
	
	//Armazena o codigo lido no arquivo Bin
	do{
		fread(&Hotel, sizeof(DADOS_HOTEL),1,Arquivo);
		Validador = Hotel.Codigo;
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

#endif
