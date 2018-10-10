#include"matricula.h"
#include"modulos.h"

FILE * criar_Arquivo(char nome[]){
	FILE *aux;
	aux = fopen(nome, "r+b");
	if (aux == NULL){
		aux = fopen(nome, "w+b");
	}
	return aux;
}

void manutencao_aluno(FILE *arq) {
	aluno c;
	FILE * aux;
	int status;
	char nome[] = "ajudante.dat";

	aux = criar_Arquivo(nome);

	fseek(arq, 0, 0);
	fseek(aux, 0, 0);

	while (1) {
		status = fread(&c, sizeof(aluno), 1, arq);
		if (status != 1) {
			if (!feof(arq)){
				printf("\nErro de leitura\n");
			}
			else{
				break;
			}
		}
		else{
			if (c.status == 1) {				
				status = fwrite(&c, sizeof(aluno), 1, aux);
				if (status != 1){
					printf("\nErro de gravacao\n");
					break;
				}
			}
		}
	}

	fclose(arq);
	fclose(aux);
	remove("aluno.dat");
	
	rename("ajudante.dat", "aluno.dat");
	
}


void manutencao_disciplina(FILE *arq) {
	disciplina c;
	FILE * aux;
	int status;
	char nome[] = "ajudante2.dat";

	aux = criar_Arquivo(nome);

	fseek(arq, 0, 0);
	fseek(aux, 0, 0);
	while (1) {
		status = fread(&c, sizeof(disciplina), 1, arq);
		if (status != 1) {
			if (!feof(arq)){
				printf("\nErro de leitura\n");
			}
			else{
				break;
			}
		}
		else{
			if (c.status == 1) {				
				fwrite(&c, sizeof(disciplina), 1, aux);
			}
		}
	}

	fclose(arq);
	fclose(aux);
	remove("disciplina.dat");
	
	rename("ajudante2.dat", "disciplina.dat");
	
}

void manutencao_matricula(FILE *arq) {
	matricula c;
	FILE * aux;
	int status;
	char nome[] = "ajudante3.dat";

	aux = criar_Arquivo(nome);

	fseek(arq, 0, 0);
	fseek(aux, 0, 0);

	while (1) {
		status = fread(&c, sizeof(matricula), 1, arq);
		if (status != 1) {
			if (!feof(arq)){
				printf("\nErro de leitura\n");
			}
			else{
				break;
			}
		}
		else{
			if (c.status == 1) {
				status = fwrite(&c, sizeof(matricula), 1, aux);
				if (status != 1){
					printf("\nErro de gravacao\n");
					break;
				}
			}
		}
	}

	fclose(arq);
	fclose(aux);
	remove("matricula.dat");

	rename("ajudante3.dat", "matricula.dat");

}

int main() {
	FILE *arqM, *arqA, *arqD;
	indice_alunos *ind_aluno;
	indice_disciplina *ind_disciplina;


	arqM = criar_Arquivo("matricula.dat");
	arqA = criar_Arquivo("aluno.dat");
	arqD = criar_Arquivo("disciplina.dat");

	criar_arvore_aluno(&ind_aluno, arqA);
	criar_arvore_disciplina(&ind_disciplina, arqD);


	menu_principal(arqM, arqA, arqD, ind_aluno, ind_disciplina);

	manutencao_aluno(arqA);
	manutencao_disciplina(arqD);
	manutencao_matricula(arqM);


	return 0;
}
