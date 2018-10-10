#include"disciplina.h"
#include<stdlib.h>


void inserir_disciplina_arvore(indice_disciplina * ind, char cod[]){
	arvore_disciplina *novo;

	novo = (arvore_disciplina *)malloc(sizeof(arvore_disciplina));

	strcpy(novo->codigo, cod);
	novo->dir = NULL;
	novo->esq = NULL;
	novo->pos = ind->indice;
	ind->indice++;

	inserir_no_disciplina(&ind->no, novo);
}

void inserir_no_disciplina(arvore_disciplina ** ind, arvore_disciplina * no){
	if (*ind == NULL){
		*ind = no;
	}
	else if (strcmp((*ind)->codigo, no->codigo) > 0){
		inserir_no_disciplina(&(*ind)->esq, no);
	}
	else{
		inserir_no_disciplina(&(*ind)->dir, no);
	}
}

void remover_disciplina_arvore(indice_disciplina *ind, char cod[]){
	remover_no_disciplina(&ind->no, cod);
}

void remover_no_disciplina(arvore_disciplina **no, char cod[]){
	if (strcmp((*no)->codigo, cod) > 0){
		remover_no_disciplina(&(*no)->esq, cod);
	}
	else if (strcmp((*no)->codigo, cod) < 0){
		remover_no_disciplina(&(*no)->dir, cod);
	}
	else{
		definir_remocao_disciplina(&(*no));
	}
}

void definir_remocao_disciplina(arvore_disciplina **no){
	arvore_disciplina *aux;
	if ((*no)->esq == NULL && (*no)->dir == NULL){
		free(*no);
		*no = NULL;
	}
	else if ((*no)->esq == NULL){
		aux = *no;
		*no = aux->dir;
		free(aux);
	}
	else if ((*no)->dir == NULL){
		aux = *no;
		*no = aux->esq;
		free(aux);
	}
	else{
		aux = maiorDireita_disciplina(&(*no)->esq);
		aux->dir = (*no)->dir;
		aux->esq = (*no)->esq;
		free(*no);
		*no = aux;
	}
}

arvore_disciplina * maiorDireita_disciplina(arvore_disciplina **no){
	if ((*no)->dir != NULL){
		return maiorDireita_disciplina(&(*no)->dir);
	}
	else{
		arvore_disciplina * aux = *no;
		if ((*no)->esq != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
			*no = (*no)->esq;
		else
			*no = NULL;
		return aux;
	}
}

int buscar_disciplina_arvore(indice_disciplina *ind, char cod[]){

	return  buscar_disciplina(ind->no, cod);
}

int buscar_disciplina(arvore_disciplina *no, char cod[]){
	int aux;
	if (no == NULL){
		return -1;
	}
	else if (strcmp(no->codigo, cod) > 0){
		aux = buscar_disciplina(no->esq, cod);
	}
	else if (strcmp(no->codigo, cod) < 0){
		aux = buscar_disciplina(no->dir, cod);
	}
	else{
		aux = no->pos;
	}
	return aux;
}

void criar_arvore_disciplina(indice_disciplina **ind, FILE *arqD){
	disciplina aux;
	int status;
	*ind = (indice_disciplina *)malloc(sizeof(indice_disciplina));
	(*ind)->indice = 0;
	(*ind)->no = NULL;
	fseek(arqD, 0, 0);
	while (1){
		status = fread(&aux, sizeof(disciplina), 1, arqD);
		if (status != 1){
			if (!feof(arqD)){
				printf("\nErro de Leitura\n");
			}
			else{
				break;
			}
		}
		else{
			inserir_disciplina_arvore((*ind), aux.codigo);
		}
	}
}

void remover_arvore_disciplina(indice_disciplina **ind){
	remover_todas_disciplinas(&(*ind)->no);

	free(*ind);
	*ind = NULL;
}

void remover_todas_disciplinas(arvore_disciplina **arv){
	if (*arv != NULL){
		remover_todas_disciplinas(&(*arv)->esq);
		remover_todas_disciplinas(&(*arv)->dir);
		free(*arv);
	}
}