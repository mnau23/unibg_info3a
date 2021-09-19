// Abstract Data Type - Record opaco

#ifndef BITVECTOR_H_
#define BITVECTOR_H_

// Pointer to a struct defined in "bitvector.c"
typedef struct bitvector *bvRef;

bvRef and(bvRef bv1, bvRef bv2);
void deleteBitVector(bvRef bv);
bvRef makeBitVector(int n);
bvRef not(bvRef bv);
bvRef or(bvRef bv1, bvRef bv2);
char* toString(bvRef bv);

#endif /* BITVECTOR_H_ */
