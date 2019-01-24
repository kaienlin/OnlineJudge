#include "tree.h"
#include <stdlib.h>

Node *insert(int array[], int n, int idx) {
    if ( idx >= n ) {return NULL;}
    Node *root = (Node*)malloc(sizeof(Node));
    root->label = array[idx];
    root->left = insert(array, n, 2 * idx + 1);
    root->right = insert(array, n, idx * 2 + 2);
    return root;
}

Node *construct(int array[], int n) {
    return insert(array, n, 0);
}