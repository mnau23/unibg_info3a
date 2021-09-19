#include <stdio.h>
#include <stdlib.h>
#include "bitvector.h"

struct bitvector {
	int dim;
	int *content;	// 0 false, 1 true
};

// If bv1 and bv2 have same dimensions then do AND, else do nothing
bvRef and(bvRef bv1, bvRef bv2) {
	bvRef res = makeBitVector(bv1->dim);

	if(bv1->dim == bv2->dim) {
		for(int i=0; i < res->dim; i++)
			res->content[i] = bv1->content[i] * bv2->content[i];
	} else
		printf("\nAND: Dimensions not equal!\n");

	return res;
}

void deleteBitVector(bvRef bv) {
	// Free the array
	free(bv->content);
	// Free the data structure
	free(bv);
	bv = NULL;
}

bvRef makeBitVector(int n) {
	// Allocate memory for the data structure
	bvRef bv = malloc(sizeof(struct bitvector));

	// Allocate memory for the array
	bv->content = malloc(n * sizeof(int));
	bv->dim = n;

	// Array initialization
	for(int i=0; i < n; i++)
		*(bv->content + i) = 0;

	return bv;
}

// If bv has '0', then res has '1'. And viceversa
bvRef not(bvRef bv) {
	bvRef res = makeBitVector(bv->dim);

	for (int i=0; i < bv->dim; i++) {
		if (bv->content[i] == 0)
			res->content[i] = 1;
		else
			res->content[i] = 0;
	}

	return res;
}

// If bv1 and bv2 have same dimensions then do OR, else do nothing
bvRef or(bvRef bv1, bvRef bv2) {
	bvRef res = makeBitVector(bv1->dim);

	if(bv1->dim == bv2->dim) {
		// Use module to vary between 0 and 1
		for(int i=0; i < res->dim; i++)
			res->content[i] = (bv1->content[i] + bv2->content[i])%2;
	} else
		printf("\nOR: Dimensions not equal!\n");

	return res;
}

char* toString(bvRef bv) {
	char *buffer = malloc((bv->dim + 1) * sizeof(char));

	int i;
	for(i=0; i < bv->dim; i++) {
		if (bv->content[i] == 0)
			buffer[i] = '0';
		else
			buffer[i] = '1';
	}
	buffer[i] = '\0';

	return buffer;
}
