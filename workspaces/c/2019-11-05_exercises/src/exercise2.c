#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"
#include "student.h"


int main(void) {
	// Student 1
	char name1[30] = "studName1";
	char surname1[30] = "studSurname1";

	studentRef s1 = makeStudent(name1, surname1);

	printf("---First student---\n");
	printf("Print student:\n");
	printStudent(s1);
	printf("\n");

	printf("Print student data:\n");
	char printData[100];
	strcpy(printData, studentData(s1));
	printf("%s\n", printData);
	printf("\n");

	addGrade(s1, 10);
	addGrade(s1, 8);
	addGrade(s1, 6);

	printAvg(s1);
	printf("\n\n");

	// Student 2
	char name2[30] = "studName2";
	char surname2[30] = "studSurname2";

	studentRef s2 = makeStudent(name2, surname2);

	printf("---Second student---\n");
	printf("Print student:\n");
	printStudent(s2);
	printf("\n");

	// Course
	char cName[30] = "courseName";
	courseRef c1 = makeCourse(cName);

	addStudent(c1, s1);
	addStudent(c1, s2);

	printf("Course:\n");
	printCourse(c1);
	printf("\n");

	// Destructor
	printf("Deleting... %p\n", s1);
	deleteStudent(&s1);
	printf("Deleted... %p\n", s1);

	return EXIT_SUCCESS;
}
