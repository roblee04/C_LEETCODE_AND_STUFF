#include <stdio.h>
#include <stdlib.h>

#include "darray.h"

int main() {
    DARRAY* da = createArray();

    // Append elements
    int a = 10;
    int b = 20;
    int c = 30;
    append(da, &a);
    append(da, &b);
    append(da, &c);

    // Insert element
    int d = 15;
    insert(da, 1, &d);

    void** arr = getElts(da);
    // Get and print elements
    for (int i = 0; i < getLen(da); i++) {
        int* value = (int*)arr[i];
        printf("Element at index %d: %d\n", i, *value);
    }
    free(arr);

    // Set element
    int e = 25;
    int f = 90;
    set(da, 2, &e);
    set(da, -1, &f);

    // Get and print elements again
    printf("\nAfter setting element at index 2:\n");
    void** arr2 = getElts(da);
    for (int i = 0; i < getLen(da); i++) {
        int* value = (int*)arr2[i];
        printf("Element at index %d: %d\n", i, *value);
    }
    free(arr2);

    printf("\nPopping \n");
    int len = getLen(da);
    for (int i = 0; i < len; i++) {
        int* value = (int*)pop(da, 0);
        printf("Element at index %d: %d\n", i, *value);
    }

    // Destroy the dynamic array
    printf("\nDestroy arr\n");
    destroyArray(da);

    return 0;
}
