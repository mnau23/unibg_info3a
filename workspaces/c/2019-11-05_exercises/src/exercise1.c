#include <stdio.h>
#include <stdlib.h>
#include "counter.h"


int main() {
	printf("Initial value (int): %d\n", getValue());
	increaseVal(); // 1
	printf("Print (as int): %d\n", getValue());
	resetVal();
	increaseVal(); // 1
	increaseVal(); // 2
	increaseVal(); // 3

	/* Have to create a variable here,
	 * so as to do "free" on this one,
	 * it makes no sense to do "free"
	 * inside the function returnVal()
	*/
	char* val = returnVal();
	printf("Print (as char*): %s\n", val);
	free(val);

	return EXIT_SUCCESS;
}
