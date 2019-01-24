#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXIN 4096

typedef struct bst_node {
    int val;
    struct bst_node *left, *right;
} Node;

Node *new_node() {
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->val = 0;
    ret->left = ret->right = NULL;
    return ret;
}

Node *build(char **now) {
    Node *ret = new_node();
    while ( **now != '(' && !isdigit(**now) )
        (*now)++; // if there are no parentheses, it would plus on 'now' but not '*now'
    if ( **now == '(' ) {
        (*now)++;
        ret->left = build(now);
        ret->right = build(now);
        ret->val += ret->left == NULL ? 0 : ret->left->val;
        ret->val += ret->right == NULL ? 0 : ret->right->val;
    } else if ( isdigit(**now) ) {
        int val = 0;
        while ( isdigit(**now) ) {
            val = val * 10 + (**now - '0');
            (*now)++;
        }
        ret->val = val;
    }
    return ret;
}

void HLHR(Node *);

void HRHL(Node *root) {
    if ( root == NULL )
        return;
    printf("%d\n", root->val);
    HLHR(root->right);
    printf("%d\n", root->val);
    HLHR(root->left);
}

void HLHR(Node *root) {
    if ( root == NULL )
        return;
    printf("%d\n", root->val);
    HRHL(root->left);
    printf("%d\n", root->val);
    HRHL(root->right);
}

int main()
{
    char in[MAXIN];
    fgets(in, MAXIN, stdin);
    char *now = in;
    Node *root = build(&now);
    HLHR(root);
    return 0;
}