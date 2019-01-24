#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void traversal(Node *root, int N, int command[]) {
    Node *path[1024] = {root};
    int x = 0;
    for ( int i = 0; root != NULL && i < N; i++) {
        switch (command[i]) {
            case 0:
                printf("%d\n", root->label);
                return;
            case 1:
                printf("%d\n", root->label);
                break;
            case 2:
                if ( x < 1 ) {
                    printf("%d\n", root->label);
                    return;
                } else
                    root = path[--x];
                break;
            case 3:
                if ( root->left == NULL ) {
                    printf("%d\n", root->label);
                    return;
                }
                path[++x] = root = root->left;
                break;
            case 4:
                if ( root->right == NULL ) {
                    printf("%d\n", root->label);
                    return;
                }
                path[++x] = root = root->right;
                break;
            case 5:
                if ( root == path[x-1]->left ) {
                    if ( path[x-1]->right == NULL ) {
                        printf("%d\n", root->label);
                        return;
                    }
                    path[x] = root = path[x-1]->right;
                } else {
                    if ( path[x-1]->left == NULL ) {
                        printf("%d\n", root->label);
                        return;
                    }
                    path[x] = root = path[x-1]->left;
                }
                break;
            default:
                return;
        }
    }
}