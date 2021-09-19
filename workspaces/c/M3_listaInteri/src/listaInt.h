// Abstract Data Type - Record opaco

#ifndef LISTAINT_H_
#define LISTAINT_H_

typedef struct ListInt* ListIntRef;

ListIntRef mkList(int N);
void aggiungi(ListIntRef, int i);
char* toString(ListIntRef);

// Puntatore a puntatore opaco
void freeListInt(ListIntRef*);

#endif /* LISTAINT_H_ */
