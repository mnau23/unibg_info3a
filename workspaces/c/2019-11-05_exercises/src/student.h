// Abstract Data Type - Record opaco
#ifndef STUDENT_H_
#define STUDENT_H_

// Pointer to a struct defined in "student.c"
typedef struct Student *studentRef;

void addGrade(studentRef s, int x);
void deleteStudent(studentRef *s);	// Pointer to an opaque pointer
studentRef makeStudent(char *n, char *s);
void printAvg(studentRef s);
void printStudent(studentRef s);
char* studentData(studentRef s);

#endif /* STUDENT_H_ */
