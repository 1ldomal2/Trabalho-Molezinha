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

//Registros
#include "Arquivos_Cabecalho/Registros.h"

//Prototipos
#include "Arquivos_Cabecalho/Prototipos.h"

//Funções
#include "Arquivos_Cabecalho/Funcoes.h"
#include "Arquivos_Cabecalho/Hotel.h"
#include "Arquivos_Cabecalho/Hospede.h"
#include "Arquivos_Cabecalho/Codigo_Categoria.h"
#include "Arquivos_Cabecalho/Acomodacoes.h"


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
	
	for(int i=0;senha[i];i++){
		if(i%2==0){
			senha[i]= senha[i]-3;
		}else{
			senha[i]= senha[i]+7;
		}
	}	
	printf("DEPOIS   %s\n",senha );

*/
	while(1){
		int Opcao_Menu_Inicial=Main_All();
		switch(Opcao_Menu_Inicial){
			case Dados_Hotel:
				Main_Hotel();
			break;
			
			case Dados_Hospede:
				Main_Hospede();
			break;
			case Dados_Acomodacoes:
				Main_Acomodacoes();
			break;
			case Dados_Codigo_Categoria:
				Main_Codigo_Categoria();
			break;
			case Dados_Produtos:
			break;
			case Dados_Fornecedores:
			break;
			case Dados_Funcionarios:
			break;
		}
	}

}
