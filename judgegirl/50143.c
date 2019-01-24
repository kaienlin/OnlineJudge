#include <stdlib.h>
#include "tree.h"

Node *treeAND(Node *root1, Node *root2) {
    if ( root1 == NULL || root2 == NULL )
        return NULL;
    root1->val *= root2->val;
    root1->left = treeAND(root1->left, root2->left);
    root1->right = treeAND(root1->right, root2->right);
    return root1;
}
Node *treeOR(Node *root1, Node *root2) {
    if ( root1 == NULL && root2 == NULL )
        return NULL;
    if ( root1 == NULL )
        return root2;
    if ( root2 == NULL )
        return root1;
    root1->val += root2->val;
    root1->left = treeOR(root1->left, root2->left);
    root1->right = treeOR(root1->right, root2->right);
    return root1;
}