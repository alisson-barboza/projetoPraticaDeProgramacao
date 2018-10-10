#include"disciplina_arquivo.h"



void cadastrar_disciplina_arquivo(indice_disciplina **ind, FILE *arqD, char cod[]){
	disciplina aux;
	int pos, status, valido;
	char opp;

	pos = buscar_disciplina_arvore(*ind, cod);
	
	if (pos == -1){
		fseek(arqD, 0, 2);

		strcpy(aux.codigo, cod);
		aux.vagas_ocupadas = 0;
		aux.status = 1;

		printf("\nPreencha os campos abaixo\n");

		do{
			opp = '0';
			printf("\nNome: ");
			gets(aux.nome); fflush(stdin);
			valido = validar_nome(aux.nome);
			if (valido == 0){
				printf("\nNome invalido, deseja digitar novamente(1-sim/0-nao): ");
				scanf("%c", &opp); fflush(stdin);
			}
		} while (opp != '0');
		if (valido == 0){
			return;
		}


		do{
			opp = '0';
			printf("\nSala: ");
			gets(aux.sala); fflush(stdin);
			valido = validar_sala(aux.sala);
			if (valido == 0){
				printf("\nSala invalido, deseja digitar novamente(1-sim/0-nao): ");
				scanf("%c", &opp); fflush(stdin);
			}
		} while (opp != '0');
		if (valido == 0){
			return;
		}


		do{
			opp = '0';
			printf("\nA-7h as 9h\nB-9h as 11h\nC-11h as 13h\nD-13h as 15h\nE-15h as 17h\nF-17h as 19h\nG-19h as 21h");
			printf("\nHorario: ");
			scanf("%c", &aux.horario); fflush(stdin);
			valido = validar_horario(aux.horario);
			organizar_horario(&aux.horario);
			
			if (valido == 0){
				printf("\nHorario invalido, deseja digitar novamente(1-sim/0-nao): ");
				scanf("%c", &opp); fflush(stdin);
			}
		} while (opp != '0');
		if (valido == 0){
			return;
		}

		do{
			opp = '0';
			printf("\nTotal de Vagas: ");
			scanf("%d", &aux.total_vagas); fflush(stdin);
			valido = validar_total_vagas(aux.total_vagas);
			if (valido == 0){
				printf("\nTotal de vagas invalido, deseja digitar novamente(1-sim/0-nao): ");
				scanf("%c", &opp); fflush(stdin);
			}
		} while (opp != '0');
		if (valido == 0){
			return;
		}


		status = fwrite(&aux, sizeof(disciplina), 1, arqD);
		if (status != 1){
			printf("\nErro de Gravacao\n");
		}
		else{
			printf("\nDisciplina cadastrada com sucesso\n");
			inserir_disciplina_arvore(*ind, cod);
		}
	}
	else{
		printf("\nDisciplina ja cadastrada\n");
	}

}

void alterar_disciplina_arquivo(indice_disciplina *ind, FILE *arqD, char cod[]){
	disciplina aux;
	int pos, status, valido;
	char opp, opp1;

	pos = buscar_disciplina_arvore(ind, cod);
	
	if (pos != -1){
		fseek(arqD, pos* sizeof(disciplina), 0);
		status = fread(&aux, sizeof(disciplina), 1, arqD);

		if (status != 1){
			printf("\nErro de Leitura\n");
		}
		else{
			do{

				printf("\n1-Nome\n2-Sala\n3-Quantidade total de vagas\n4-Efetivar\n5-Cancelar");
				printf("\nDeseja alterar: ");
				scanf("%c", &opp1); fflush(stdin);

				switch (opp1)
				{
				case'1':

					do{
						opp = '0';
						printf("\nNome: ");
						gets(aux.nome); fflush(stdin);
						valido = validar_nome(aux.nome);
						if (valido == 0){
							printf("\nNome invalido, deseja digitar novamente(1-sim/0-nao): ");
							scanf("%c", &opp); fflush(stdin);
						}
					} while (opp != '0');
					if (valido == 0){
						return;
					}
					break;

				case'2':

					do{
						opp = '0';
						printf("\nSala: ");
						gets(aux.sala); fflush(stdin);
						valido = validar_sala(aux.sala);
						if (valido == 0){
							printf("\nSala invalido, deseja digitar novamente(1-sim/0-nao): ");
							scanf("%c", &opp); fflush(stdin);
						}
					} while (opp != '0');
					if (valido == 0){
						return;
					}
					break;


				case '3':

					do{
						opp = '0';
						printf("\nTotal de Vagas: ");
						scanf("%d", &aux.total_vagas); fflush(stdin);
						valido = validar_total_vagas(aux.total_vagas);						
						if (valido == 0){
							printf("\nTotal de vagas invalido, deseja digitar novamente(1-sim/0-nao): ");
							scanf("%c", &opp); fflush(stdin);
						}
					} while (opp != '0');
					if (valido == 0){
						return;
					}

					break;

				case'4':

					
					break;
				case'5':

					break;
				default:

					printf("\nOpcao invalida\n");
					break;

				}

			} while (opp1 != '4' && opp1 != '5');
			if (opp1 =='4'){
				fseek(arqD, -sizeof(disciplina), 1);
				status = fwrite(&aux, sizeof(disciplina), 1, arqD);
				if (status != 1){
					printf("\nErro de gravação\n");
				}
				else{
					printf("\nDisciplina alterada com sucesso\n");
				}
			}
		}
	}
	else{
		printf("\nDisciplina nao cadastrada\n");
	}
	
}

void exibir_disciplina_arquivo(indice_disciplina * ind, FILE *arqD, char cod[]){
	disciplina aux;
	int pos, status;

	pos = buscar_disciplina_arvore(ind, cod);
	
	if (pos != -1){
		fseek(arqD, pos*sizeof(disciplina), 0);
		status = fread(&aux, sizeof(disciplina), 1, arqD);
		if (status != 1){
			printf("\nErro de Leitura\n");
		}
		else{
			printf("\nNome: %s\nHorario: %c\nSala: %s\nQuantidade de vagas: %d", aux.nome, aux.horario, aux.sala, aux.total_vagas);
		}
	}
	else{
		printf("\nDisciplina nao encontrada\n");
	}
}

void remover_disciplina_arquivo(indice_disciplina ** ind, FILE *arqD, char cod[]){
	disciplina aux;
	int pos, status;

	pos = buscar_disciplina_arvore(*ind, cod);
	if (pos != -1){
		fseek(arqD, pos*sizeof(disciplina), 0);
		status = fread(&aux, sizeof(disciplina), 1, arqD);
		if (status != 1){
			printf("\nErro de Leitura\n");
		}
		else if(aux.vagas_ocupadas == 0){
			aux.status = 0;
			fseek(arqD, -sizeof(disciplina), 1);
			status = fwrite(&aux, sizeof(disciplina), 1, arqD);
			if (status != 1){
				printf("\nFalha na gravacao\n");
			}
			else{
				printf("\nDisciplina removida com sucesso\n");
				remover_disciplina_arvore(*ind, cod);
			}
		}
		else{
			printf("\nDisciplina nao pode ser removida pois existem alunos matriculados nela\n");
		}
	}
}