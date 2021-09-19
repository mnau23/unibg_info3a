#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

// Progressive static number for studentIdNumber
static int PROGRESSIVE_NR = 100;

struct Student {
	char name[30];
	char surname[30];
	int studentIdNumber;
	int grades[20];
	int gradesIndex;
};

void addGrade(studentRef s, int x) {
	s->grades[s->gradesIndex] = x;
	s->gradesIndex++;
}

void deleteStudent(studentRef *s) {
	/*
	 * These are used only if defined as "malloc" inside the struct:
	 * free((*s)->name);
	 * free((*s)->surname);
	 * free((*s)->studentIdNumber);
	*/
	free((*s));	// Free the entire struct (fields included)
	*s = NULL;	// Free the pointer to the pointer to the struct
}

studentRef makeStudent(char *name, char *surname) {
	studentRef studRef = malloc(sizeof(struct Student)); // Entire struct on the heap

	// Must use strcpy and not: studRef->name = n; studRef->surname = c;
	strcpy(studRef->name, name);
	strcpy(studRef->surname, surname);
	studRef->studentIdNumber = PROGRESSIVE_NR;
	PROGRESSIVE_NR++;

	for(int i=0; i<20; i++)
		studRef->grades[i] = 0;

	studRef->gradesIndex = 0;

	return studRef;
}

void printAvg(studentRef s) {
	int sum = 0;
	for(int i=0; i<s->gradesIndex; i++)
		sum += s->grades[i];
	int avg = sum/(s->gradesIndex);
	printf("Grades average: %d\n", avg);
}

void printStudent(studentRef s) {
	printf("%s %s %d\n", s->surname, s->name, s->studentIdNumber);
}

char* studentData(studentRef s) {
	//NB: If you had used "buffer[]", it meant you were allocating it on the stack!
	char *buffer = malloc(sizeof(char) * 100);
	sprintf(buffer, "%s %s %d", s->name, s->surname, s->studentIdNumber);
	return buffer;
}
