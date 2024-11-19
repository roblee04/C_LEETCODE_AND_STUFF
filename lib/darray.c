#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "darray.h"

#define SIZE 2

struct darray{
    int count;
    void** data;
    int capacity;
};

DARRAY* createArray() {
    
    DARRAY* da = malloc(sizeof(DARRAY));
    assert(da != NULL && "DA pointer was unable to be allocated");
    da->count = 0;
    da->capacity = SIZE;
    da->data = malloc(sizeof(void*) * SIZE);
    assert(da->data != NULL && "DA data pointer was unable to be allocated");

    return da;
}

void destroyArray(DARRAY* da) {
    assert(da != NULL);
    free(da->data);
    free(da);
}

void append(DARRAY* da, void* elt) {
    assert(da != NULL && elt != NULL);
    // check if end_idx >= cap, if so realloc
    if (da->count >= da->capacity) {
        da->capacity = 2 * da->capacity;
        da->data = realloc(da->data, sizeof(void*) * da->capacity);
    }

    da->data[da->count] = elt;
    da->count += 1;
}

void insert(DARRAY* da, int idx, void* elt) {
    assert(da != NULL && elt != NULL && idx < da->capacity);
    // support negative indexing
    if (idx < 0) {
        idx = da->count + idx;
    }

    // check if end_idx >= cap, if so realloc
    if (da->count >= da->capacity) {
        da->capacity = 2 * da->capacity;
        da->data = realloc(da->data, sizeof(void*) * da->capacity);
    }
    // INSERT
    for(int i = da->count + 1; i > idx; i--) {
        da->data[i] = da->data[i-1];
    }
    da->data[idx] = elt;
    da->count += 1;

}

void* pop(DARRAY* da, int idx) {
    assert(da != NULL && idx < da->capacity);
    // support negative indexing
    if (idx < 0) {
        idx = da->count + idx;
    } 

    // pop
    void* popped = da->data[idx];
    for(int i = idx; i < da->count; i ++) {
        da->data[i] = da->data[i + 1];
    }
    da->count -= 1;
    return popped;
}

void* get(DARRAY* da, int idx) {
    assert(da != NULL && idx < da->capacity);
    // support negative indexing
    if (idx < 0) {
        idx = da->count + idx;
    } 

    return da->data[idx];
}

void set(DARRAY* da, int idx, void* elt) {
    assert(da != NULL && elt != NULL);
    
    // support negative indexing
    if (idx < 0) {
        idx = da->count + idx;
    } 
    da->data[idx] = elt;
}

int getLen(DARRAY* da) {
    assert(da != NULL);
    return da->count;
}

void** getElts(DARRAY* da) {
    assert(da != NULL);
    void** elements = malloc(sizeof(void*) * getLen(da));
    memcpy(elements, da->data, sizeof(void*) * getLen(da));
    return elements;
}

void* sort(DARRAY* da) {
    assert(da != NULL);
}