#include"validacao.h"
#include<ctype.h>
#include<string.h>
#include<math.h>


int validar_nome(char texto[]){
	int flag = 0, i;

	for(i=0;texto[i] != '\0'; i++){  // Verifica se o nome da diciplina tem apenas letra e espaços
		if (isalpha(texto[i]) == 0 && texto[i] != ' ' && texto[i] != '\0') {
			flag = 1;
		}			
	
	}
	if (flag){
		return 0;
	}
	else{
		organizar_texto(texto, i);
		return 1;
	}
}

void organizar_texto(char texto[], int i){
	int cont, stringcont = 0;
	char string[100];

	for (cont = 0; cont<i ; cont++){
	if (isalpha(texto[cont]) != 0 && cont == 0){
	string[stringcont] = toupper(texto[cont]);
	stringcont++;
	}
	else if (isalpha(texto[cont]) != 0 && texto[cont - 1] == 32){
	string[stringcont] = ' ';
	stringcont++;
	string[stringcont] = toupper(texto[cont]);
	stringcont++;
	}
	else if (isalpha(texto[cont]) != 0 && isalpha(texto[cont - 1]) != 0){
	string[stringcont] = tolower(texto[cont]);
	stringcont++;
	}
	}

	string[stringcont] = '\0';
	strcpy(texto, string);
}

int validar_matricula(char mat[]){
	int i, soma=0, result;
	if (strlen(mat) > 10){
		return 0;
	}
	for (i = 0; i <= 8; i++){
		if (isdigit(mat[i]) != 0){
			soma = soma + ((mat[i] - 48)  * pow(2, i));
		}
		else{
			return 0;
		}
	}
	result = soma % 11;
	if (result == 10){
		if (mat[i] == 'x'){
			return 1;
		}
	}
	else if (result == (mat[i]-48)){
		return 1;
	}
	else{
		return 0;
	}
}

int validar_email(char email[]){
	int i, qtd = 0;

	for (i = 0; email[i] != '\0'; i++){
		if (email[i] == '@'){
			qtd++;
		}
		else if (email[i] == ' '){
			return 0;
		}
	}

	if (qtd == 1){
		return 1;
	}
	else{
		return 0;
	}
}

int validar_telefone(char telefone[]){
	int i;
	if (strlen(telefone) > 11 || strlen(telefone) < 11){
		return 0;
	}
	else{
		for (i = 0; i != '\0'; i++){
			if (isdigit(telefone[i]) == 0){
				return 0;
			}
		}
		return 1;
	}
}

int validar_media(float media){
	if (media < 0 || media > 10){
		return 0;
	}
	else{
		return 1;
	}
}

int validar_codigo(char cod[]){
	int i;
	if (strlen(cod) >= 8){
		return 0;
	}
	for (i = 0; i < 3; i++){
		if (isalpha(cod[i]) == 0){
			return 0;
		}
	}
	for (; cod[i] != '\0' || i <= 6; i++){
		if (isdigit(cod[i]) == 0){
			return 0;
		}
	}
	organizar_codigo(cod);
	return 1;
}
void organizar_codigo(char cod[]){
	int i;
	char novo[8];

	for (i = 0; i < 3; i++){
		novo[i] = toupper(cod[i]);
	}
	for (; cod[i] != '\0'; i++){
		novo[i] = cod[i];
	}
	novo[i] = '\0';
	strcpy(cod, novo);
}

int validar_sala(char sala[]){
	int i=0;
	if (strlen(sala) >= 5){
		return 0;
	}
	if (isalpha(sala[i]) == 0){
		return 0;
	}
	else{
		for (i = 1; sala[i] != '\0'; i++){
			if (isdigit(sala[i]) == 0){
				return 0;
			}
		}
	}
	organizar_sala(sala);
	return 1;
	
}
void organizar_sala(char sala[]){
	sala[0] = toupper(sala[0]);
}

int validar_horario(char hora){
	if (hora >= 65 && hora <= 71){
	
		return 1;
	}
	else if (hora >= 97 && hora <= 103){
		
		return 1;
	}
	else{
		return 0;
	}
}
void organizar_horario(char *hora){
	char novo;
	novo = toupper(*hora);
	*hora = novo;
	 
}

int validar_total_vagas(int vagas){
	if (vagas >= 30 && vagas <= 60){
		return 1;
	}
	return 0;

}

