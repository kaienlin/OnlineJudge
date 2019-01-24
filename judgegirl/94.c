#include <stdio.h>
#include <stdlib.h>
#define MAXL 4096

/* 累的時候真的只會寫bug而已 */

typedef struct node {
    int num;
    struct node *left, *right;
} Node;

Node *newNode()
{
    Node *ret = (Node *)malloc(sizeof(Node));
    ret->num = 0;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

void construct(Node *root, char *buf, int start, int end)
{
    root->right = newNode();
    root->left = newNode();
    if ( buf[start] == '(') {
        int x = 1, i = start + 1;
        for ( ; x != 0; i++) {
            if ( buf[i] == ')' )
                x--;
            else if ( buf[i] == '(' )
                x++;
        } // now i is on the intermidiate ','
        construct(root->left, buf, start + 1, i - 2);
        root->num += root->left->num;
        i++;
        if ( buf[i] == '(' ) {
            int x = 1;
            start = ++i;
            for ( ; x != 0; i++) {
                if ( buf[i] == ')' )
                    x--;
                else if ( buf[i] == '(' )
                    x++;
            }
            construct(root->right, buf, start, i - 2);
            root->num += root->right->num;
        } else {
            int right;
            sscanf(&buf[i], "%d", &right);
            root->right->num = right;
            root->num += right;
            return;
        }
    } else {
        int left;
        sscanf(&buf[start], "%d", &left);
        root->left->num = left;
        root->num += left;
        int i = start;
        for ( ; buf[i] != ','; i++) {;} // now i is on the intermidiate ','
        i++;
        if ( buf[i] == '(' ) {
            int x = 1;
            i++;
            start = i;
            for ( ; x != 0; i++) {
                if ( buf[i] == ')' )
                    x--;
                else if ( buf[i] == '(' )
                    x++;
            }
            construct(root->right, buf, start, i - 2);
            root->num += root->right->num;
        } else {
            int right;
            sscanf(&buf[i], "%d", &right);
            root->right->num = right;
            root->num += right;
            return;
        }
    }
}

void hrhl(Node *root);

void hlhr(Node *root)
{
    if ( root == NULL ) { return; }
    printf("%d\n", root->num);
    hrhl(root->left);
    printf("%d\n", root->num);
    hrhl(root->right);
    return;
}

void hrhl(Node *root)
{
    if ( root == NULL ) { return; }
    printf("%d\n", root->num);
    hlhr(root->right);
    printf("%d\n", root->num);
    hlhr(root->left);
    return;
}

int main()
{
    char buffer[MAXL];
    int len = fread(buffer, sizeof(char), MAXL, stdin) - 1;
    buffer[len] = '\0';
    Node *root = newNode();
    construct(root, buffer, 1, len - 2); // ignore first '(' and last ')'
    hlhr(root);
    return 0;
}