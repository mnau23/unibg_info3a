/*
 ============================================================================
 Lezione	 : Mercoledì 02 Ottobre 2019
 Esercizio	 : Data una stringa, creare una versione iterativa ed una ricorsiva
 	 	 	   di una funzione che restituisca solamente le vocali di tale stringa.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Non recursive
char* vocalizza_I(char* s) {
	// Viene allocato nello heap
	char* result = malloc((strlen(s)+1)*sizeof(char));

	// Posizione corrente in result
	int j = 0;

	while(*s) {
		if(*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u') {
			result[j++]= *s;
			result[j] = '\0'; // Terminatore corretto
			printf("Risultato parziale (iterativa): %s\n", result);
		}
		s++;
	}
	return result;
}

// Recursive without tail recursion
char* vocalizza_R(char *s) {
	if (*s=='\0') {
		// Restituisce una stringa vuota
		char* res = malloc(sizeof(char));
		*res = '\0';
		return res;
	} else {
		char* res = vocalizza_R(s+1);
		if (*s == 'a' ||*s == 'e'||*s == 'i'||*s == 'o' || *s == 'u') {
			// Aggiungi come prefisso *s
			char* stringaFinale = malloc((strlen(res)+2)*sizeof(char));
			// Metti il primo char
			sprintf(stringaFinale, "%c", s[0]);
			// Concatena il risultato
			strcat(stringaFinale, res);
			// Free di res dato che non serve più
			free(res);
			return stringaFinale;
		} else
			return res;
	}
}


int main(void) {
	char nome[] = "giovanni";

	char *res = vocalizza_I(nome);
	printf("\nIterativa: %s\n", res);

	printf("Ricorsiva: %s\n", vocalizza_R(nome));

	return EXIT_SUCCESS;
}
