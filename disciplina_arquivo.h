#include"disciplina.h"
#include"validacao.h"

void cadastrar_disciplina_arquivo(indice_disciplina **ind, FILE *arqD, char cod[]);
void alterar_disciplina_arquivo(indice_disciplina *ind, FILE *arqD, char cod[]);
void exibir_disciplina_arquivo(indice_disciplina * ind, FILE *arqD, char cod[]);
void remover_disciplina_arquivo(indice_disciplina ** ind, FILE *arqD, char cod[]);