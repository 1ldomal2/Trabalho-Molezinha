//Autor		:Lucas Mateus Fernandes e Leandro
//Ano		:2017
//Semestre	:2º Semestre
//
//Macros
#define Vermelho(TEXTO)	printf("\33[1;31m%s \33[0;29m ",TEXTO)
#define Verde(TEXTO)	printf("\33[1;32m%s \33[0;29m ",TEXTO)
//Biblioteca Padrão
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
//Registros
#include "Arquivos_Cabecalho/Registros.h"
//Prototipos
#include "Arquivos_Cabecalho/Prototipos.h"
//Funções
#include "Arquivos_Cabecalho/Funcoes.h"
//Modulo_Registro
#include "Arquivos_Cabecalho/Modulo_Registro/Hotel.h"
#include "Arquivos_Cabecalho/Modulo_Registro/Hospede.h"
#include "Arquivos_Cabecalho/Modulo_Registro/Codigo_Categoria.h"
#include "Arquivos_Cabecalho/Modulo_Registro/Acomodacoes.h"
#include "Arquivos_Cabecalho/Modulo_Registro/Login.h"
#include "Arquivos_Cabecalho/Modulo_Registro/Funcionarios.h"
#include "Arquivos_Cabecalho/Modulo_Registro/Fornecedores.h"
#include "Arquivos_Cabecalho/Modulo_Registro/Produtos.h"
//Modulo_Reserva




//Macro
	#define DEBUG(x) printf("\n______________________%s_____________________________\n",x);

//Inicio


int main(int argc, char const *argv[])
{
	system("mkdir Arquivos");
	//comando do s.os
	Verificacao_Arquivo("Arquivos/Produtos.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Produtos.txt",Arquivo_Texto);
	Verificacao_Arquivo("Arquivos/Acomodacoes.txt",Arquivo_Texto);
	Verificacao_Arquivo("Arquivos/Acomodacoes.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Codigo_Categoria.txt",Arquivo_Texto);
	Verificacao_Arquivo("Arquivos/Codigo_Categoria.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Funcionarios.txt",Arquivo_Texto);
	Verificacao_Arquivo("Arquivos/Funcionarios.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Hospede.txt",Arquivo_Texto);
	Verificacao_Arquivo("Arquivos/Hospede.bin",Arquivo_Binario);
	Verificacao_Arquivo("Arquivos/Hotel.txt",Arquivo_Texto);
	Verificacao_Arquivo("Arquivos/Hotel.bin",Arquivo_Binario);
	//Cria os arquivos
	system("clear");
	//Limpa a tela

	while(1){
		int Enum_Manipulacao,Loop=1;
		MODO Modo;

		Enum_Manipulacao=Configuracoes();//Retorna um inteiro referente ao modo de manipulação
		Modo=Modo_Bin_ou_Txt(Enum_Manipulacao);//Retorna uma struct com os modos txt ou bin
		Modo.Nivel_De_Permissao = Login(Modo);
		//LOGIN retorna o tipo de permissao de 1 a 15

		while(Loop){
			OrdenaValoresTxt();
			//Cria os arquivos
			int Opcao_Menu_Inicial;

			Opcao_Menu_Inicial=Main_All();//Retorna um numero inteiro referente ao case

			switch(Opcao_Menu_Inicial){

				case Dados_Hotel:
					Main_Hotel(Modo);
				break;
				
				case Dados_Hospede:
					Main_Hospede(Modo); 	
				break;

				case Dados_Acomodacoes:
					Main_Acomodacoes(Modo);
				break;

				case Dados_Codigo_Categoria:
					Main_Codigo_Categoria(Modo);
				break;

				case Dados_Produtos:
					Main_Produtos(Modo);
				break;

				case Dados_Fornecedores:
					Main_Fornecedores(Modo);
				break;

				case Dados_Funcionarios:
					Main_Funcionarios(Modo);
				break;

				case 0:
					Loop=0;
				break;
			}
		}
	}
	return 1;
}
