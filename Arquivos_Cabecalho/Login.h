#ifndef _Login_ 
	//Se não estiver definido entra no if
#define _Login_ 
	//Define _Funcoes_ evitando que a bilioteca seja iplementada duas vezes

LOGIN Login(){
	LOGIN Permissoes;//Cria um struct do Tipo login

	printf("Digite o codigo do usuario:");
	scanf("%d%*c",&Permissoes.Codigo_Usuario);

	char *Ponteiro_Senha = getpass("Digite a senha: ");//Camufla a Senha
	char Senha[99];
	strcpy(Senha,Ponteiro_Senha);

	//Achar a linha do Codigo!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	FILE *Arquivo;

	fopen(Url)

	//Achar o Registro de senha!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1!

	if(strcmp(Senha,Senha_Arquivo)==0){
		Permissoes.
		Codigo_Usuario=0; 
		Permissao_Criar=0;
		Permissao_Editar=0;
		Permissao_Ler=0;
		Permissao_Apagar=0;
		Logado=1;
	}

	return Permissoes;//Retorna as Permissoes e se o Login foi efetivado

}

#endif