#include"aluno.h"
#include<stdlib.h>
#include<string.h>


// funções e procedimentos relacionados a árvore
void inserir_aluno_arvore(indice_alunos *ind, char mat[])//cadastra o aluno no indice da arvore, 
//procedimento só será chamado após a inserção do aluno no arquivo
// recebe o indice(da arvore alunos) e a matricula do aluno em questão
{
	arvore_aluno *novo;

	novo = (arvore_aluno *)malloc(sizeof(arvore_aluno));
	novo->pos = ind->indice;
	strcpy(novo->matricula, mat);
	novo->dir = NULL;
	novo->esq = NULL;

	inserir_no_aluno(&ind->no, novo);

	ind->indice++;
}

void inserir_no_aluno(arvore_aluno **ind, arvore_aluno *no){
	if (*ind == NULL){
		*ind = no;
	}
	else if (strcmp((*ind)->matricula, (no)->matricula) > 0){
		inserir_no_aluno(&(*ind)->esq, no);
	}
	else{
		inserir_no_aluno(&(*ind)->dir, no);
	}
}

void remover_aluno_arvore(indice_alunos *ind, char mat[]){//remove um aluno do indice da arvore, procedimento chamado apos a
	//apos a remoção lógica do aluno no arquivo
	// só poderá ser removido o aluno que não está matriculado em nada
	//verei se posso remover no arquivo, aqui já tomo como verdade que ele pode ser removido
	remover_no_aluno(&(ind->no), mat);
}

void remover_no_aluno(arvore_aluno **no, char mat[]){
	if (strcmp((*no)->matricula, mat) == 0){
		definir_remocao_aluno(&(*no));
	}
	else if (strcmp((*no)->matricula, mat) > 0){
		remover_no_aluno(&(*no)->esq, mat);
	}
	else{
		remover_no_aluno(&(*no)->dir, mat);
	}
}

void definir_remocao_aluno(arvore_aluno **no){
	arvore_aluno *aux = *no;

	if ((*no)->esq == NULL && (*no)->dir == NULL){
		free(*no);
		*no = NULL;
	}
	else if ((*no)->esq == NULL){
		*no = (*no)->dir;
		free(aux);

	}
	else if ((*no)->dir == NULL){
		*no = (*no)->esq;
		free(aux);
	}
	else{
		aux = maiorDireita_aluno(&(*no)->esq);
		aux->dir = (*no)->dir;
		aux->esq = (*no)->esq;
		free(*no);
		*no = aux;
	}
}
arvore_aluno * maiorDireita_aluno(arvore_aluno **no){

	if ((*no)->dir != NULL){
		return maiorDireita_aluno(&(*no)->dir);
	}
	else{
		arvore_aluno * aux = *no;
		if ((*no)->esq != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
			*no = (*no)->esq;
		else
			*no = NULL;
		return aux;
	}
}

int buscar_aluno_arvore(indice_alunos *ind, char mat[]){

	return buscar_aluno(ind->no, mat);
}

int buscar_aluno(arvore_aluno *no, char mat[]){
	int aux;

	if (no == NULL){
		return -1;
	}
	else if (strcmp(no->matricula, mat) > 0){
		aux = buscar_aluno(no->esq, mat);
	}
	else if (strcmp(no->matricula, mat) < 0){
		aux = buscar_aluno(no->dir, mat);
	}
	else{
		aux = no->pos;
	}
	return aux;
}

//implementação da linguagem

void criar_arvore_aluno(indice_alunos **ind, FILE *arqA){//procedimento para criar o nó descritor e a arvore em conjunto
	//recebe o arquivo pois ele já vai criar o indice com os arquivos possivelmente existentes	
	aluno aux_arquivo;
	int status;



	*ind = (indice_alunos *)malloc(sizeof(indice_alunos));
	(*ind)->indice = 0;
	(*ind)->no = NULL;

	fseek(arqA, 0, 0);

	while (1){
		status = fread(&aux_arquivo, sizeof(aluno), 1, arqA);
		if (status != 1){
			if (!feof(arqA)){
				printf("\nErro de Leitura\n");
			}
			else{
				break;
			}
		}
		else{
			inserir_aluno_arvore(*ind, aux_arquivo.matricula);
		}
	}
}


void remover_arvore_aluno(indice_alunos **ind){

	remover_todos_alunos(&(*ind)->no);

	free(*ind);
	*ind = NULL;
}

void remover_todos_alunos(arvore_aluno ** arv){
	if (arv != NULL){
		remover_todos_alunos(&(*arv)->esq);
		remover_todos_alunos(&(*arv)->dir);
		free(*arv);
	}
}