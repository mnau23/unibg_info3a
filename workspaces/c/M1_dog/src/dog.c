#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

typedef struct Dog {
	char *name;
} Dog;

dogRef make(char *n) {
	Dog *p = malloc(sizeof(Dog));
	p->name = n;
	return (dogRef) p;
}

void bark(dogRef c) {
	printf("%s, BAU\n", ((Dog*) c)->name);
}

void delete(dogRef c) {
	free((Dog*) c);
}

void make_and_bark() {
	dogRef maya = make("Pluto");
	bark(maya);
	delete(maya);
}

int main(void) {
	make_and_bark();
	make_and_bark();
	return 0;
}
