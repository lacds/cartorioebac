#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos string

int registrar() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis que se deseja cadastrar/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis que se deseja cadastrar/string

	printf("Digitar o n� do CPF a ser cadastrado: "); //coletando a informa��o "CPF" do usu�rio
	scanf("%s", cpf); //%s refere-se a salvar a string - salvar como cpf
	printf("\n");
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //criando o arquivo no banco de dados
	file = fopen(arquivo, "w"); //w - write/escrever - cria o arquivo
	fprintf(file,cpf); //salvar valor da vari�vel no arquivo
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //a para atualizar o arquivo e n�o criar um novo
	fprintf(file,", "); //separar vari�veis usando a v�rgula
	fclose(file); //fechar o arquivo
	
	printf("Digitar o nome a ser cadastrado: "); //coletando a informa��o "Nome" do usu�rio
	scanf("%s",nome); //%s refere-se a salvar a string - salvar com arquivo Nome
	printf("\n");
	
	file = fopen(arquivo, "a"); //atualizar arquivo
	fprintf(file,nome); //criar o arquivo Nome
	fclose(file); //fechar o arquivo Nome
	
	file = fopen(arquivo, "a"); //atualizar arquivo
	fprintf(file,", "); //separar vari�veis usando a v�rgula
	fclose(file); //fechar o arquivo
	
	printf("Digitar o sobrenome a ser cadastrado: "); //coletando a informa��o "Sobrenome" do usu�rio
	scanf("%s",sobrenome); //salvar string com arquivo Sobrenome
	printf("\n");
	
	file = fopen(arquivo, "a"); //atualizar arquivo
	fprintf(file,sobrenome); //criar arquivo Sobrenome
	fclose(file); //fechar o arquivo Sobrenome
	
	file = fopen(arquivo, "a"); //atualizar arquivo
	fprintf(file,", "); //separar vari�veis usando a v�rgula
	fclose(file); //fechar o arquivo

	printf("Digitar o cargo a ser cadastrado: "); //coletando a informa��o "Cargo" do usu�rio
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
	char conteudo[200]; //string conte�do do aqruivo
	
	printf("Digitar o n� de CPF a ser consultado: "); //recebendo qual usu�rio ser� consultado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //r de read/ler
	
	if(file == NULL)
	{
		printf("\nArquivo n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //La�o de repeti��o: salvando na string conte�do, os 500 caracteres que est�o dentro do arquivo e para quando for nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	} 
	
	fclose(file);
	system("pause");
}
	
	
int deletar()
{
	char cpf[40];
		
	printf("Digitar o n� de CPF a ser deletado: ");
	scanf("%s",cpf);
		
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\n\nO usu�rio n�o se encontra no sistema!\n\n");
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
		printf("\n\nUsu�rio deletado com sucesso!\n\n");
		system("pause");
		}
	}
	
	fclose(file);
}
	

	
int main() //fun��o principal - ponto de entrada no sistema
{
	int opcao=0; //definindo vari�veis - main retorna ao 0 quando executar tudo o que precisa
	int x=1;
	char senhadigitada[10]="a"; //acesso usu�rio
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("*** Cart�rio da EBAC ***\n\n");
	printf("Login do administrador:\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //compara 2 string, se forem iguais retorna 0
	
	if(comparacao == 0)
	{
		
		for(x=1;x=1;) //sempre retorna no 1 - usu�rio sai quando ele quiser
		{
			
			system("cls"); //respons�vel por limpar a tela
			
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
			
			//entrada de dados
			printf("*** Cart�rio da EBAC ***\n\n"); //in�cio MENU
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do sistema\n");
			printf("\nOp��o desejada: "); //final MENU
		
			scanf("%d", &opcao); //armazenamento da escolha do usu�rio - %d vari�vel inteira
		
			system("cls"); //limpa a tela
		
			switch(opcao) //in�cio sele��o do menu - analise vari�vel op��o
			{
				case 1:
				registrar(); //chama a fun��o
				break; //encerra a fun��o
				
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
				printf("Essa op��o n�o est� dispon�vel!\n\n");
				system("pause"); //pausa antes de voltar para a main
				break;
			} //final sele��o
		}
	}
	
	else
		printf("\nSenha incorreta!\n\n");
			
}
