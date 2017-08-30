/*
Modificar:
			Editar/criar
				Caso não exista os Arquivos o Que Fazer ?
Falta fazer :
			 Ler em Binario
			 Excluir
*/


#ifndef _Hotel_ 
	//Se não estiver definido entra no if
#define _Hotel_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes
#include "Registro.h"
#include <string.h>
	//Inclui o outro arquivo de cabeçalho
#define DEBUG(x) printf("\n______________________%s_____________________________\n",x);
//Prototipos de Função 
void Ler_Hotel_Txt(char Url[99]);
void Gravar_Hotel_Txt(char Url[99],DADOS_HOTEL *Hotel);
void Ler_Hotel_Bin();
void Gravar_Hotel_Bin(char Url[99],DADOS_HOTEL *Hotel);
void Criar_Editar_Hotel(int Modo_de_Abertura);
int Manipular_Arquivo_Hotel();
int Valida_Codigo(char Url[99],int Numero_De_Registros,int Modo_de_Abertura);
void Quick_Sort(int vetor[], int inicio, int fim);
int Intervalo_Vetor_Hotel(int Vetor[],int Ultimo);
void Verificacao_Arquivo_Hotel(char Url[99]);
int Temporaria_Hotel(char Url[99], int Numero_De_Registros);
int Retorna_Linha_Codigo_Hotel(char Url[99], int Codigo);
void Apagar_Modificar_Hotel(char Url[99], int Codigo);	

//Funçoes

void Verificacao_Arquivo_Hotel(char Url[99]){
	FILE *Arquivo;
		//Ponteiro para Arquivo

	Arquivo=fopen(Url,"r");
		//Abre o Arquivo em Modo Leitura

	if(Arquivo==NULL){
		//Se retornar Null é porque nao conseguiu abrir o arquivo e provavelmente ele não existe

		Arquivo=fopen(Url,"w");
			//Abre no modo leitura e caso não exista ele vai criar o arquivo

	}
	fclose(Arquivo);
		//Fecha o Arquivo
}

int Intervalo_Vetor_Hotel(int Vetor[],int Ultimo){
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



int Valida_Codigo(char Url[99],int Numero_De_Registros,int Modo_de_Abertura){
	char Temporario[9999];
	int Vetor_Codigos[9999],Codigo;
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

	while(!feof(Arquivo)){

		fscanf(Arquivo,"%d",&Vetor_Codigos[Contador1]);
			//Salva o Codigo

			getc(Arquivo);

		if(feof(Arquivo)){
			Contador1--;
			break;
		}
		for (int i = 1; i <=Numero_De_Registros; ++i)
		{//Pula os Registros
			fscanf(Arquivo,"%[^;]s",Temporario);
			getc(Arquivo);
		}
		getc(Arquivo);
		Contador1++;
		
	}

	Quick_Sort(Vetor_Codigos,0,Contador1);
		//Ordenamento do Vetor;
																
	int Auxiliar = Intervalo_Vetor_Hotel(Vetor_Codigos,Contador1);
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

	fclose(Arquivo);
	//Fecha arquivo
	return Codigo;
	//Retorna o Codigo

}

//----------------------------Hotel--------------------------------------
/*int Temporaria_Hotel(char Url[99], int Numero_De_Registros){
	FILE *Arquivo, *Arquivo_Temporario;
	switch (Modo_de_Abertura){
		case Arquivo_Texto:
			Verificacao_Arquivo_Hotel(Url);
		break;
	}

	
}*/
int Retorna_Linha_Codigo_Hotel(char Url[99], int Codigo){
	//Funcao para procurar hotel com base no codigo digitado pelo usuario
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
	void Apagar_Modificar_Hotel(char Url[99], int Codigo){
		int Linha = Retorna_Linha_Codigo_Hotel(Url,Codigo);
		if(Linha == -1){
			printf("Codigo inexistente");
		}
		else{
			char Temporario[9999];		
			FILE *Arquivo, *Arquivo_Temporario;
			Arquivo = fopen(Url,"r");
			Arquivo_Temporario = fopen("Arquivos/Temp.txt","w");
			fclose(Arquivo_Temporario);
			Arquivo_Temporario = fopen("Arquivos/Temp.txt","a");
			for(int i=0;i<Linha;i++){
				fscanf(Arquivo,"%[^\n]s",Temporario);
				fprintf(Arquivo_Temporario,"%s;\n",Temporario);
				getc(Arquivo);
			}
			fscanf(Arquivo,"%[^\n]s",Temporario);
			getc(Arquivo);		
			while(!feof(Arquivo)){
				fscanf(Arquivo,"%[^\n]s",Temporario);
				fprintf(Arquivo_Temporario,"%s;\n",Temporario);
				getc(Arquivo);
			}
			fclose(Arquivo_Temporario);
			fclose(Arquivo);
			
		}
	}

	//-------------------------Txt--------------------------------------
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


	//-----------------------Binario----------------------------------
	void Ler_Hotel_Bin(){

	}

	void Gravar_Hotel_Bin(char Url[99],DADOS_HOTEL *Hotel){

		FILE *Arquivo;
			//Um ponteiro que aponta para um arquivo
		
		Arquivo=fopen(Url,"a+b");
			//A função Retorna NULL caso o ponteiro não consiga apontar para o arquivo

		if(Arquivo == NULL){
	   		printf("\nNao foi possivel abrir o arquivo!");
	   	}

	   	fwrite(&Hotel, sizeof(DADOS_HOTEL), 1, Arquivo); 
	   		//Primeiro argumento é um ponteiro .... como proceder

	   	fclose(Arquivo);
	   		//Fecha o Arquivo Para evitar erro
	   	printf("\nArquivo Salvo 'Hotel.bin'");
	   		//Mensagem de Confirmação
	}

	//---------------------Editar/Criar---------------------
	void Criar_Editar_Hotel(int Modo_de_Abertura){
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
				Hotel.Codigo = Valida_Codigo(Url,15,Arquivo_Texto);
				break;
			case Arquivo_Binario:
			 strcpy(Url,"Arquivos/Hotel.bin");
			 	//Coloca o caminho na URL
				Hotel.Codigo = Valida_Codigo(Url,15,Arquivo_Binario);

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





//Criar Editar Excluir Ler

int Manipular_Arquivo_Hotel(){
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

#endif