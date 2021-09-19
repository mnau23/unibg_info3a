#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Non recursive
bool multiplo7_I(int numero) {
	int unita = numero%10;
	int prenumero = (numero-unita)/10;

	while (numero > 6) {
		printf("NUMERO: %d - PRENUMERO: %d - UNITA: %d\n", numero, prenumero, unita);
		numero = (prenumero+unita*5);

		if (numero == 7)
			return true;
		else {
			unita = numero%10;
			prenumero = (numero-unita)/10;
		}
	}
	return false;
}

// Recursive without tail recursion
bool multiplo7_R(int numero) {
	int unita = numero%10;
	int prenumero = (numero-numero%10)/10;
	numero = prenumero+unita*5;

	printf("NUMERO: %d - PRENUMERO: %d - UNITA: %d\n", numero, prenumero, unita);

	if (numero < 7)
		return false;

	return numero == 7 || multiplo7_R(numero);
}

// Recursive with tail recursion
bool multiplo7_TR(int numero) {
	int unita = numero%10;
	int prenumero = (numero-numero%10)/10;
	numero = prenumero+unita*5;

	if (prenumero < 7)
		return false;

	if (numero == 7)
		return true;
	else
		return multiplo7_TR(numero);
}

// Main
int main(void) {
	printf("\n68089 (NR):\n");
	printf("%d\n", multiplo7_I(68089));

	printf("\n14 (R):\n");
	printf("%d\n", multiplo7_R(14));

	printf("\n6853 (TR):\n");
	printf("%d", multiplo7_TR(6853));

	return 0;
}
