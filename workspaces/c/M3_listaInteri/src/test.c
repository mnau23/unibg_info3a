/*
 ============================================================================
 Lezione	 : Martedì 23 Ottobre 2019
 Esercizio	 : Realizza una lista di N interi tramite tipi opachi.
 	 	 	   La lista dovrà avere le seguenti operazioni:
 	 	 	   - mkLista: costruisce una lista con al massimo N interi
 	 	 	     (N passato) inizialmente vuota
 	 	 	   - aggiungi: aggiunge un intero in fondo alla lista (se piena ignora)
 	 	 	   - toString: restituisce una stringa (char*) che rappresenta il
 	 	 	     contenuto della lista
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "listaInt.h"

int main(void) {
	ListIntRef l1 = mkList(100);

	aggiungi(l1, 11);
	aggiungi(l1, 22);
	aggiungi(l1, 33);
	aggiungi(l1, 44);

	char *s = toString(l1);

	printf("Buffer (Main): [%s]\n", s);

	printf("%p \n", l1);
	freeListInt(&l1);
	printf("%p \n", l1);

	return EXIT_SUCCESS;
}
