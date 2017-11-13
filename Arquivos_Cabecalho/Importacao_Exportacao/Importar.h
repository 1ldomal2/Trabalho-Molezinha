#ifndef _Importar_
#define _Importar_

void Importacao(){
	int Loop=1,Indice[]={1,1,1,1,1,1,1,1,1};

	DADOS_HOTEL *Hotel = malloc(sizeof(DADOS_HOTEL)); 
	DADOS_HOSPEDE *Hospede = malloc(sizeof(DADOS_HOSPEDE)); 
	ACOMODACOES *Acomodacoes=malloc(sizeof(ACOMODACOES));
	CODIGO_CATEGORIA *Codigo_Categoria = malloc(sizeof(CODIGO_CATEGORIA)); 
	PRODUTOS *Produtos = malloc(sizeof(PRODUTOS)); 
	FORNECEDORES *Fornecedores = malloc(sizeof(FORNECEDORES)); 
	FUNCIONARIOS *Funcionarios = malloc(sizeof(FUNCIONARIOS)); 
	RESERVA *Reserva = malloc(sizeof(RESERVA)); 
	FLUXO *Fluxo = malloc(sizeof(FLUXO));

	char Url[Tamanho2],Temp[Tamanho2];
	char Tag[Tamanho2];
	int Contador=0;
	FILE *Arquivo;
	//{ Cria as Variaveis }//
	
	
	
	Verde("Caso o Arquivo esteja nesta pasta digite apenas o nome do arquivo caso contrario digite todo o caminho");
	printf("\nDigite o Local do Arquivo:");
	scanf("%s",Url);
	strcat(Url,".xml");
	//{ Pega url do arquivo }//
	
	
	
	Arquivo=fopen(Url,"r");
	if(Arquivo==NULL){
		Vermelho(Url);
		printf(" não é um arquivo válido\n");
		return;
	}else{
	//{ Abre arquivo em modo txt }//

		fscanf(Arquivo,"%[^<]s",Temp);//Le a até o inicio da tag
		getc(Arquivo);//pula<
		fscanf(Arquivo,"%[^>]s",Tag);//pula até o >
		getc(Arquivo);//pula>
		getc(Arquivo);//pula\n
		//Le tag 
		
				if(strcmp(Tag,"tabela=DADOS_HOTEL")==0){ //Verifica se está na  tabela Hospede
			while(Loop){
				fscanf(Arquivo,"%[^<]s",Temp);//Le a até o inicio da tag
				getc(Arquivo);//pula<
				fscanf(Arquivo,"%[^>]s",Tag);//pula até o >
				getc(Arquivo);//pula>
				getc(Arquivo);//pula\n
				//Le tag
				
				if(strcmp (Tag,"/tabela")==0){
					Indice[0]--;//Corrige o Indice
					for (int i = 0; i < Indice[0]; ++i)
					{
						
						Gravar_Hotel_Txt("Arquivos/IMPORTADO",&Hotel[i]);
						system("clear");
					}
					break;//significa que chegou ao fim da tag
				}else{
					if(strcmp (Tag,"registro")==0){//Entramos em uma nova reserva

						Hotel=realloc(Hotel,Indice[0]*sizeof(DADOS_HOTEL));//Realoca o ponteiro

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%d",&Hotel[Indice[0]-1].Codigo);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Nome_Fantasia);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Razao_Social);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Inscricao_Estadual);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].CNPJ);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Endereco.Logradouro);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Endereco.Numero);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Endereco.Bairro);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Endereco.Cidade);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Telefone);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Email);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Dono_Gerente);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Telefone_Gerente);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Check_in);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%[^<]s",Hotel[Indice[0]-1].Check_out);
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);

						fscanf(Arquivo,"%[^>]s",Temp);//pula até o >
						getc(Arquivo);
						fscanf(Arquivo,"%d",&Hotel[Indice[0]-1].Lucro);				
						fscanf(Arquivo,"%[^\n]s",Temp);//pula até o \n
						getc(Arquivo);
						
						
					}else{
						if(!strcmp (Tag,"/registro")){
							Indice[0]++;//Adiciona um ao indice quando fechar a tag ou seja um reserva foi salva na memoria
						}
					}
				}
			}
		}
	}
}

#endif