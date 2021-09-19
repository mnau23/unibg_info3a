#include <stdio.h>
#include <stdlib.h>
#include "bitvector.h"

int main(void) {
	bvRef bv = makeBitVector(3);
	printf("Print data: %s\n", toString(bv));

	bvRef bvNot = not(makeBitVector(3));
	printf("\nNOT: not(000) = %s\n", toString(bvNot));

	// Correct
	printf("\nAND: and(000,111) = %s\n", toString(and(bvNot, bv)));
	printf("\nOR: or(000,111) = %s\n", toString(or(bvNot, bv)));

	// Not correct -> different dimensions
	printf("Error AND: %s\n", toString(and(makeBitVector(5), bv)));	// prints 5 zeros
	printf("Error OR: %s\n", toString(or(makeBitVector(5), bv)));	// prints 5 zeros

	deleteBitVector(bvNot);
	deleteBitVector(bv);

	return EXIT_SUCCESS;
}
