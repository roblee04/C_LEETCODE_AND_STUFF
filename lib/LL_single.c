#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "LL_single.h"

struct list {
    NODE* head;
    NODE* tail;
    int (*compare)();
    int length;
};

struct node {
    void* data;
    NODE* next;
};

LIST* SLL_create(int (*compare)()) {
    LIST* sll = malloc(sizeof(LIST));
    assert(sll != NULL);
    // initialize a dummy
    sll->length = 0;
    sll->compare = compare;
    sll->head = NULL;
    sll->tail = NULL;

    return sll;
}

void SLL_insert(LIST* sll, int idx, void* elt) {
    assert(idx <= sll->length);
    NODE* ptr = sll->head;
    NODE* backptr = sll->tail;

    NODE* newNode = malloc(sizeof(NODE));
    assert(newNode != NULL);
    newNode->data = elt;

    // first node insertion
    if(sll->length == 0) {
        newNode->next = NULL;
        ptr = newNode;
        backptr = newNode;
    } else if(idx == 0) {
        // insert at front
        newNode->next = ptr;
        ptr = newNode;
        
    } else if (idx == sll->length) {
        // insert at back
        newNode->next = NULL;
        backptr->next = newNode;
        backptr = newNode;
        
    } else {
        // insert in between    
        while(idx != 1) {
            ptr = ptr->next;
            idx--;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    sll->length += 1;
}

void SLL_remove(LIST* sll, int idx) {
    assert(sll->length > 0 && "Tried to remove from empty list!");

    NODE* ptr = sll->head;
    NODE* backptr = sll->tail;
    // first node deletion
    if(sll->length == 1) {
        ptr = NULL;
        backptr = NULL;
    } else if(idx == 0) {
        // remove at front
        ptr = ptr->next;
    }
    else {
        // remove
        while(idx-- != 1) {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
    }
    sll->length -= 1;
}

int SLL_getLen(LIST* sll) {
    assert(sll != NULL);
    return sll->length;
}

int SLL_findElt(LIST* sll, void* elt) {
    assert(sll != NULL);
    NODE* ptr = sll->head->next;
    int c = 0;
    while(ptr != NULL) {
        if((*sll->compare)(ptr->data, elt) == 0) {
            return c;
        }
        c += 1;
    }
    return -1;
}

void SLL_print(LIST* sll) {
    NODE* ptr = sll->head->next;
    while(ptr) {
        printf("%d", *(int*)ptr->data);
        ptr = ptr->next;
    }
}

int compare_int(int* a, int* b) {
    if(*a == *b) {
        return 0;
    } else if(*a > * b) {
        return 1;
    } else {
        return -1;
    }
}

int main() {


    LIST* intList = SLL_create(compare_int);

    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;

    SLL_insert(intList, 0, &a);
    SLL_insert(intList, 1, &b);
    SLL_insert(intList, 2, &c);
    SLL_insert(intList, 3, &d);

    printf("List after insertions: ");
    SLL_print(intList);

    printf("Length of list: %d\n", SLL_getLen(intList));

    int e = 20;
    int index = SLL_findElt(intList, &e);
    if (index != -1) {
        printf("Element %d found at index %d\n", e, index);
    } else {
        printf("Element %d not found\n", e);
    }

    SLL_remove(intList, 1);
    printf("List after removing element at index 1: ");
    SLL_print(intList);

    SLL_remove(intList, 0);
    printf("List after removing element at index 0: ");
    SLL_print(intList);

    SLL_remove(intList, 1);
    printf("List after removing element at index 1: ");
    SLL_print(intList);

    return 0;
}