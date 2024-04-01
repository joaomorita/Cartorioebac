#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por fazer as strings funcionarem

int registrar(){ // Função respopnsável por registrar usuários sistema
	printf("#-#-# Você escolheu REGISTRAR um novo aluno! #-#-#\n\n");
	
	// Definindo as variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim das variáveis 
	
	
	printf("Digite o CPF a ser cadastrado: "); //Pedindo o cpf para cadastro
	scanf("%s", cpf); // Alocando o valor digitado na variável cpf || (%s é usado para salvar a string)
	
	strcpy(arquivo, cpf); // copiando o valor digitado em cpf para a variável arquivo
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" é para escrever nesse arquivo
	fprintf(file, cpf); // escreve o valor digitado em cpf no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Para atualizar o arquivo
	fprintf(file, ","); // Adicionando a virgula para separar as informações
	fclose(file); // fechando o arquivo
	
	printf("Digite o NOME a ser cadastrado: "); // Pedindo ao usuário para inserir o nome de cadastro
	scanf("%s", nome); // Inserindo os dados na variável nome
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" para Atualizar o arquivo
	fprintf(file, nome); // Inserindo os dados da variável nome no arquivo
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Atualizando o arquivo
	fprintf(file, ","); // Inserindo a virgula para separação dos dados
	fclose(file); // fechando o arquivo
	
	printf("Digite o SOBRENOME a ser cadastrado: "); // Perguntando o sobrenome a cadastrar
	scanf("%s", sobrenome); // Guardando o que foi escrito na variável sobrenome
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo e atualizando
	fprintf(file, sobrenome); // Inserindo os dados da variável sobrenome no arquivo
	fclose(file); // fechando o arquivo
	
	file = fopen(arquivo, "a"); // Atualizando o arquivo
	fprintf(file, ","); // Inserindo a virgula para separação dos dados
	fclose(file);  // fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Pedindo o cargo da pessoa que está sendo cadastrada
	scanf("%s", cargo); // Adicionando a informação na variável cargo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo para atualizar com novos dados
	fprintf(file, cargo); // Inserindo os dados da variável cargo no arquivo
	fclose(file); // fechando o arquivo
	
	
	
	system("pause"); // Pausando o sistema 
}

int consultar(){ // Função responsável por fazer a consulta dos usuários.
	setlocale(LC_ALL, "Portuguese"); // Definindo o idioma 
	printf("#-#-# Você escolheu CONSULTAR um aluno! #-#-#\n\n"); // Cabeçario da tela
	
	//criação das variáveis
	char cpf[40];
	char conteudo[200];
	char *token;
	// Finalização das variáveis
	
	printf("Digite o CPF a ser consultado: "); // Pedindo informações para o usuário
	scanf("%s", cpf); // Armazenando o valor digitado na variável cpf
	
	FILE *file; 
	file = fopen(cpf, "r"); // Busca pelo arquivo com valor da variável CPF, R de "read" a informação
	
	if(file == NULL){ // Uma condição para verificar se existe o CPF digitado no banco de dados
		printf("\n[ERRO] CPF não encontrado!\n\n");
		
	}
	
	// Enquanto tiver informação dentro do "file", armazenar na variável conteúdo. Se for NULL, sai do looping
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações encontradas:\n");
		
		
		token = strtok(conteudo, ","); // Quebrando a linha dos dados na "," e adicionando a informação na variável token
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

int deletar(){ // Função para deletar um usuário da base de dados
	printf("#-#-# Você escolheu DELETAR um aluno #-#-#\n"); // Topo da tela
	
	// Criando variável
	char cpf[40];
	// Fim das variáveis
	
	
	printf("Digite o CPF do usuário a ser deletado: "); // Pedindo o dado para o usuário
	scanf("%s", cpf); // Alocando o cpf digitado na variável cpf
	
	
	FILE *file; // Trabalhando com o arquivo
	file = fopen(cpf, "r"); // Abrindo o arquivo e usando o "r" para ler
	fclose(file); // Fechando o arquivo
	
	if(file == NULL){ // Condição que se não for encontrado o CPF, retornar uma informação
		printf("[ERRO] CPF NÃO encontrado na base de dados!\n"); // Informação retornada caso o CPF não seja encontrado
		system("pause"); // Pausando o sistema
	}else if(remove(cpf) == 0){ // Deletando os dados e verificando se foi deletado, se sim informar
		printf("Deletado com sucesso!\n"); // Informando ao usuário que o arquivo foi deletado com sucesso
	}
	
	
	
	system("pause"); // Pausando o sistema
}


int main(){ // Função da tela principal do programa

	// Definindo variável
	int opcao=0; 
	int laco=1; 
	// Fim das variáveis
	
	
	setlocale(LC_ALL, "Portuguese"); // Definindo o idioma 
	
	for(laco=1;laco=1; laco=4){ // Inicio do looping
		
		system("cls"); // Limpando a tela
		
		printf("#-#-# Cartório EBAC #-#-#\n\n"); // Início do menu
		printf("Escolha a opção desejada do menu: \n\n"); // Pedindo para o usuário escolher uma opção
		printf("\t1 - Registrar um aluno\n"); // Opção 1
		printf("\t2 - Consultar um aluno\n"); // Opção 2
		printf("\t3 - Deletar um aluno\n"); // Opção 3
		printf("\t4 - Para sair do programa\n\n"); // Opção 4
		printf("Opção: "); // Fim do menu
		
		scanf("%d", &opcao); // Alocando a resposta do usuário na variável opcao
		
		system("cls"); // Limpando a tela de comando
		
		switch(opcao){ // Inicio do switch case (para o usuário escolher uma opção)
			case 1:
			registrar(); // Chamando a função de registrar
			break;
		
			case 2:
			consultar(); // Chamando a função de consultar
			break;
		
			case 3:
			deletar(); // Chamando a função de deletar
			break;
			
			case 4:
			printf("Saindo do sistema...");
			//system("pause");
			scanf("%d", &laco);
			break;
			
			default:
			printf("[ERRO] Você escolheu uma opção inválida, tente novamente!\n"); // Caso o usuário tenha escolhido uma opção inválida
			system("pause");
			break;
		
			//printf("#-#-# Esse software foi desenvolvido por João Vitor Morita como aluno da EBAC. #-#-#\n");
		} // Fim do switch case
	} //Fim do looping
	
}
