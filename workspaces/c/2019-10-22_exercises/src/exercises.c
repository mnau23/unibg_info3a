#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int STUDENT_NUMBER = 1;

// *** Exercise 1 ***
void foo(int *a) {
	*(a + 1) = 20;
}


// *** Exercise 2 ***
void modify(char* s) {
	strcpy(s, "ciaociao");
}


// *** Exercise 3 ***
typedef struct Student {
	char name[50];
	char surname[50];
	int studentId;
};

struct Student* makeStudent1(char *n, char *s) {
	struct Student stud; // Does not work -> dangling pointer on stack
	strcpy(stud.name, n);
	strcpy(stud.surname, s);
	stud.studentId = STUDENT_NUMBER++;
	printf("(MK1) My name is %s \n", stud.name);
	return &stud; // If it is on the stack, return the address
}

void print(struct Student *s) {
	printf("%s %s %d \n", s->name, (*s).surname, s->studentId);
}


// *** Exercise 4 ***
struct Student* makeStudent2(char *n, char *s) {
	struct Student *stud = malloc(sizeof(struct Student));
	strcpy(stud->name, n);
	strcpy(stud->surname, s);
	stud->studentId = STUDENT_NUMBER++;
	printf("(MK2) My name is %s \n", stud->name);
	return stud; // If it is on the heap, it is already a pointer
}


int main(void) {
	// *** Exercise 1 ***
	printf("\n---Exercise 1---\n");
	int x = 0, y = 10;
	printf("x = %d; y = %d \n", x, y);		// 0 10
	foo(&y);	// x is modified even if y is passed
	printf("x = %d; y = %d \n", x, y);		// 20 10
	printf("x = %x; y = %x \n", &x, &y);	// memory addresses (%x)

	// *** Exercise 2 ***
	printf("\n---Exercise 2---\n");
	char s1[] = "aa";
	char s2[] = "bbbb";
	printf("%s - %s\n", s1, s2);
	modify(s2);
	printf("%s - %s\n", s1, s2);

	// *** Exercise 3 ***
	printf("\n---Exercise 3---\n");
	char *n = "StudentName";
	char *s = "StudentSurname";
	struct Student *pstud1 = makeStudent1(n, s);
	printf("(MAIN) My name is %s \n", pstud1->name);

	// *** Exercise 4 ***
	printf("\n---Exercise 4---\n");
	struct Student *pstud2 = makeStudent2(n, s);
	printf("(MAIN) My name is %s \n", pstud2->name);
	free(pstud2);
	printf("(MAIN) My name is %s \n", pstud2->name);

	return EXIT_SUCCESS;
}
