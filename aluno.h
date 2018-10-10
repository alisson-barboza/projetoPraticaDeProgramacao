#include"type_aluno.h"
#include"type_arvore.h"
#include<stdio.h>

void inserir_aluno_arvore(indice_alunos *ind, char mat[]);
void inserir_no_aluno(arvore_aluno **ind, arvore_aluno *no);
void remover_aluno_arvore(indice_alunos *ind, char mat[]);
void remover_no_aluno(arvore_aluno **no, char mat[]);
void definir_remocao_aluno(arvore_aluno **no);
arvore_aluno * maiorDireita_aluno(arvore_aluno **no);
int buscar_aluno_arvore(indice_alunos *ind, char mat[]);
int buscar_aluno(arvore_aluno *no, char mat[]);

void criar_arvore_aluno(indice_alunos **ind, FILE *arqA);
void remover_arvore_aluno(indice_alunos **ind);
void remover_todos_alunos(arvore_aluno ** arv);