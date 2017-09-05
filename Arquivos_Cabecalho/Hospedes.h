#ifndef _Hospedes_ 
	//Se não estiver definido entra no if
#define _Hospedes_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Registros.h"
#include "Prototipos.h"

void Criar_Modificar_Hospedes(int Modo_de_Abertura, int Manter_Codigo){
	char Url[99];
	DADOS_HOSPEDES Hospedes;
		//Variavel Local
		//Obedecendo o principio do privilegio mínimo
		//Usada somente para transição do buffer para o arquivo ou do arquivo para a tela
	switch (Modo_de_Abertura){
		case Arquivo_Texto:
		strcpy(Url,"Arquivos/Hospedes.txt");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Hospedes.Codigo = Valida_Codigo(Url,15,Arquivo_Texto);
		}else{
			Hospedes.Codigo = Manter_Codigo;
		}
		break;

		case Arquivo_Binario:
		strcpy(Url,"Arquivos/Hospedes.bin");
		 	//Coloca o caminho na URL
		if (Manter_Codigo == 0)
		{
			Hospedes.Codigo = Valida_Codigo(Url,15,Arquivo_Binario);
		}else{
			Hospedes.Codigo = Manter_Codigo;
		}
		break;
		case Banco_De_Dados:
			//Não está implementado
		break;
		case Nuvem:
			//Não está implementado
		break;

	}
	printf("\nNome:");
	scanf("%s",Hospedes.Nome);
	printf("CPF:");
	scanf("%s",Hospedes.CPF);
	printf("Logradouro:");
	scanf("%s",Hospedes.Endereco.Logradouro);
	printf("Numero:");
	scanf("%s",Hospedes.Endereco.Numero);
	printf("Bairro:");
	scanf("%s",Hospedes.Endereco.Bairro);
	printf("Cidade:");
	scanf("%s",Hospedes.Endereco.Cidade);
	printf("Telefone:");
	scanf("%s",Hospedes.Telefone);
	printf("e-mail:");
	scanf("%s",Hospedes.Email);
	printf("Sexo:");
	scanf("%s",Hospedes.Sexo);
	printf("Estado Civil:");
	scanf("%s",Hospedes.Estado_Civil);
	printf("Data de nascimento:");
	scanf("%s",Hospedes.Data_Nascimento);
	printf("Horário de check-out:");
	scanf("%s",Hospedes.Check_out);
	printf("Margen de lucro de produtos vendidos:");
	scanf("%s",Hospedes.Lucro);
	//Mostra Dados de Hospedes salvos na struct
	switch(Modo_de_Abertura){			
		case Arquivo_Texto:
			Gravar_Hospedes_Bin_Txt(Url,&Hospedes);
			//Grava em TXT
			break;

		case Arquivo_Binario:
			Gravar_Hospedes_Bin(Url,&Hospedes);
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
#endif
