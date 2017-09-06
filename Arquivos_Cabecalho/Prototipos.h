#ifndef _Prototipos_ 
	//Se não estiver definido entra no if
#define _Prototipos_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

#include "Registros.h"
	//Inclui arquivos de cabeçalho

//Funçoes
//void Apagar_Modificar(char Url[99], int Codigo,int Modificar,MODO Modo);
int Confirmacao();
int Intervalo_Vetor(int Vetor[],int Ultimo);
int Modo_Manipulacao();
void Quick_Sort(int vetor[], int inicio, int fim);
int Retorna_Linha_Codigo(char Url[99], int Codigo);
int Valida_Codigo(char Url[99],int Numero_De_Registros,int Modo_de_Abertura);
void Verificacao_Arquivo(char Url[99],int Modo_de_Abertura);
MODO Modo_Bin_ou_Txt(int Modo_de_Abertura);
//Hotel
void Ler_Hotel_Txt(char Url[99]);
void Ler_Hotel_Bin();
void Ler_Hotel_Memoria(DADOS_HOTEL Hotel);
void Gravar_Hotel_Txt(char Url[99],DADOS_HOTEL *Hotel);
void Gravar_Hotel_Bin(char Url[99],DADOS_HOTEL *Hotel);
void Criar_Modificar_Hotel(int Modo_de_Abertura,int Manter_Codigo);
int Retorna_Campo_Struct_Hotel(char Url[99], int Codigo);
void Apagar_Modificar_Hotel_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
DADOS_HOTEL Retorna_Struct_Hotel_Grava_Memoria(DADOS_HOTEL *Hotel);
//Hospede
void Ler_Hospede_Txt(char Url[99]);
void Ler_Hospede_Bin();
void Ler_Hospede_Memoria(DADOS_HOSPEDE Hospede);
void Gravar_Hospede_Txt(char Url[99],DADOS_HOSPEDE *Hospede);
void Gravar_Hospede_Bin(char Url[99],DADOS_HOSPEDE *Hospede);
void Criar_Modificar_Hospede(int Modo_de_Abertura,int Manter_Codigo);
int Retorna_Campo_Struct_Hospede(char Url[99], int Codigo);
void Apagar_Modificar_Hospede_Bin(char Url[99], int Codigo,int Modificar,MODO Modo);
DADOS_HOSPEDE Retorna_Struct_Hospede_Grava_Memoria(DADOS_HOSPEDE *Hospede);
#endif