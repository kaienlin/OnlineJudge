#include "tree.h"
#include <stdlib.h>

Node *construct(Node *root, char instruction[MAXN]) {
    char *s = instruction;
    if ( !root )
        root = (Node*)calloc(1, sizeof(Node));
    Node *cur = root;
    while (1) {
        cur->data++;
        switch (*(s++)) {
            case 'L':
                if ( !cur->left )
                    cur->left = (Node*)calloc(1, sizeof(Node));
                cur = cur->left;
                break;
            case 'R':
                if ( !cur->right )
                    cur->right = (Node*)calloc(1, sizeof(Node));
                cur = cur->right;
                break;
            default:
                return root;
        }
    }
}
int query(Node *root, char instruction[MAXN]) {
    char *s = instruction;
    while (1) {
        if ( !root )
            return 0;
        switch (*(s++)) {
            case 'L':
                root = root->left;
                break;
            case 'R':
                root = root->right;
                break;
            default:
                return root->data;
        }
    }
}