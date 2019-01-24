#include "construct.h"
#include <stdlib.h>
#define SWAP(a, b) {int t = a; a = b; b = t;}

Node *new_node() {
    Node *ret = (Node *)calloc(1, sizeof(Node));
    ret->small = -1;
    return ret;
}
Node *insert(Node *root, int data) {
    if ( !root ) {
        Node *ret = new_node();
        ret->large = data;
        return ret;
    } else if ( root->small == -1 ) {
        root->small = data;
        if ( root->small > root->large )
            SWAP(root->small, root->large);
    } else if ( data > root->large )
        root->right = insert(root->right, data);
    else if ( data < root->large && data > root->small )
        root->mid = insert(root->mid, data);
    else
        root->left = insert(root->left, data);
    return root;
}
Node *ConstructTree(int sequence[],int N) {
    Node *root = NULL;
    for ( int i = 0; i < N; i++)
        root = insert(root, sequence[i]);
    return root;
}