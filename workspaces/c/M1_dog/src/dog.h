#ifndef DOG_H_
#define DOG_H_

typedef void *dogRef;

dogRef make(char *name);
void bark(dogRef);
void delete(dogRef);

#endif /* CANE_H_ */
