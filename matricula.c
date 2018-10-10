#include"matricula.h"
#include<time.h>


//Realizar matricula 
void realizar_matricula(FILE *arqM, FILE *arqD, FILE *arqA, indice_disciplina * ind_disciplina, indice_alunos * ind_aluno){
	//Pedir matricula e codigo da disciplina aqui dentro
	//validar e checar se existe
	char mat[11], codigo[9];
	aluno aux_aluno;
	disciplina aux_disciplina;
	int pos_aluno, pos_disciplina;
	int status, valido;


	do{
		printf("\nDigite a matricula: "); // matricula
		gets(aux_aluno.matricula); fflush(stdin);
		valido = validar_matricula(aux_aluno.matricula);
		if (valido == 0){
			printf("\nMatricula nao valida");
		}
	} while (valido == 0);

	do{
		printf("\nDigite o codigo da disciplina que deseja cadastrar: ");
		gets(codigo); fflush(stdin);
		valido = validar_codigo(codigo);
		if (valido == 0){
			printf("\nCodigo invalido\n");
		}
	} while (valido == 0);

	pos_disciplina = buscar_disciplina_arvore(ind_disciplina, codigo);
	pos_aluno = buscar_aluno_arvore(ind_aluno, aux_aluno.matricula);


	strcpy(aux_disciplina.codigo, codigo);

	

	if (pos_aluno != -1){
		if (pos_disciplina != -1){
			fseek(arqA, pos_aluno * sizeof(aluno), 0);
			fseek(arqD, pos_disciplina * sizeof(disciplina), 0);
			status = fread(&aux_aluno, sizeof(aluno), 1, arqA);
			if (status != 1){
				printf("\nErro de Leitura\n");
			}
			else{
				status = fread(&aux_disciplina, sizeof(disciplina), 1, arqD);
				if (status != 1){
					printf("\nErro de Leitura\n");
				}
				else{
					//checar a media anterior e a qtd de disciplinas para saber se posso colocar ele
					if (aux_aluno.media_anterior < 5 && aux_aluno.qtd_disciplinas < 3){
						if (aux_disciplina.total_vagas > aux_disciplina.vagas_ocupadas){
							if (checar_matricula_repetida(arqM, aux_aluno.matricula, aux_disciplina.codigo)){//função para checar se o aluno já está matriculado
								if (checar_horario_disciplina(arqM, arqD, aux_aluno.matricula, aux_disciplina.horario, ind_disciplina)){
									//funcao checa se horarios se chocam
									matricular_aluno_definitivo(arqM, arqD, arqA, pos_aluno, pos_disciplina, aux_aluno, aux_disciplina);//procedimento para realizar a matricula do aluno em definitivo apos todas as checagens
								}
								else{
									printf("\nO aluno ja esta matriculado em outra disciplina no mesmo horario\n");
								}
							}
							else{
								printf("\nO aluno ja esta matriculado nesta desciplina\n");
							}
						}
						else{
							printf("\nDisciplina atingiu o numero maximo de vagas\n");
						}
					}
					else if (aux_aluno.media_anterior >= 5 && aux_aluno.media_anterior < 7 && aux_aluno.qtd_disciplinas < 5){
						if (aux_disciplina.total_vagas > aux_disciplina.vagas_ocupadas){
							if (checar_matricula_repetida(arqM, aux_aluno.matricula, aux_disciplina.codigo)){//função para checar se o aluno já está matriculado
								if (checar_horario_disciplina(arqM, arqD, aux_aluno.matricula, aux_disciplina.horario, ind_disciplina)){
									//funcao checa se horarios se chocam
									matricular_aluno_definitivo(arqM, arqD, arqA, pos_aluno, pos_disciplina, aux_aluno, aux_disciplina);//procedimento para realizar a matricula do aluno em definitivo apos todas as checagens
								}
								else{
									printf("\nO aluno ja esta matriculado em outra disciplina no mesmo horario\n");
								}
							}
							else{
								printf("\nO aluno ja esta matriculado nesta desciplina\n");
							}
						}
						else{
							printf("\nDisciplina atingiu o numero maximo de vagas\n");
						}
					}
					else if (aux_aluno.media_anterior >= 7 && aux_aluno.qtd_disciplinas < 6){
						if (aux_disciplina.total_vagas > aux_disciplina.vagas_ocupadas){
							if (checar_matricula_repetida(arqM, aux_aluno.matricula, aux_disciplina.codigo)){//função para checar se o aluno já está matriculado
								if (checar_horario_disciplina(arqM, arqD, aux_aluno.matricula, aux_disciplina.horario, ind_disciplina)){
									//funcao checa se horarios se chocam
									matricular_aluno_definitivo(arqM, arqD, arqA, pos_aluno, pos_disciplina, aux_aluno, aux_disciplina);//procedimento para realizar a matricula do aluno em definitivo apos todas as checagens
								}
								else{
									printf("\nO aluno ja esta matriculado em outra disciplina no mesmo horario\n");
								}
							}
							else{
								printf("\nO aluno ja esta matriculado nesta desciplina\n");
							}
						}
						else{
							printf("\nDisciplina atingiu o numero maximo de vagas\n");
						}
					}
					else{
						printf("\nA media do aluno nao permite que ele se matricule em mais disciplinas\n");
					}



				}

			}

		}
		else{
			printf("\nDisciplina nao cadastrada\n");
		}
	}
	else{
		printf("\nAluno nao cadastrado\n");
	}
}

int checar_matricula_repetida(FILE * arqM, char mat[], char cod[]){
	matricula m;
	int status;

	fseek(arqM, 0, 0);

	while (1){
		status = fread(&m, sizeof(matricula), 1, arqM);
		if (status != 1){
			if (!feof(arqM)){
				printf("\nErro de Leitura\n");
			}
			else{
				break;
			}
		}
		else{
			if (strcmp(mat, m.matricula) == 0 && strcmp(cod, m.codigo) == 0 && m.status == 1){
				return 0;
			}
		}
	}
	return 1;
}

int checar_horario_disciplina(FILE * arqM, FILE * arqD, char mat[], char horario, indice_disciplina *ind){
	matricula aux_matricula;
	int status, flag = 1;
	fseek(arqM, 0, 0);

	while (1){
		status = fread(&aux_matricula, sizeof(matricula), 1, arqM);
		if (status != 1){
			if (!feof(arqM)){
				printf("\nErro de leitura\n");
			}
			else{
				break;
			}
		}
		if (strcmp(aux_matricula.matricula, mat) == 0 && aux_matricula.status == 1){
			if (checar_horario_repetido(arqD, aux_matricula.codigo, ind, horario)){//função retorna 1 caso eles forem iguais
				flag = 0;
				break;
			}
		}
	}

	if (flag){
		return 1;
	}
	else{
		return 0;
	}
}

int checar_horario_repetido(FILE *arqD, char codigo[], indice_disciplina *ind, char horario){
	disciplina aux_disciplina;
	int status, pos;

	pos = buscar_disciplina_arvore(ind, codigo);
	fseek(arqD, pos*sizeof(disciplina), 0);

	status = fread(&aux_disciplina, sizeof(disciplina), 1, arqD);
	if (status != 1){
		return -1; // alterar local de chamada para aceitar o erro de leitura
	}
	else{
		if (aux_disciplina.horario == horario){
			return 1;
		}
		else{
			return 0;
		}
	}
}

void matricular_aluno_definitivo(FILE *arqM, FILE *arqD, FILE *arqA, int pos_aluno, int pos_disciplina, aluno aux_aluno, disciplina aux_disciplina){

	int status;
	matricula aux_matricula;
	time_t data_time;
	struct tm * k;

	data_time = time(NULL);
	k = localtime(&data_time);


	strcpy(aux_matricula.matricula, aux_aluno.matricula);
	strcpy(aux_matricula.codigo, aux_disciplina.codigo);	
	
	aux_matricula.dia = k->tm_mday;
	aux_matricula.ano = k->tm_year + 1900;
	aux_matricula.mes = k->tm_mon + 1;

	aux_matricula.status = 1;
	

	fseek(arqM, 0, 2);
	status = fwrite(&aux_matricula, sizeof(matricula), 1, arqM);
	if (status != 1){
		printf("\nFalha na Matricula\n");
	}
	else{
		aux_aluno.qtd_disciplinas = aux_aluno.qtd_disciplinas + 1;
		aux_disciplina.vagas_ocupadas = aux_disciplina.vagas_ocupadas + 1;
		fseek(arqA, pos_aluno * sizeof(aluno), 0);
		status = fwrite(&aux_aluno, sizeof(aluno), 1, arqA);
		if (status != 1){
			printf("\nFalha na Matricula\n");
		}
		else{
			fseek(arqD, pos_disciplina * sizeof(disciplina), 0);
			status = fwrite(&aux_disciplina, sizeof(disciplina), 1, arqD);
			if (status != 1){
				printf("\nFalha na Matricula\n");
			}
			else{
				printf("\nAluno matriculado com sucesso!\n");
			}
		}
	}
}

// ------- 
// exibir 
void exibir_disciplinas_d1aluno(FILE *arqM, FILE *arqD, indice_disciplina *ind_disciplina, char mat[]){
	int pos, status, flag = 1;
	disciplina aux_disciplina;
	matricula aux_matricula;

	fseek(arqM, 0, 0);
	while (1){
		status = fread(&aux_matricula, sizeof(matricula), 1, arqM);
		if (status != 1){
			if (!feof(arqM)){
				
				printf("\nErro de Leitura\n");
			}
			else{
				break;
			}
		}
		else{
			if (aux_matricula.status == 1 && strcmp(aux_matricula.matricula, mat) == 0){

				pos = buscar_disciplina_arvore(ind_disciplina, aux_matricula.codigo);
				fseek(arqD, pos*sizeof(disciplina), 0);
				status = fread(&aux_disciplina, sizeof(disciplina), 1, arqD);
				if (status != 1){
					printf("\nErro no Fread\n");
					printf("\nErro de Leitura\n");
				}
				else{
					flag = 0;
					printf("\nCodigo: %s\nNome: %s\nHorario %c\nSala: %s\n", aux_disciplina.codigo,
						aux_disciplina.nome, aux_disciplina.horario, aux_disciplina.sala);
				}
			}
		}
	}
	if (flag){
		printf("\nO aluno nao esta matriculado em nenhuma disciplinan\n");
	}
}

void exibir_alunos_d1disciplina(FILE *arqM, FILE *arqA, indice_alunos *ind_alunos, char codig[]){
	aluno aux_aluno;
	matricula aux_matricula;
	int pos, status, flag = 1;
	
	fseek(arqM, 0, 0);

	while (1){
		status = fread(&aux_matricula, sizeof(matricula), 1, arqM);
		if (status != 1){
			if (!feof(arqM)){
				printf("\nErro de leitura\n");
			}
			else{
				break;
			}
		}
		else{
			if (aux_matricula.status == 1 && strcmp(aux_matricula.codigo, codig) == 0){
				pos = buscar_aluno_arvore(ind_alunos, aux_matricula.matricula);
				fseek(arqA, pos * sizeof(aluno), 0);
				status = fread(&aux_aluno, sizeof(aluno), 1, arqA);
				if (status != 1){
					printf("\nErro de leitura\n");
				}
				else{
					flag = 0;
					printf("\nMatricula: %s\nNome: %s\n", aux_aluno.matricula, aux_aluno.nome);
				}
			}
		}
	}
	if (flag){
		printf("\nNenhum aluno matriculado nesta disciplina\n");
	}
}

// -----

void remover_matricula(FILE *arqM, FILE *arqD, FILE *arqA, indice_disciplina * ind_disciplina, indice_alunos * ind_aluno){
	int pos_disciplina, pos_aluno, status, flag = 1, valido;	
	matricula aux_matricula;
	aluno aux_aluno;
	disciplina aux_disciplina;


	do{
		printf("\nDigite a matricula: "); // matricula
		gets(aux_aluno.matricula); fflush(stdin);
		valido = validar_matricula(aux_aluno.matricula);
		if (valido == 0){
			printf("\nMatricula nao valida");
		}
	} while (valido == 0);

	do{
		printf("\nDigite o codigo da disciplina: ");
		gets(aux_disciplina.codigo); fflush(stdin);
		valido = validar_codigo(aux_disciplina.codigo);
		if (valido == 0){
			printf("\nCodigo invalido\n");
		}
	} while (valido == 0);
	

	pos_disciplina = buscar_disciplina_arvore(ind_disciplina, aux_disciplina.codigo);
	pos_aluno = buscar_aluno_arvore(ind_aluno, aux_aluno.matricula);

	if (pos_disciplina != -1 && pos_aluno != -1){
		fseek(arqM, 0, 0);
		while (1){
			status = fread(&aux_matricula, sizeof(matricula), 1, arqM);
			if (status != 1){
				if (!feof(arqM)){
					printf("\nErro de leitura\n");
				}
				else{
					flag = 0;
					break;
				}
			}
			else{
				
				if (strcmp(aux_matricula.matricula, aux_aluno.matricula) == 0 && strcmp(aux_matricula.codigo, aux_disciplina.codigo) == 0 && aux_matricula.status == 1){
					if (aux_matricula.status == 1){
						aux_matricula.status = 0;
						break;
					}
					else{
						flag = 0;
						break;
					}
				}
			}
		}
		if (flag){
			fseek(arqM, -sizeof(matricula), 1);
			status = fwrite(&aux_matricula, sizeof(matricula), 1, arqM);
			if (status != 1){
				printf("\nErro de gravacao\n");
			}
			else{
				fseek(arqA, pos_aluno * sizeof(aluno), 0);
				status = fread(&aux_aluno, sizeof(aluno), 1, arqA);
				if (status != 1){
					printf("\nErro de Leitura\n");
				}
				else{
					aux_aluno.qtd_disciplinas--;
					fseek(arqA, -sizeof(aluno), 1);
					status = fwrite(&aux_aluno, sizeof(aluno), 1, arqA);
					if (status != 1){
						printf("\nErro de gravacao\n");
					}
					else{
						fseek(arqD, pos_disciplina * sizeof(disciplina), 0);
						status = fread(&aux_disciplina, sizeof(disciplina), 1, arqD);
						if (status != 1){
							printf("\nErro de leitura\n");
						}
						else{
							aux_disciplina.vagas_ocupadas--;
							fseek(arqD, -sizeof(disciplina), 1);
							status = fwrite(&aux_disciplina, sizeof(disciplina), 1, arqD);
							if (status != 1){
								printf("\nErro de gravacao\n");

							}
							else{
								printf("\nMatricula removida com sucesso\n");
							}
						}
					}
				}
			}
		}
		else{
			printf("\nMatricula nao encontrada\n");
		}
	}
	else{
		printf("\nAluno ou matricula nao cadastrados\n");
	}
}