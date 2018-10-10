#include"aluno_arquivo.h"
#include"aluno.h"
#include"type_aluno.h"
#include"type_arvore.h"
#include<stdlib.h>
#include<string.h>


void cadastrar_aluno_arquivo(indice_alunos *ind, FILE *arqA, char mat[]){
	int flag, status;
	aluno aux;
	int valido;
	char opp;


	flag = buscar_aluno_arvore(ind, mat);

	if (flag == -1){
		fseek(arqA, 0, 2);

		strcpy(aux.matricula, mat);
		aux.media_anterior = 0;
		aux.status = 1;
		aux.qtd_disciplinas = 0;


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
			printf("\nTelefone: ");
			gets(aux.telefone); fflush(stdin);
			valido = validar_telefone(aux.telefone);
			if (valido == 0){
				printf("\nTelefone invalido, deseja digitar novamente(1-sim/0-nao): ");
				scanf("%c", &opp); fflush(stdin);
			}
		} while (opp != '0');
		if (valido == 0){
			return;
		}


		do{
			opp = '0';
			printf("\nEmail: ");
			gets(aux.email); fflush(stdin);
			valido = validar_email(aux.email);
			if (valido == 0){
				printf("\nEmail invalido, deseja digitar novamente(1-sim/0-nao): ");
				scanf("%c", &opp); fflush(stdin);
			}
		} while (opp != '0');
		if (valido == 0){
			return;
		}


		status = fwrite(&aux, sizeof(aluno), 1, arqA);

		if (status != 1){
			printf("\nErro ao cadastrar contato\n");
		}
		else{
			printf("\nContato cadastrado com sucesso\n");
			inserir_aluno_arvore(ind, aux.matricula);
		}
	}
	else{
		printf("\nContato ja cadastrado\n");
	}

}

void alterar_aluno_arquivo(indice_alunos *ind, FILE *arqA, char mat[]){
	int pos, status, valido;
	aluno aux;
	char opp, opp1;

	pos = buscar_aluno_arvore(ind, mat);
	if (pos != -1){
		fseek(arqA, pos * sizeof(aluno), 0);
		status = fread(&aux, sizeof(aluno), 1, arqA);
		if (status != 1){
			printf("\nErro de Leitura\n");
		}
		else{

			do{
				printf("\n1-Telefone\n2-Email\n3-Media\n4-Efetivar\n5-Cancelar");
				printf("\nDeseja alterar: ");
				scanf("%c", &opp1); fflush(stdin);

				switch (opp1)
				{
				case'1':

					do{
						opp = '0';
						printf("\nTelefone: ");
						gets(aux.telefone); fflush(stdin);
						valido = validar_telefone(aux.telefone);
						if (valido == 0){
							printf("\nTelefone invalido, deseja digitar novamente(1-sim/0-nao): ");
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
						printf("\nEmail: ");
						gets(aux.email); fflush(stdin);
						valido = validar_email(aux.email);
						if (valido == 0){
							printf("\nEmail invalido, deseja digitar novamente(1-sim/0-nao): ");
							scanf("%c", &opp); fflush(stdin);
						}
					} while (opp != '0');
					if (valido == 0){
						return;
					}
					break;

				case'3':

					do{
						opp = '0';
						printf("\nMedia: ");
						scanf("%f", &aux.media_anterior); fflush(stdin);
						valido = validar_media(aux.media_anterior);
						if (valido == 0){
							printf("\nMedia invalido, deseja digitar novamente(1-sim/0-nao): ");
							scanf("%c", &opp);
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

			if (opp1 == '4'){
				fseek(arqA, -sizeof(aluno), 1);
				status = fwrite(&aux, sizeof(aluno), 1, arqA);
				if (status != 1){
					printf("\nErro de gravacao\n");
				}
				else{
					printf("\nAluno alterado com sucesso\n");
				}
			}
		}
	}
	else{
		printf("\nAluno nao cadastrado\n");
	}
}

void exibir_aluno_arquivo(indice_alunos*ind, FILE *arqA, char mat[]){
	int pos, status;
	aluno a;
	pos = buscar_aluno_arvore(ind, mat);
	if (pos != -1){

		fseek(arqA, pos*sizeof(aluno), 0);
		status = fread(&a, sizeof(aluno), 1, arqA);
		if (status != 1){
			printf("\nErro de Leitura\n");
		}
		else{
			printf("\nNome: %s\nTelefone: %s\nEmail: %s\nMedia: %.2f\nQuantidade de disciplinas: %d\n"
				, a.nome, a.telefone, a.email, a.media_anterior, a.qtd_disciplinas);
		}
	}
	else{
		printf("\nAluno nao cadastrado\n");
	}
}

void remover_aluno_arquivo(indice_alunos**ind, FILE *arqA, char mat[]){
	aluno a;
	int pos;
	int status;
	pos = buscar_aluno_arvore(*ind, mat);
	if (pos != -1){

		fseek(arqA, pos*sizeof(aluno), 0);
		status = fread(&a, sizeof(aluno), 1, arqA);

		if (status != 1){
			printf("\nErro de Leitura\n");
		}
		else if (a.qtd_disciplinas ==0){
			a.status = 0;
			fseek(arqA, -sizeof(aluno), 1);
			status = fwrite(&a, sizeof(aluno), 1, arqA);

			if (status != 1){
				printf("\nErro de gravacao\n");
			}
			else{
				printf("\nAluno removido com sucesso\n");
				remover_aluno_arvore(*ind, mat);
			}
		}
		else{
			printf("\nAluno nao pode ser removido pois esta matriculado\n");
		}
	}
}