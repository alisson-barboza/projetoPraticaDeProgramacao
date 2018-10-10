#ifndef estrutura_arvore_disciplina
#define estrutura_arvore_disciplina

typedef struct arvore_disciplina{
	struct arvore_disciplina *esq, *dir;
	int pos;
	char codigo[8];
}arvore_disciplina;

typedef struct indice_disciplina{
	struct arvore_disciplina * no;
	int indice;
}indice_disciplina;

#endif