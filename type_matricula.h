#ifndef estrutura_matricula
#define estrutura_matricula
typedef struct matricula{
	//9 pq eu posso usar o strlen para checar se a string é maaior do que o necessario
	//mesma coisa na matricula.
	char codigo[9], matricula[12];
	int status, dia, mes, ano;

}matricula;




#endif