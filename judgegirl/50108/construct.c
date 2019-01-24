#include <stdlib.h>
#include <string.h>
#include "construct.h"
#define MAXN 16384

typedef struct {
    int idx, val;
} Pair;

int cmp(const void *a, const void *b) {
    Pair *x = (Pair*)a, *y = (Pair*)b;
    return y->val - x->val;
}
int k_largest(int seq[], int l, int r, int k) {
    Pair sort[MAXN];
    int size = r - l + 1;
    for ( int i = l, j = 0; i <= r; i++, j++)
        sort[j].idx = i, sort[j].val = seq[i];
    qsort(sort, size, sizeof(Pair), cmp);
    return sort[k-1].idx;
}
Node *new_node(int val) {
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->value = val;
    ret->left = ret->right = NULL;
    return ret;
}
Node *left_list(int seq[], int l, int r) {
    if ( l > r )
        return NULL;
    Node *ret = new_node(seq[r]);
    Node *prev = ret;
    for ( int i = r - 1; i >= l; i--) {
        prev->left = new_node(seq[i]);
        prev = prev->left;
    }
    return ret;
}
Node *build_tree(int seq[], int l, int r) {
    if ( l > r )
        return NULL;
    if ( r - l + 1 < MAXLENGTH )
        return left_list(seq, l, r);
    int idx = k_largest(seq, l, r, MAXLENGTH);
    Node *ret = new_node(seq[idx]);
    ret->left = build_tree(seq, l, idx - 1);
    ret->right = build_tree(seq, idx + 1, r);
    return ret;
}
Node *ConstructTree(int sequence[], int N) {
    Node *root = build_tree(sequence, 0, N - 1);
    return root;
}