#ifndef _Feedback_
#define _Feedback_



void MainFeedback(){
	int Tipo_Listagem = MenuInicialFeedback();
	int Campo_Lista = MenuListagemFeedback();
	int Tipo_Hospede, Tipo_Acomodacoes, Tipo_Reservas, Tipo_Produtos; 
	if(Tipo_Listagem == Tela){
		switch(Campo_Lista){
			case Hospedes:
				Tipo_Hospede = Tipo_Listagem_Hospede();
				if(Tipo_Hospede == Codigo){
					Filtro_Hospede_Codigos(Tela);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;
				}else{
					//Chamar funcao para printar na tela com filtro de sexo
				}
			break;
			case Acomodacoes:
			break;
			case Reservas:
			break;
			case Produtos:
			break;
		}
	}else if(Tipo_Listagem == Csv){
		switch(Campo_Lista){
			case Hospedes:
				Tipo_Hospede = Tipo_Listagem_Hospede();
				if(Tipo_Hospede == Codigo){
					Filtro_Hospede_Codigos(Csv);
					Verde("Digite 1 e pressione enter para continuar");
					PAUSA;
				}else{
					//Chamar funcao para printar na tela com filtro de sexo
				}
			break;
			case Acomodacoes:
			break;
			case Reservas:
			break;
			case Produtos:
			break;
		}
	}
}	

int Tipo_Listagem_Hospede(){
	//Funcao para saber o filtro que o usuario deseja utilizar
	int Filtro;
	do{
		printf("Digite 1 para filtrar por codigos e 2 para filtar por sexo ");
		scanf("%d",&Filtro);
		if(Filtro < 1 || Filtro > 2){
			Vermelho("Digite 1 opcao valida\n");
		}
	}while(Filtro < 1 || Filtro > 2);
	return Filtro;
	//Retorna o filtro
}
void Filtro_Hospede_Codigos(int Modo_Feedback){
	//Funcao para realizar filtro por codigos de hospede
	int Modo_Abertura = Configuracoes();
	int Codigo_Inicial = 0;
	int Codigo_Final = 0;
	//Variaveis para receber o codigo inicial e final e fazer o range entre eles
	Verde("Digite o range de codigos que sera printado:\n");
	do{
		Verde("Codigo Inicial = ");
		scanf("%d",&Codigo_Inicial);
		Verde("Codigo Final = ");
		scanf("%d",&Codigo_Final);
		if(Codigo_Inicial == 0 || Codigo_Final == 0 ){
			Vermelho("O codigo inicial e final não pode ser 0 digite um valido");
		}else if(Codigo_Final < Codigo_Inicial){
			Vermelho("O codigo final não pode ser menor que o inicial");
		}
		//Mostra mensagem de erros ao usuario
	}while(Codigo_Inicial == 0 || Codigo_Final == 0 || Codigo_Final < Codigo_Inicial);
	//Loop que repete ate usuario digitiar valores validos para o range de codigos 
	int Quantidade_Codigos = Codigo_Final - Codigo_Inicial + 1;
	int Codigos[Quantidade_Codigos];
	int Contador_Codigos = 0;
	int Indice_Iguais = 0;
	//Vetor de codigos com a quantidade exata do range de codigos que foi passado, e contador de condigos
	for(int i = Codigo_Inicial; i <= Codigo_Final; i++){
		Codigos[Contador_Codigos] = i;
		Contador_Codigos++;
	}
	if(Modo_Abertura == Arquivo_Texto){
	//Caso modo de abertura seja TXT
	char Url[Tamanho2],Temporario[Tamanho2];
	sprintf(Url,"Arquivos/Hospede.txt");
	//Declara Array com a url
	DADOS_HOSPEDE Hospede;
	//Cria uma variavel do tipo DADOS HOSPEDE;

	FILE *Arquivo;
		//Ponteiro para o arquivo

	Arquivo=fopen(Url,"r");
		//Abre o Arquivo
	int Arquivo_Vazio=0;
		
	
	if(Arquivo==NULL){
		Vermelho("O Arquivo não foi aberto corretamente\n");
	}else{
		do{
			fscanf(Arquivo,"%d",&Hospede.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			//Pula o Ponteiro para o proximo caractere
			for(int i = 0;i < Quantidade_Codigos; i++){
				if(Codigos[i] == Hospede.Codigo){
					if(feof(Arquivo)){
						//Verifica se esta no fim do arquivo
						break;
						//Sai do loop
					}
					fscanf(Arquivo,"%[^;]s",Hospede.Nome);
					//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
					//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Sexo);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Estado_Civil);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.CPF);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Endereco.Logradouro);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Endereco.Numero);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Endereco.Bairro);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Endereco.Cidade);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Telefone);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Email);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Data_Nascimento);
						//Expreção Regular
					getc(Arquivo);
					getc(Arquivo);
					//Pula o Ponteiro para o proximo caracte (pula o \n)
					if(Modo_Feedback == Tela){
						Ler_Hospede_Memoria(Hospede);
					}else if(Modo_Feedback == Csv){
						Gravar_Hospede_Txt("Arquivos/Hospedes.csv",&Hospede);	
						//CRIAR E CHAMAR FUNCAO PARA GERAR ARQUIVO CSV
					}
					
				}
			}
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			fscanf(Arquivo,"%[^\n]s",Temporario);
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		
	}

	fclose(Arquivo);
		//Fecha o Arquivo;
	}else{
		//Caso modo de abertura seja BIN
		FILE *Arquivo;
		//Cria ponteiro de arquivo
		DADOS_HOSPEDE Hospede;
		char Url[Tamanho2];
		sprintf(Url,"Arquivos/Hospede.bin");
		Arquivo = fopen(Url,"rb");
		int Arquivo_Vazio=0;
		if(Arquivo == NULL){
			Vermelho("\nNao foi possivel abrir o arquivo!");
		}else{
			while(!feof(Arquivo)){
				fread(&Hospede, sizeof(DADOS_HOSPEDE),1,Arquivo);
				if(feof(Arquivo)){
					//Verifica se esta no fim do arquivo
					break;
					//Sai do loop
				}
				for(int i = 0;i < Quantidade_Codigos; i++){
					if(Codigos[i] == Hospede.Codigo){
						if(Modo_Feedback == Tela){
							Ler_Hospede_Memoria(Hospede);
						}else if(Modo_Feedback == Csv){
							Gravar_Hospede_Txt("Arquivos/Hospedes.csv",&Hospede);	
							system("clear");
							printf("\n");
						}
					}
				}
			}
			fclose(Arquivo);	
		}
	}
}
/*void Filtro_Hospede_Sexo(int Modo_Feedback){
	//Funcao para realizar filtro por codigos de hospede
	int Modo_Abertura = Configuracoes();
	int Sexo = 0;
	do{
		Verde("Digite 1 - Masculino\n2 - Feminino\n3 - Outro:\n");
		if(Sexo < 1 || Sexo > 3){
			Vermelho("Digite um valor valido para sexo");
		}
		//Mostra mensagem de erros ao usuario
	}while(Sexo < 1 || Sexo > 3);
	//Loop que repete ate usuario digitiar valores validos para o range de codigos 
	int Quantidade_Codigos = Tamanho2;
	int Codigos[Quantidade_Codigos];
	int Contador_Codigos = 0;
	int Indice_Iguais = 0;
	//Vetor de codigos com a quantidade exata do range de codigos que foi passado, e contador de condigos
	for(int i = Codigo_Inicial; i <= Codigo_Final; i++){
		Codigos[Contador_Codigos] = i;
		Contador_Codigos++;
	}
	if(Modo_Abertura == Arquivo_Texto){
	//Caso modo de abertura seja TXT
	char Url[Tamanho2],Temporario[Tamanho2];
	sprintf(Url,"Arquivos/Hospede.txt");
	//Declara Array com a url
	DADOS_HOSPEDE Hospede;
	//Cria uma variavel do tipo DADOS HOSPEDE;

	FILE *Arquivo;
		//Ponteiro para o arquivo

	Arquivo=fopen(Url,"r");
		//Abre o Arquivo
	int Arquivo_Vazio=0;
		
	
	if(Arquivo==NULL){
		Vermelho("O Arquivo não foi aberto corretamente\n");
	}else{
		do{
			fscanf(Arquivo,"%d",&Hospede.Codigo);
				//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"
				//Expreção Regular
			getc(Arquivo);
			//Pula o Ponteiro para o proximo caractere
			for(int i = 0;i < Quantidade_Codigos; i++){
				if(Codigos[i] == Hospede.Codigo){
					if(feof(Arquivo)){
						//Verifica se esta no fim do arquivo
						break;
						//Sai do loop
					}
					fscanf(Arquivo,"%[^;]s",Hospede.Nome);
					//[^;] Significa que a string tera todos os caracteres ate que se encontre um ";"7
					//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Sexo);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Estado_Civil);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.CPF);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Endereco.Logradouro);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Endereco.Numero);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Endereco.Bairro);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Endereco.Cidade);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Telefone);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Email);
						//Expreção Regular
					getc(Arquivo);
						//Pula o Ponteiro para o proximo caractere
					fscanf(Arquivo,"%[^;]s",Hospede.Data_Nascimento);
						//Expreção Regular
					getc(Arquivo);
					getc(Arquivo);
					//Pula o Ponteiro para o proximo caracte (pula o \n)
					if(Modo_Feedback == Tela){
						Ler_Hospede_Memoria(Hospede);
					}else if(Modo_Feedback == Csv){
						Gravar_Hospede_Txt("Arquivos/Hospedes.csv",&Hospede);	
						//CRIAR E CHAMAR FUNCAO PARA GERAR ARQUIVO CSV
					}
					
				}
			}
			if(feof(Arquivo)){
				//Verifica se esta no fim do arquivo
				break;
				//Sai do loop
			}
			fscanf(Arquivo,"%[^\n]s",Temporario);
		}while(!feof(Arquivo));
			//Entra no loop se não estiver apontando para o final do arquivo;
		
	}

	fclose(Arquivo);
		//Fecha o Arquivo;
	}else{
		//Caso modo de abertura seja BIN
		FILE *Arquivo;
		//Cria ponteiro de arquivo
		DADOS_HOSPEDE Hospede;
		char Url[Tamanho2];
		sprintf(Url,"Arquivos/Hospede.bin");
		Arquivo = fopen(Url,"rb");
		int Arquivo_Vazio=0;
		if(Arquivo == NULL){
			Vermelho("\nNao foi possivel abrir o arquivo!");
		}else{
			while(!feof(Arquivo)){
				fread(&Hospede, sizeof(DADOS_HOSPEDE),1,Arquivo);
				if(feof(Arquivo)){
					//Verifica se esta no fim do arquivo
					break;
					//Sai do loop
				}
				for(int i = 0;i < Quantidade_Codigos; i++){
					if(Codigos[i] == Hospede.Codigo){
						if(Modo_Feedback == Tela){
							Ler_Hospede_Memoria(Hospede);
						}else if(Modo_Feedback == Csv){
							Gravar_Hospede_Txt("Arquivos/Hospedes.csv",&Hospede);	
							system("clear");
							printf("\n");
						}
					}
				}
			}
			fclose(Arquivo);
			
		}
	}

}
*/

#endif