#include"type_matricula.h"
#include"disciplina_arquivo.h"
#include"aluno_arquivo.h"
#include"validacao.h"

//validar aluno e validar disciplina serão chamadas no main, estarão contidas no .c de validação futuramente


//Realizar matricula 
void realizar_matricula(FILE *arqM, FILE *arqD, FILE *arqA, indice_disciplina * ind_disciplina, indice_alunos * ind_aluno);
int checar_matricula_repetida(FILE * arqM, char mat[], char cod[]);

int checar_horario_disciplina(FILE * arqM, FILE * arqD, char mat[], char horario, indice_disciplina *ind);
int checar_horario_repetido(FILE *arqD, char codigo[], indice_disciplina *ind, char horario);
void matricular_aluno_definitivo(FILE *arqM, FILE *arqD, FILE *arqA, int pos_aluno, int pos_disciplina, aluno aux_aluno, disciplina aux_disciplina);
// ------- 
// exibir 
void exibir_disciplinas_d1aluno(FILE *arqM, FILE *arqD, indice_disciplina *ind_disciplina, char mat[]);
void exibir_alunos_d1disciplina(FILE *arqM, FILE *arqA, indice_alunos *ind_alunos, char codig[]);
// -----

void remover_matricula(FILE *arqM, FILE *arqD, FILE *arqA, indice_disciplina * ind_disciplina, indice_alunos * ind_aluno);