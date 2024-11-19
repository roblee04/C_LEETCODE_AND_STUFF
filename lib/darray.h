#ifndef DARRAY_H
#define DARRAY_H

typedef struct darray DARRAY;

DARRAY* createArray();

void destroyArray(DARRAY* da);

void append(DARRAY* da, void* elt);

void insert(DARRAY* da, int idx, void* elt);

void* pop(DARRAY* da, int idx);

void* get(DARRAY* da, int idx);

void set(DARRAY* da, int idx, void* elt);

int getLen(DARRAY* da);

void** getElts(DARRAY* da);

void* sort(DARRAY* da);

#endif /* DARRAY_H */