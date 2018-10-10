#include"aluno.h"
#include"validacao.h"

void cadastrar_aluno_arquivo(indice_alunos *ind, FILE *arqA, char mat[]);
void alterar_aluno_arquivo(indice_alunos *ind, FILE *arqA, char mat[]);
void exibir_aluno_arquivo(indice_alunos*ind, FILE *arqA, char mat[]);
void remover_aluno_arquivo(indice_alunos**ind, FILE *arqA, char mat[]);