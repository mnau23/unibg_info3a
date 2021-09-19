/*
 ============================================================================
 Lezione	 : Martedì 08 Ottobre 2019
 Esercizio   : Scrivi una funzione PALINT che dato in ingresso un array di numeri
 	 	 	   interi restituisce (usa stdbool.h) se l’array è palindromo
 	 	 	   (cioè se si legge l’array dalla prima all’ultima posizione o viceversa,
 	 	 	   si ha sempre la stessa sequenza di numeri). Scrivi tre versioni:
 	 	 	   - una ITERATIVA,
 	 	 	   - una ricorsiva SENZA TAIL
 	 	 	   - una ricorsiva con TAIL recursion.
 	 	 	   Scrivi anche un main di esempio in cui chiami la funzione
 	 	 	   con un paio di array a tua scelta.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Non recursive
 a: array di n interi
*/
bool palInt_I(int a[], int n) {
	for(int i=0; i < n/2; i++) {
		if (a[i] != a[n-i-1])
			return false;
	}
	return true;
}

/* Recursive without tail recursion
 a: array di n interi
*/
bool PalInt_R(int a[], int n) {
	if (n <= 1) return true;
	// è palindromo se testa = coda e
	// l'array tolta la testa e la coda è ancora palindromo
	return a[0] == a[n-1] && PalInt_R(a+1, n-2);
}

/* Recursive with tail recursion
 i: elemento da considerare
*/
bool PalInt_trh(int a[], int n, int i) {
	if (i > n/2)
		return true;

	if (a[i] != a[n-i-1])
		return false;
	else
		return PalInt_trh(a, n, i+1);
}

bool PalInt_TR(int a[], int n) {
	return PalInt_trh(a, n, 0);

}


int main(void) {
	// esempio di vettore palindromo
	int p1[] = {1, 2, 3, 2, 1};
	printf("--Array p1--\n");
	printf("Palindroma iterativa: %d\n",palInt_I(p1,5));
	printf("Palindroma ricorsiva senza TR: %d\n",PalInt_R(p1,5));
	printf("Palindroma ricorsiva con TR: %d\n",PalInt_TR(p1,5));

	// esempio di vettore non palindromo
	int p2[] = {1, 2, 3, 4, 1};
	printf("--Array p2--\n");
	printf("Palindroma iterativa: %d\n",palInt_I(p2,5));
	printf("Palindroma ricorsiva senza TR: %d\n",PalInt_R(p2,5));
	printf("Palindroma ricorsiva con TR: %d\n",PalInt_TR(p2,5));

	return EXIT_SUCCESS;
}
