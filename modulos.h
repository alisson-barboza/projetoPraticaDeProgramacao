#include<stdio.h>
#include"matricula.h"
FILE * criar_Arquivo(char nome[]);



void menu_principal(FILE *arqM, FILE *arqA, FILE *arqD, indice_alunos *ind_aluno, indice_disciplina * ind_disciplina);
void modulo_aluno(FILE*arqA, indice_alunos *ind_aluno);
void cadastrar_aluno_modulo(FILE * arqA, indice_alunos *ind_aluno);
void alterar_aluno_modulo(FILE * arqA, indice_alunos *ind_aluno);
void exibir_aluno_modulo(FILE *arqA, indice_alunos *ind_aluno);
void remover_aluno_modulo(FILE *arqA, indice_alunos *ind_aluno);
void modulo_disciplina(FILE *arqD, indice_disciplina * ind_disciplina);
void cadastrar_disciplina_modulo(FILE *arqD, indice_disciplina *ind_disciplina);
void alterar_disciplina_modulo(FILE *arqD, indice_disciplina *ind_disciplina);
void exibir_disciplina_modulo(FILE *arqD, indice_disciplina *ind_disciplina);
void remover_disciplina_modulo(FILE *arqD, indice_disciplina *ind_disciplina);
void modulo_matricula(FILE *arqM, FILE *arqD, FILE*arqA, indice_alunos * ind_aluno, indice_disciplina * ind_disciplina);
void exibir_disciplinas_d1aluno_modulo(FILE *arqM, FILE *arqD, indice_disciplina * ind_disciplina);
void exibir_alunos_d1disciplina_modulo(FILE *arqM, FILE*arqA, indice_alunos * ind_aluno);