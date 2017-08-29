//Autor		:Lucas Mateus Fernandes
//Ano		:2017
//Semestre	:2º Periodo

//Arquivos de cabeçalho fundamentais
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "Hotel.h"

//Inicio

int main(int argc, char const *argv[])
{
	system("clear");
		//Limpa a tela
	
	int Modo_de_Abertura,teste;
	while(1){
		printf("\nDigite:"
			"\n\t1\tPara Ler"
			"\n\t2\tPara Gravar"
			"\n\t?\tSair\n\t");
		scanf("%d",&teste);

		system("clear");
			//limpa a tela

		if(teste>=1 && teste<=2){
			Modo_de_Abertura=Manipular_Arquivo();
		}
		///Não sei se tem necessidade  no final mas por enquanto tem !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		switch (teste){
			case 1:
				Ler_Hotel_Txt();
				break;

			case 2:
				Criar_Editar_Hotel(Modo_de_Abertura);	
				break;	

			default:
				return 0;
				break;
		}
	}

}
