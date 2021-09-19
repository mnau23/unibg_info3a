// Abstract Data Type - Record opaco
#include "student.h"

#ifndef COURSE_H_
#define COURSE_H_

// Pointer to a struct defined in "student.c"
typedef struct Course *courseRef;

void addStudent(courseRef c, studentRef s);	// Entry at the top of the list
courseRef makeCourse(char *n);
void printCourse(courseRef c);

#endif /* COURSE_H_ */
