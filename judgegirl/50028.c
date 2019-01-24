#include "subtree.h"
#include <stdlib.h>

int cnt;

int get_Node(Node *root, int label[], int k)
{
    if ( root == NULL ) {return 0;}
    int l = get_Node(root->left, label, k), r = get_Node(root->right, label, k);
    if ( root->label == k )
        return 1 + l + r;
    else if ( l > 0 && r > 0 )
        label[cnt++] = root->label;
    return l + r;
}

int getNode(Node *root, int label[], int k)
{
    cnt = 0;
    get_Node(root, label, k);
    return cnt;
}