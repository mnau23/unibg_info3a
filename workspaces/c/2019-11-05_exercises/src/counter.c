#include <stdio.h>
#include <stdlib.h>
#include "counter.h"

static int count = 0;

// reset the counter
void resetVal() {
	count = 0;
}

// increase the counter
void increaseVal() {
	count++;
}

// return the value as int
int getValue() {
	return count;
}

// return the value as char*
char* returnVal() {
	char* value = malloc(sizeof(char));
	sprintf(value, "%d", count);
	return value;
}
