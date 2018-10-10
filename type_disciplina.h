#ifndef estrutura_disciplina
#define estrutura_disciplina
typedef struct disciplina{
	//codigo 7 + 0 \0
	//mesma coisa com sala e nome (99)
	char codigo[9], horario, sala[6], nome[100];
	int total_vagas, vagas_ocupadas, status;

}disciplina;

#endif