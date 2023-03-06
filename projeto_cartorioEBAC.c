#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos string

int registrar() //função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis que se deseja cadastrar/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis que se deseja cadastrar/string

	printf("Digitar o nº do CPF a ser cadastrado: "); //coletando a informação "CPF" do usuário
	scanf("%s", cpf); //%s refere-se a salvar a string - salvar como cpf
	printf("\n");
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //criando o arquivo no banco de dados
	file = fopen(arquivo, "w"); //w - write/escrever - cria o arquivo
	fprintf(file,cpf); //salvar valor da variável no arquivo
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //a para atualizar o arquivo e não criar um novo
	fprintf(file,", "); //separar variáveis usando a vírgula
	fclose(file); //fechar o arquivo
	
	printf("Digitar o nome a ser cadastrado: "); //coletando a informação "Nome" do usuário
	scanf("%s",nome); //%s refere-se a salvar a string - salvar com arquivo Nome
	printf("\n");
	
	file = fopen(arquivo, "a"); //atualizar arquivo
	fprintf(file,nome); //criar o arquivo Nome
	fclose(file); //fechar o arquivo Nome
	
	file = fopen(arquivo, "a"); //atualizar arquivo
	fprintf(file,", "); //separar variáveis usando a vírgula
	fclose(file); //fechar o arquivo
	
	printf("Digitar o sobrenome a ser cadastrado: "); //coletando a informação "Sobrenome" do usuário
	scanf("%s",sobrenome); //salvar string com arquivo Sobrenome
	printf("\n");
	
	file = fopen(arquivo, "a"); //atualizar arquivo
	fprintf(file,sobrenome); //criar arquivo Sobrenome
	fclose(file); //fechar o arquivo Sobrenome
	
	file = fopen(arquivo, "a"); //atualizar arquivo
	fprintf(file,", "); //separar variáveis usando a vírgula
	fclose(file); //fechar o arquivo

	printf("Digitar o cargo a ser cadastrado: "); //coletando a informação "Cargo" do usuário
	scanf("%s",cargo); //salvar string com arquivo Cargo
	printf("\n");
	
	file = fopen(arquivo, "a"); //atualizar arquivo
	fprintf(file,cargo); //criar arquivo Cargo
	fclose(file); //fechar o arquivo
	printf("\n");
	system("pause");
}


int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200]; //string conteúdo do aqruivo
	
	printf("Digitar o nº de CPF a ser consultado: "); //recebendo qual usuário será consultado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //r de read/ler
	
	if(file == NULL)
	{
		printf("\nArquivo não localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Laço de repetição: salvando na string conteúdo, os 500 caracteres que estão dentro do arquivo e para quando for nulo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	} 
	
	fclose(file);
	system("pause");
}
	
	
int deletar()
{
	char cpf[40];
		
	printf("Digitar o n° de CPF a ser deletado: ");
	scanf("%s",cpf);
		
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\n\nO usuário não se encontra no sistema!\n\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		FILE *file;	
		file = fopen(cpf,"r");
				
		if(file == NULL)
		{
		printf("\n\nUsuário deletado com sucesso!\n\n");
		system("pause");
		}
	}
	
	fclose(file);
}
	

	
int main() //função principal - ponto de entrada no sistema
{
	int opcao=0; //definindo variáveis - main retorna ao 0 quando executar tudo o que precisa
	int x=1;
	char senhadigitada[10]="a"; //acesso usuário
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("*** Cartório da EBAC ***\n\n");
	printf("Login do administrador:\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //compara 2 string, se forem iguais retorna 0
	
	if(comparacao == 0)
	{
		
		for(x=1;x=1;) //sempre retorna no 1 - usuário sai quando ele quiser
		{
			
			system("cls"); //responsável por limpar a tela
			
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
			
			//entrada de dados
			printf("*** Cartório da EBAC ***\n\n"); //início MENU
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do sistema\n");
			printf("\nOpção desejada: "); //final MENU
		
			scanf("%d", &opcao); //armazenamento da escolha do usuário - %d variável inteira
		
			system("cls"); //limpa a tela
		
			switch(opcao) //início seleção do menu - analise variável opção
			{
				case 1:
				registrar(); //chama a função
				break; //encerra a função
				
				case 2:
				consultar();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("\nObrigada por usar nosso sistema!\n");
				printf("\nVolte logo!\n\n");
				return 0;
				break;
				
				default:
				printf("Essa opção não está disponível!\n\n");
				system("pause"); //pausa antes de voltar para a main
				break;
			} //final seleção
		}
	}
	
	else
		printf("\nSenha incorreta!\n\n");
			
}
