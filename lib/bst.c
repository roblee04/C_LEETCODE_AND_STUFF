#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

struct bst_node {
    int val;
    BSTNODE* left;
    BSTNODE* right;
};

BSTNODE* createBST(int val) {
    // create node 1
    BSTNODE* newNode = malloc(sizeof(BSTNODE));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void BST_insert(BSTNODE* root, int val) {
    BSTNODE* ptr = root;
    BSTNODE* prev = NULL;
    while(root != NULL) {
        prev = root;
        if(val > root->val) {
            root = root->right;
        } else if (val < root->val) {
            root = root->left;
        } else {
            return;
        }
    }
    // found place to insert (root)
    BSTNODE* newNode = malloc(sizeof(BSTNODE));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    if(prev->left == root) {
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }
    
}

void BST_remove(BSTNODE* root, int val) {
    BSTNODE* ptr = root;
    BSTNODE* prev = NULL;
    while(root != NULL) {
        prev = root;
        if(val > root->val) {
            root = root->right;
        } else if (val < root->val) {
            root = root->left;
        } else {
            // found
            
            // 2 children case
            if(ptr->left != NULL && ptr->right != NULL) {
                // left tree
                int replaceVal = BST_max(ptr->left);
                BST_remove(root, replaceVal);
                root->val = replaceVal;
                
            } else if (ptr->left == NULL && ptr->right == NULL) {
                // no children
                if(prev->right == root) {
                    prev->right = NULL;
                } else {
                    prev->left = NULL;
                }
            } else {
                BSTNODE* ptr_child;
                if(ptr->left != NULL) {
                    ptr_child = ptr->left;
                } else {
                    ptr_child = ptr->right;
                }

                if(prev->right == root) {
                    prev->right = ptr_child;
                } else {
                    prev->left = ptr_child;
                }
            }

        }
    }
    return;

}

int BST_search(BSTNODE* root, int val) {
    BSTNODE* ptr = root;
    BSTNODE* prev = NULL;
    while(root != NULL) {
        prev = root;
        if(val > root->val) {
            root = root->right;
        } else if (val < root->val) {
            root = root->left;
        } else {
            return 1;
        }
    }
    return 0;
}

int BST_min(BSTNODE* root) {
    int minSeen = root->val;
    BSTNODE* ptr = root;
    while(ptr) {
        minSeen = ptr->val;
        ptr = ptr->left;
    }
    return minSeen;
}

int BST_max(BSTNODE* root) {
    int maxSeen = root->val;
    BSTNODE* ptr = root;
    while(ptr) {
        maxSeen = ptr->val;
        ptr = ptr->right;
    }
    return maxSeen;
}

int main() {
    BSTNODE* root = createBST(10);
    BST_insert(root, 5);
    BST_insert(root, 15);
    BST_insert(root, 3);
    BST_insert(root, 7);
    BST_insert(root, 12);
    BST_insert(root, 18);

    printf("Min: %d\n", BST_min(root));
    printf("Max: %d\n", BST_max(root));
    printf("Search 7: %d\n", BST_search(root, 7));
    printf("Search 20: %d\n", BST_search(root, 20));

    BST_remove(root, 15);
    printf("Search 15: %d\n", BST_search(root, 15));

    return 0;
}