#ifndef estrutura_arvore_aluno
#define estrutura_arvore_aluno

typedef struct arvore_aluno{
	int pos;
	struct arvore_aluno *esq, *dir;
	char matricula[11];

}arvore_aluno;

typedef struct indice_alunos{
	arvore_aluno *no;
	int indice;

}indice_alunos;

#endif