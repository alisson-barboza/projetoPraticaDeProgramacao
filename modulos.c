#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"aluno_arquivo.h"
#include"disciplina_arquivo.h"
#include"matricula.h"
#include"modulos.h"


void menu_principal(FILE *arqM, FILE *arqA, FILE *arqD, indice_alunos *ind_aluno, indice_disciplina * ind_disciplina){
	
	char opp;	
	
	
	do{
		system("cls");
		printf("\nSelecione o modulo");
		printf("\n1-Matricula\n2-Disciplina\n3-Aluno\n0-Sair\n");
		printf("\nDigite sua opcao: ");
		
		scanf("%c", &opp); fflush(stdin);
		switch (opp)
		{
		case'1':
			modulo_matricula(arqM, arqD, arqA, ind_aluno, ind_disciplina);
			break;
		case'2':
			modulo_disciplina(arqD, ind_disciplina);
			break;
		case'3':
			modulo_aluno(arqA, ind_aluno);
			break;
		case'0':
			
			
			break;

		default:
			printf("\nOpcao invalida\n");
			break;
		}

	} while (opp != '0');


}


void modulo_aluno(FILE*arqA, indice_alunos *ind_aluno){
	char opp;
	system("cls");

	printf("\nAluno\n");

	do{
		printf("\n1-Cadastrar Aluno\n2-Alterar dados do aluno\n3-Exibir aluno\n4-Remover Aluno\n0-Voltar");
		printf("\nDigite sua opcao: ");
		scanf("%c", &opp); fflush(stdin);
		switch (opp)
		{
		case'1':
			cadastrar_aluno_modulo(arqA, ind_aluno);
			break;
		case'2':
			alterar_aluno_modulo(arqA, ind_aluno);
			break;
		case'3':
			exibir_aluno_modulo(arqA, ind_aluno);
			break;
		case'4':
			remover_aluno_modulo(arqA, ind_aluno);
			break;
		case'0':
			
			break;
		default:
			printf("\nOpcao Invalida\n");
			break;
		}

	} while (opp != '0');
}


void cadastrar_aluno_modulo(FILE * arqA, indice_alunos *ind_aluno){
	char matricula[11];
	int valido;
	do{
		printf("\nDigite a matricula: "); // matricula
		gets(matricula); fflush(stdin);
		valido = validar_matricula(matricula);
		if (valido == 0){
			printf("\nMatricula nao valida");
		}
	} while (valido == 0);


	cadastrar_aluno_arquivo(ind_aluno, arqA, matricula);

}

void alterar_aluno_modulo(FILE * arqA, indice_alunos *ind_aluno){
	char matricula[11];
	int valido;

	do{
		printf("\nDigite a matricula: "); // matricula
		gets(matricula); fflush(stdin);
		valido = validar_matricula(matricula);
		if (valido == 0){
			printf("\nMatricula nao valida");
		}
	} while (valido == 0);

	alterar_aluno_arquivo(ind_aluno, arqA, matricula);

}

void exibir_aluno_modulo(FILE *arqA, indice_alunos *ind_aluno){
	char matricula[11];
	int valido;

	do{
		printf("\nDigite a matricula: "); // matricula
		gets(matricula); fflush(stdin);
		valido = validar_matricula(matricula);
		if (valido == 0){
			printf("\nMatricula nao valida");
		}
	} while (valido == 0);

	exibir_aluno_arquivo(ind_aluno, arqA, matricula);

}

void remover_aluno_modulo(FILE *arqA, indice_alunos *ind_aluno){
	char matricula[11];
	int valido;

	do{
		printf("\nDigite a matricula: "); // matricula
		gets(matricula); fflush(stdin);
		valido = validar_matricula(matricula);
		if (valido == 0){
			printf("\nMatricula nao valida");
		}
	} while (valido == 0);
	remover_aluno_arquivo(&ind_aluno, arqA, matricula);

}




void modulo_disciplina(FILE *arqD, indice_disciplina * ind_disciplina){
	char opp;

	system("cls");
	printf("\nDisciplina\n");

	do{
		printf("\n1-Cadastrar Disciplina\n2-Alterar dados da disciplina\n3-Exibir disciplina\n4-Remover disciplina\n0-Voltar");
		printf("\nDigite sua opcao: ");
		scanf("%c", &opp); fflush(stdin);
		switch (opp)
		{
		case'1':
			cadastrar_disciplina_modulo(arqD, ind_disciplina);
			break;
		case'2':
			alterar_disciplina_modulo(arqD, ind_disciplina);
			break;
		case'3':
			exibir_disciplina_modulo(arqD, ind_disciplina);
			break;
		case'4':
			remover_disciplina_modulo(arqD, ind_disciplina);
			break;
		case'0':
			
			break;
		default:
			printf("\nOpcao Invalida\n");
			break;
		}

	} while (opp != '0');

}

void cadastrar_disciplina_modulo(FILE *arqD, indice_disciplina *ind_disciplina){
	char codigo[9];
	int valido;
	do{
		printf("\nDigite o codigo da disciplina que deseja cadastrar: ");
		gets(codigo); fflush(stdin);
		valido = validar_codigo(codigo);
		if (valido == 0){
			printf("\nCodigo invalido\n");
		}
	} while (valido == 0);

	cadastrar_disciplina_arquivo(&ind_disciplina, arqD, codigo);
}

void alterar_disciplina_modulo(FILE *arqD, indice_disciplina *ind_disciplina){
	char codigo[8];
	int valido;

	do{
		printf("\nDigite o codigo da disciplina que deseja cadastrar: ");
		gets(codigo); fflush(stdin);
		valido = validar_codigo(codigo);
		if (valido == 0){
			printf("\nCodigo invalido\n");
		}
	} while (valido == 0);

	alterar_disciplina_arquivo(ind_disciplina, arqD, codigo);
}

void exibir_disciplina_modulo(FILE *arqD, indice_disciplina *ind_disciplina){
	char codigo[8];
	int valido;
	do{
		printf("\nDigite o codigo da disciplina que deseja exibir: ");
		gets(codigo); fflush(stdin);
		valido = validar_codigo(codigo);
		if (valido == 0){
			printf("\nCodigo invalido\n");
		}
	} while (valido == 0);

	exibir_disciplina_arquivo(ind_disciplina, arqD, codigo);
}

void remover_disciplina_modulo(FILE *arqD, indice_disciplina *ind_disciplina){
	char codigo[8];
	int valido;

	do{
		printf("\nDigite o codigo da disciplina que deseja cadastrar: ");
		gets(codigo); fflush(stdin);
		valido = validar_codigo(codigo);
		if (valido == 0){
			printf("\nCodigo invalido\n");
		}
	} while (valido == 0);

	remover_disciplina_arquivo(&ind_disciplina, arqD, codigo);

}

void modulo_matricula(FILE *arqM, FILE *arqD, FILE*arqA, indice_alunos * ind_aluno, indice_disciplina * ind_disciplina){
	char opp;

	system("cls");
	printf("\nMatricula\n");

	do{
		printf("\n1-Cadastrar matricula\n2-Exibir disciplinas de um aluno\n3-Exibir alunos de uma disciplina\n4-Remover matricula\n0-Voltar");
		printf("\nDigite sua opcao: ");
		scanf("%c", &opp); fflush(stdin);
		switch (opp)
		{
		case'1':
			realizar_matricula(arqM, arqD, arqA, ind_disciplina, ind_aluno);
			break;
		case'2':
			exibir_disciplinas_d1aluno_modulo(arqM, arqD, ind_disciplina);
			break;
		case'3':
			exibir_alunos_d1disciplina_modulo(arqM, arqA, ind_aluno);
			break;
		case'4':
			remover_matricula(arqM, arqD, arqA, ind_disciplina, ind_aluno);
			break;
		case'0':
			
			break;
		default:
			printf("\nOpcao Invalida\n");
			break;
		}

	} while (opp != '0');

}

void exibir_disciplinas_d1aluno_modulo(FILE *arqM, FILE *arqD, indice_disciplina * ind_disciplina){
	char matricula[11];
	int valido;
	do{
		printf("\nDigite a matricula: ");
		gets(matricula); fflush(stdin);
		valido = validar_matricula(matricula);
		if (valido == 0){
			printf("\nMatricula nao valida");
		}
	} while (valido == 0);

	exibir_disciplinas_d1aluno(arqM, arqD, ind_disciplina, matricula);

}

void exibir_alunos_d1disciplina_modulo(FILE *arqM, FILE*arqA, indice_alunos * ind_aluno){
	char codigo[8];
	int valido;
	do{
		printf("\nDigite o codigo da disciplina: ");
		gets(codigo); fflush(stdin);
		valido = validar_codigo(codigo);
		if (valido == 0){
			printf("\nCodigo invalido\n");
		}
	} while (valido == 0);

	exibir_alunos_d1disciplina(arqM, arqA, ind_aluno, codigo);
}