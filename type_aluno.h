#ifndef estrutura_aluno
#define estrutura_aluno

typedef struct aluno{
	int qtd_disciplinas, status;
	//12 pq eu posso usar o strlen para checar se a string é maior do que o necessario
	
	char nome[100], email[50], telefone[20], matricula[12];
	float media_anterior;

}aluno;
#endif
