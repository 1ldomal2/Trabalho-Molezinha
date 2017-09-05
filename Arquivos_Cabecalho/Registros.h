#ifndef _Registro_ 
	//Se não estiver definido entra no if
#define _Registro_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

//Enum
enum Modo_de_Abertura{Erro=0,Memoria,Arquivo_Texto,Arquivo_Binario,Banco_De_Dados,Nuvem};
enum Registro{Erro=0,Dados_Hotel,Dados_Hospede,Acomodacoes,Codigo_Categoria,Produtos,Fornecedores,Funcionarios};	
//enum Registro{Codigo=0,Nome_Fantasia,Razao_Social,Hotel,Inscricao_Estadual,CNPJ,Logradouro,Numero,Bairro,Cidade,Telefone,Email,Dono_Gerente,Telefone_Gerente,Check_in,Check_out,Lucro};
	//Enumerador para facilitar a leitura pois a onde estiver escrito tal palavra representara
	//o valor sendo que a cada termo tem um acrescimo unário ou seja como o primeiro termo tem
	//tribuido o valor 0 o segundo será atribuido o valor 1 o 3º o valor 2 e assim por diante

//Struturas e Union

	//O Typedef atribui um apelido em vez de ter que declarar "struct Nome_da_struct" será usado apenas "Nome_da_struct"
typedef struct Modo{
	char Leitura[4];
	char Escrita[4];
	char Concatenacao[4];
	int Modo_de_Abertura;
}MODO;
	
typedef struct Endereco{
	char Logradouro[80];
	char Numero[80];
	char Bairro[80];
	char Cidade[80];
}ENDERECO;

typedef struct Dados_Hotel{
	int Codigo;
	char Nome_Fantasia[80];
	char Razao_Social[80];
	char Inscricao_Estadual[80];
	char CNPJ[80];
	ENDERECO Endereco;
	char Telefone[80];
	char Email[80];
	char Dono_Gerente[80];
	char Telefone_Gerente[80];
	char Check_in[80];
	char Check_out[80];
	char Lucro[80];
}DADOS_HOTEL;

typedef struct Dados_Hospede{
	int Codigo;
	char Nome[80];
	char CPF[80];
	char Telefone[80];
	char Email[80];
	char Sexo[15];
	char Estado_Civil[80];
	char Data_Nascimento[80];
}DADOS_HOSPEDE;

typedef struct Facilidades{
	int Televisao;
	int Ar_Condicionado;
	int Frigobar;
	int Internete;
	int Banheira;
}FACILIDADES;

typedef struct Acomodacoes{
	int Codigo;
	char Descricao[999];
	FACILIDADES Facilidades;
	int Cod_Categoria;
}ACOMODACOES;

typedef struct Codigo_Categoria{
	int Codigo;
	char Nome[80];
	char Descricao[999];
	float Valor_Diaria;
	int Capacidade;
}CODIGO_CATEGORIA;
typedef struct Produtos{
	int Codigo;
	unsigned int Estoque;
	unsigned int Estoque_Minimo;
	char Descricao[999];
	float Preco_Codigo;
	float Preco_Venda;
}PRODUTOS;

typedef struct Fornecedores{
	char Nome_Fantasia[80];
	char Razao_Social[80];
	char Inscricao_Estadual[80];
	char CNPJ[80];
	ENDERECO Endereco;
	char Telefone[80];
	char Email[80];

}FORNECEDORES;

typedef struct Funcionarios{
	int Codigo;
	char Usuario[80];
	char Senha[80];
	int Permissao;
		//Elaborar
}FUNCIONARIOS;
#endif