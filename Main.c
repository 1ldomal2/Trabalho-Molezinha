//Autor		:Lucas Mateus Fernandes e Leandro
//Ano		:2017
//Semestre	:2º Semestre
//
//Arquivos de cabeçalho padrão Ansi
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
/* ... */
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

	//SENHA 
	/*char *password = getpass("Password: "); //PEGA SENHA SEM MOSTRAR AO USUARIO
		char senha[99];
		strcpy(senha,password);
		for(int i=0;senha[i];i++){
			if(i%2==0){
				senha[i]= senha[i]+3;
			}else{
				senha[i]= senha[i]-7;
			}
			  // para criptografar "embaralhar"
		}
		for(int i=0;senha[i];i++)
		{
			senha[i] = senha[i]+1;	 code 
		}
		printf("%s\n",senha);
		for(int i=0; senha[i];i++)
		{
			senha[i] = senha[i]-1;	
		}
	*/
	for(int i=0;senha[i];i++){
		if(i%2==0){
			senha[i]= senha[i]-3;
		}else{
			senha[i]= senha[i]+7;
		}
	}	
	printf("DEPOIS   %s\n",senha );


	
	DADOS_HOTEL Hotel;
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
			Modo = Modo_Bin_ou_Txt(Modo_de_Abertura);
		}
		///Não sei se tem necessidade  no final mas por enquanto tem !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		switch (teste){
			case 1:
			if (Modo_de_Abertura == Arquivo_Binario)
			{
				Ler_Hotel_Bin("Arquivos/Hotel.bin");
			}else if(Modo_de_Abertura == Arquivo_Texto){
				Ler_Hotel_Txt("Arquivos/Hotel.txt");
			}else if(Modo_de_Abertura==Memoria){
				if(Hotel.Codigo == 1){
					Ler_Hotel_Memoria(Hotel);
				}else{
					printf("Não existe nenhum dado na memória");
				}
			}
				break;
			case 2:
				if(Modo_de_Abertura == Memoria){
					printf("!!!ATENÇÂO!!!\n"
					"Se existir algum dado na mémoria será peridido, so é possivel salvar 1 dado por vez na memoria");
					if(Confirmacao()){
						Retorna_Struct_Grava_Memoria(&Hotel);
						printf("Salvo com sucesso na memória");
					}
					
					break;
				}else{
					Criar_Modificar_Hotel(Modo_de_Abertura,0);	
				}
				break;	
			case 3:
				if(Modo_de_Abertura == Arquivo_Binario){
					printf("Digite o codigo a ser editado: ");
					scanf("%d",&Codigo);
					Apagar_Modificar_Hotel_Bin("Arquivos/Hotel.bin",Codigo,1,Modo);
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
				Apagar_Modificar_Hotel_Bin("Arquivos/Hotel.bin",Codigo,0,Modo);
			}else if(Modo_de_Abertura == Arquivo_Texto){
				printf("Digite o codigo a ser apagado: ");
				scanf("%d",&Codigo);
				Apagar_Modificar("Arquivos/Hotel.txt",Codigo,0,Modo);
			}
				
			break;

			case 666:
				printf(""
"             ____________________________________________________\n"
"            /                                                    \\\n"
"           |    _____________________________________________     |\n"
"           |   |                                             |    |\n"
"           |   |  C:\\>Mint > Ubunto                          |    |\n"
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


			default:
				return 0;
				break;
		}
	}

}
