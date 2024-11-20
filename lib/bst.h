#ifndef BST_H
#define BST_H

typedef struct bst_node BSTNODE;

BSTNODE* createBST(int val);

void BST_insert(BSTNODE* root, int val);

void BST_remove(BSTNODE* root, int val);

int BST_search(BSTNODE* root, int val);

int BST_min(BSTNODE* root);

int BST_max(BSTNODE* root);

// find next min / max aka its parent

#endif