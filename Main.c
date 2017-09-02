//Autor		:Lucas Mateus Fernandes e Leandro
//Ano		:2017
//Semestre	:2º Semestre

//
//Arquivos de cabeçalho padrão Ansi
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Registros
#include "Arquivos_Cabecalho/Registros.h"

//Prototipos
#include "Arquivos_Cabecalho/Prototipos.h"

//Funções
#include "Arquivos_Cabecalho/Funcoes.h"
#include "Arquivos_Cabecalho/Hotel.h"

//Macro
	#define DEBUG(x) printf("\n______________________%s_____________________________\n",x);

//Inicio

int main(int argc, char const *argv[])
{
	system("clear");
		//Limpa a tela
	
	
	MODO Modo;
	int Modo_de_Abertura,teste,Codigo=0;
	Verificacao_Arquivo("Arquivos/Hotel.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Hotel.txt",Arquivo_Texto);
	
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

		if(teste>=1 && teste<=4){
			Modo_de_Abertura=Modo_Manipulacao();
			Modo = Modo_Nao_Sei(Modo_de_Abertura);
		}
		///Não sei se tem necessidade  no final mas por enquanto tem !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		switch (teste){
			case 1:
			if (Modo_de_Abertura == Arquivo_Binario)
			{
				
				//Verifica se existe o Arquivo;
				Ler_Hotel_Bin("Arquivos/Hotel.bin");
			}else{
				//Verifica se existe o Arquivo;
				Ler_Hotel_Txt("Arquivos/Hotel.txt");
			}
				break;

			case 2:
				Criar_Modificar_Hotel(Modo_de_Abertura,0);	
				break;	
			case 3:
				if(Modo_de_Abertura == Arquivo_Binario){
					printf("Digite o codigo a ser editado: ");
					scanf("%d",&Codigo);
					Apagar_Modificar("Arquivos/Hotel.bin",Codigo,1,Modo);
				}else if(Modo_de_Abertura == Arquivo_Texto){
					printf("Digite o codigo a ser editado: ");
					scanf("%d",&Codigo);
					Apagar_Modificar("Arquivos/Hotel.txt",Codigo,1,Modo);
				}
				
			break;
			case 4:
			if(Modo_de_Abertura == Arquivo_Binario){
				printf("Digite o codigo a ser apagado: ");
				scanf("%d",&Codigo);
				Apagar_Modificar("Arquivos/Hotel.bin",Codigo,0,Modo);
			}else if(Modo_de_Abertura == Arquivo_Texto){
				printf("Digite o codigo a ser apagado: ");
				scanf("%d",&Codigo);
				Apagar_Modificar("Arquivos/Hotel.txt",Codigo,0,Modo);
			}
				
			break;
			default:
				return 0;
				break;
		}
	}

}
