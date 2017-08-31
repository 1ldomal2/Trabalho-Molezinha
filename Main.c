//Autor		:Lucas Mateus Fernandes
//Ano		:2017
//Semestre	:2º Periodo

//Arquivos de cabeçalho fundamentais
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Arquivos_Cabecalho/Hotel.h"

//Inicio

int main(int argc, char const *argv[])
{
	system("clear");
		//Limpa a tela
	
	Verificacao_Arquivo_Hotel("Arquivos/Hotel.txt");
		//Verifica se existe o Arquivo;
		//POSTERIORMENTE FAZER UMA FUNÇÃO QUE CHAMA TODAS AS OUTRAS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	int Modo_de_Abertura,teste,Codigo=0;
	while(1){
		printf("\nDigite:"
			"\n\t1\tPara Ler"
			"\n\t2\tPara Criar"
			"\n\t3\tPara Editar"
			"\n\t4\tPara Apagar"
			"\n\t?\tSair\n\t");
		scanf("%d",&teste);

		system("clear");
			//limpa a tela

		if(teste>=1 && teste<=2){
			Modo_de_Abertura=Manipular_Arquivo_Hotel();
		}
		///Não sei se tem necessidade  no final mas por enquanto tem !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		switch (teste){
			case 1:
				Ler_Hotel_Txt("Arquivos/Hotel.txt");
				break;

			case 2:
				Criar_Editar_Hotel(Modo_de_Abertura,0);	
				break;	
			case 3:
			printf("Digite o codigo a ser editado: ");
			scanf("%d",&Codigo);
				Apagar_Modificar_Hotel("Arquivos/Hotel.txt",Codigo,1);
			break;
			case 4:
			printf("Digite o codigo a ser apagado: ");
			scanf("%d",&Codigo);
				Apagar_Modificar_Hotel("Arquivos/Hotel.txt",Codigo,0);
			break;
			default:
				return 0;
				break;
		}
	}

}
