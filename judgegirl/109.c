#include <stdio.h>
#include "node.h"
#define MAXD 1000
/*
void myPrint(struct node *root, int cnt)
{
    static int p[MAXD];
    if ( root->left == NULL && root->right == NULL ) {
        p[cnt] = root->data;
        for ( int i = 0; i <= cnt; i++)
            printf("%d%c", p[i], " \n"[i == cnt]);
    } else {
        p[cnt] = root->data;
        if ( root->left != NULL ) {
            myPrint(root->left, cnt + 1);
        }
        if ( root->right != NULL ) {
            myPrint(root->right, cnt + 1);
        }
    }
}
*/
void print_all_paths(struct node *root)
{
    static int p[MAXD], cnt = 0;
    p[cnt] = root->data;
    if ( root->left == NULL && root->right == NULL ) {
        for ( int i = 0; i <= cnt; i++)
            printf("%d%c", p[i], " \n"[i == cnt]);
    } else {
        cnt++;
        if ( root->left != NULL )
            print_all_paths(root->left);
        if ( root->right != NULL )
            print_all_paths(root->right);
        cnt--;
    }
}