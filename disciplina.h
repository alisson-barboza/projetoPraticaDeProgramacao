#include"type_disciplina.h"
#include"type_arvore_disciplina.h"
#include<stdio.h>
#include<string.h>

void inserir_disciplina_arvore(indice_disciplina * ind, char cod[]);
void inserir_no_disciplina(arvore_disciplina ** ind, arvore_disciplina * no);
void remover_disciplina_arvore(indice_disciplina *ind, char cod[]);
void remover_no_disciplina(arvore_disciplina **no, char cod[]);
void definir_remocao_disciplina(arvore_disciplina **no);
arvore_disciplina * maiorDireita_disciplina(arvore_disciplina **no);
int buscar_disciplina_arvore(indice_disciplina *ind, char cod[]);
int buscar_disciplina(arvore_disciplina *no, char cod[]);


void criar_arvore_disciplina(indice_disciplina **ind, FILE *arqD);
void remover_arvore_disciplina(indice_disciplina **ind);
void remover_todas_disciplinas(arvore_disciplina **arv);