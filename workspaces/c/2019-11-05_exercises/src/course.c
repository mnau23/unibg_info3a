#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"
#include "student.h"

#define MAX_CHAR 40

// NodeList
typedef struct NodeList {
	studentRef stud;
	struct NodeList *next;
} NodeList;

struct Course {
	char courseName[MAX_CHAR];

	// Points to the first node at the top of the list
	// of students enrolled in the course
	NodeList *listRef;
};

// Entry at the top of the list
void addStudent(courseRef c, studentRef s) {
	// Need to use the asterisk
	NodeList *node = malloc(sizeof(struct NodeList));

	node->stud = s;
	node->next = c->listRef;
	c->listRef = node;
}

courseRef makeCourse(char *name) {
	// Omit the asterisk because courseRef is already a pointer
	courseRef crsRef = malloc(sizeof(struct Course));

	strncpy(crsRef->courseName, name, MAX_CHAR);
	crsRef->listRef = NULL;	// Initially, list has no nodes
	return crsRef;
}

void printCourse(courseRef c) {
	printf("%s: ", c->courseName);

	// Print students attending the course c
	NodeList *nl = c->listRef;
	while(nl != NULL) {
		printf("%s, ", nl->stud);
		nl = nl->next;
	}
	printf("\n");
}
