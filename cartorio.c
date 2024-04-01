#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por fazer as strings funcionarem

int registrar(){ // Fun��o respopns�vel por registrar usu�rios sistema
	printf("#-#-# Voc� escolheu REGISTRAR um novo aluno! #-#-#\n\n");
	
	// Definindo as vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim das vari�veis 
	
	
	printf("Digite o CPF a ser cadastrado: "); //Pedindo o cpf para cadastro
	scanf("%s", cpf); // Alocando o valor digitado na vari�vel cpf || (%s � usado para salvar a string)
	
	strcpy(arquivo, cpf); // copiando o valor digitado em cpf para a vari�vel arquivo
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" � para escrever nesse arquivo
	fprintf(file, cpf); // escreve o valor digitado em cpf no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Para atualizar o arquivo
	fprintf(file, ","); // Adicionando a virgula para separar as informa��es
	fclose(file); // fechando o arquivo
	
	printf("Digite o NOME a ser cadastrado: "); // Pedindo ao usu�rio para inserir o nome de cadastro
	scanf("%s", nome); // Inserindo os dados na vari�vel nome
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" para Atualizar o arquivo
	fprintf(file, nome); // Inserindo os dados da vari�vel nome no arquivo
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Atualizando o arquivo
	fprintf(file, ","); // Inserindo a virgula para separa��o dos dados
	fclose(file); // fechando o arquivo
	
	printf("Digite o SOBRENOME a ser cadastrado: "); // Perguntando o sobrenome a cadastrar
	scanf("%s", sobrenome); // Guardando o que foi escrito na vari�vel sobrenome
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e atualizando
	fprintf(file, sobrenome); // Inserindo os dados da vari�vel sobrenome no arquivo
	fclose(file); // fechando o arquivo
	
	file = fopen(arquivo, "a"); // Atualizando o arquivo
	fprintf(file, ","); // Inserindo a virgula para separa��o dos dados
	fclose(file);  // fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Pedindo o cargo da pessoa que est� sendo cadastrada
	scanf("%s", cargo); // Adicionando a informa��o na vari�vel cargo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo para atualizar com novos dados
	fprintf(file, cargo); // Inserindo os dados da vari�vel cargo no arquivo
	fclose(file); // fechando o arquivo
	
	
	
	system("pause"); // Pausando o sistema 
}

int consultar(){ // Fun��o respons�vel por fazer a consulta dos usu�rios.
	setlocale(LC_ALL, "Portuguese"); // Definindo o idioma 
	printf("#-#-# Voc� escolheu CONSULTAR um aluno! #-#-#\n\n"); // Cabe�ario da tela
	
	//cria��o das vari�veis
	char cpf[40];
	char conteudo[200];
	char *token;
	// Finaliza��o das vari�veis
	
	printf("Digite o CPF a ser consultado: "); // Pedindo informa��es para o usu�rio
	scanf("%s", cpf); // Armazenando o valor digitado na vari�vel cpf
	
	FILE *file; 
	file = fopen(cpf, "r"); // Busca pelo arquivo com valor da vari�vel CPF, R de "read" a informa��o
	
	if(file == NULL){ // Uma condi��o para verificar se existe o CPF digitado no banco de dados
		printf("\n[ERRO] CPF n�o encontrado!\n\n");
		
	}
	
	// Enquanto tiver informa��o dentro do "file", armazenar na vari�vel conte�do. Se for NULL, sai do looping
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas s�o as informa��es encontradas:\n");
		
		
		token = strtok(conteudo, ","); // Quebrando a linha dos dados na "," e adicionando a informa��o na vari�vel token
		printf("CPF: %s\n", token); // Adionando a palavra "CPF" antes de exibir o valor correspondente
		
		token = strtok(NULL, ",");
		printf("NOME: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("SOBRENOME: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("CARGO: %s\n", token);
		
		printf("\n\n");
		
		
	}
	
	
	system("pause"); // Pausando o sistema
}

int deletar(){ // Fun��o para deletar um usu�rio da base de dados
	printf("#-#-# Voc� escolheu DELETAR um aluno #-#-#\n"); // Topo da tela
	
	// Criando vari�vel
	char cpf[40];
	// Fim das vari�veis
	
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // Pedindo o dado para o usu�rio
	scanf("%s", cpf); // Alocando o cpf digitado na vari�vel cpf
	
	
	FILE *file; // Trabalhando com o arquivo
	file = fopen(cpf, "r"); // Abrindo o arquivo e usando o "r" para ler
	fclose(file); // Fechando o arquivo
	
	if(file == NULL){ // Condi��o que se n�o for encontrado o CPF, retornar uma informa��o
		printf("[ERRO] CPF N�O encontrado na base de dados!\n"); // Informa��o retornada caso o CPF n�o seja encontrado
		system("pause"); // Pausando o sistema
	}else if(remove(cpf) == 0){ // Deletando os dados e verificando se foi deletado, se sim informar
		printf("Deletado com sucesso!\n"); // Informando ao usu�rio que o arquivo foi deletado com sucesso
	}
	
	
	
	system("pause"); // Pausando o sistema
}


int main(){ // Fun��o da tela principal do programa

	// Definindo vari�vel
	int opcao=0; 
	int laco=1; 
	// Fim das vari�veis
	
	
	setlocale(LC_ALL, "Portuguese"); // Definindo o idioma 
	
	for(laco=1;laco=1; laco=4){ // Inicio do looping
		
		system("cls"); // Limpando a tela
		
		printf("#-#-# Cart�rio EBAC #-#-#\n\n"); // In�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n"); // Pedindo para o usu�rio escolher uma op��o
		printf("\t1 - Registrar um aluno\n"); // Op��o 1
		printf("\t2 - Consultar um aluno\n"); // Op��o 2
		printf("\t3 - Deletar um aluno\n"); // Op��o 3
		printf("\t4 - Para sair do programa\n\n"); // Op��o 4
		printf("Op��o: "); // Fim do menu
		
		scanf("%d", &opcao); // Alocando a resposta do usu�rio na vari�vel opcao
		
		system("cls"); // Limpando a tela de comando
		
		switch(opcao){ // Inicio do switch case (para o usu�rio escolher uma op��o)
			case 1:
			registrar(); // Chamando a fun��o de registrar
			break;
		
			case 2:
			consultar(); // Chamando a fun��o de consultar
			break;
		
			case 3:
			deletar(); // Chamando a fun��o de deletar
			break;
			
			case 4:
			printf("Saindo do sistema...");
			//system("pause");
			scanf("%d", &laco);
			break;
			
			default:
			printf("[ERRO] Voc� escolheu uma op��o inv�lida, tente novamente!\n"); // Caso o usu�rio tenha escolhido uma op��o inv�lida
			system("pause");
			break;
		
			//printf("#-#-# Esse software foi desenvolvido por Jo�o Vitor Morita como aluno da EBAC. #-#-#\n");
		} // Fim do switch case
	} //Fim do looping
	
}
