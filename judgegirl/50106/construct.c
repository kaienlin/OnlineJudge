#include "construct.h"
#include <stdlib.h>
#include <string.h>

Node *insert(Node *root, char *name, int h, int w) {
    if ( root == NULL ) {
        Node *ret = (Node*)malloc(sizeof(Node));
        strcpy(ret->name, name);
        ret->height = h;
        ret->weight = w;
        ret->left = ret->right = NULL;
        return ret;
    }
#ifdef HEIGHT
    if ( h < root->height )
        root->left = insert(root->left, name, h, w);
    else
        root->right = insert(root->right, name, h, w);
#endif
#ifdef WEIGHT
    if ( w < root->weight )
        root->left = insert(root->left, name, h, w);
    else
        root->right = insert(root->right, name, h, w);
#endif
    return root;
}

Node *ConstructBSTree(int N, char name[][16], int height[], int weight[]) {
    Node *ret = NULL;
    for ( int i = 0; i < N; i++)
        ret = insert(ret, name[i], height[i], weight[i]);
    return ret;
}