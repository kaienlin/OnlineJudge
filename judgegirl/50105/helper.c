#include "construct.h"
#include <stdlib.h>

int balance(int t[], int l, int r) {
    long long mtot = 0, rxm = 0;
    for ( int i = l, j = 0; i <= r; i++, j++) {
        mtot += t[i];
        rxm += t[i] * j;
    }
    if ( rxm % mtot == 0 )
        return l + rxm / mtot;
    return -1;
}
Node *new_node(int value) {
    Node *ret = (Node *)malloc(sizeof(Node));
    ret->value = value;
    ret->left = ret->right = NULL;
    return ret;
}
Node *link(int t[], int l, int r) {
    Node *ret = new_node(t[r]), *tail = ret;
    for ( int i = r - 1; i >= l; i--)
        tail = tail->left = new_node(t[i]);
    return ret;
}
Node *build(int t[], int l, int r, int N) {
    if ( l > r )
        return NULL;
    if ( r - l + 1 < 3 )
        return link(t, l, r);
    int bp = balance(t, l, r);
    if ( bp < 0 )
        return link(t, l, r);
    Node *ret = new_node(t[bp]);
    ret->left = build(t, l, bp - 1, N);
    ret->right = build(t, bp + 1, r, N);
    return ret;
}
Node *ConstructTree(int T[], int N) {
    return build(T, 0, N - 1, N);    
}