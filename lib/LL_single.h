#ifndef LL_SINGLE_H
#define LL_SINGLE_H

typedef struct list LIST;

typedef struct node NODE;

LIST* SLL_create();

void SLL_insert(LIST* sll, int idx, void* elt);

void SLL_remove(LIST* sll, int idx);

int SLL_getLen(LIST* sll);

int SLL_findElt(LIST* sll, void* elt);

void** SLL_getElts(LIST* sll);

#endif