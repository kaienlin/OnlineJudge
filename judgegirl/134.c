#include <stdio.h>
#include <stdlib.h>
#define MAXN 1024

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

int cmp(const void *a, const void *b)
{
    int *x = (int*)a, *y = (int*)b;
    if ( x[1] != y[1] ) { return x[1] - y[1]; }
    return x[0] - y[0];
}

void build(Node *root, int data[][2], int n)
{
    Node **insert;
    for ( int i = 1; i < n; i++) {
        insert = data[i][0] > root->data ? &root->right : &root->left;
        while ( *insert != NULL ) {
            insert = data[i][0] > (*insert)->data ? &(*insert)->right : &(*insert)->left;
        }
        *insert = (Node *)malloc(sizeof(Node));
        (*insert)->data = data[i][0];
        (*insert)->left = (*insert)->right = NULL;
    }
}

int search(Node *root, int a, int b)
{
    int same = 1, diverge = 0;
    Node *a_search = root, *b_search = root;
    int a_done = 0, b_done = 0, da = 1, db = 1, ca, cb;
    while ( !(a_done && b_done) ) { // be careful with De Morgan's Law!!
        if ( !a_done ) {
            if ( a == a_search->data ) {
                a_done = 1;
            } else if ( a > a_search->data ) {
                da++;
                a_search = a_search->right;
                ca = 1;
            } else if ( a < a_search->data ) {
                da++;
                a_search = a_search->left;
                ca = 0;
            }
        }
        if ( !b_done ) {
            if ( b == b_search->data ) {
                b_done = 1;
            } else if ( b > b_search->data ) {
                db++;
                b_search = b_search->right;
                cb = 1;
            } else if ( b < b_search->data ) {
                db++;
                b_search = b_search->left;
                cb = 0;
            }
        }
        if ( ca == cb && !diverge && !a_done && !b_done) {
            same++;
        } else {
            diverge = 1;
        }
    }
    return da + db - same * 2;
}

int main()
{
    int n;
    scanf("%d", &n);
    Node *root = (Node *)malloc(sizeof(Node));
    int data[MAXN][2];
    for ( int i = 0; i < n; i++) {
        scanf("%d%d", &data[i][0], &data[i][1]);
    }
    qsort(data, n, sizeof(*data), cmp);
    root->data = data[0][0];
    root->left = root->right = NULL;
    build(root, data, n);
    int p, a, b;
    scanf("%d", &p);
    while (p--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", search(root, a, b));
    }
    return 0;
}