#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
    int idx, val;
} Elem;

typedef struct sum {
    int id1, id2, val;
} Sum;

int cmp_ele(const void *a, const void *b) {
    return ((Elem*)a)->val - ((Elem*)b)->val;
}

int cmp_sum(const void *a, const void *b) {
    Sum *x = (Sum*)a, *y = (Sum*)b;
    if ( x->val != y->val )
        return x->val - y->val;
#ifdef INC
    return (x->id1 < x->id2 ? x->id1 : x->id2) - (y->id1 < y->id2 ? y->id1 : y->id2);
#endif
#ifdef DEC
    return (x->id1 > x->id2 ? x->id1 : x->id2) - (y->id1 > y->id2 ? y->id1 : y->id2);
#endif
}

void pairPrint(int numbers[], int n) {
    Elem arr[n];
    for ( int i = 0; i < n; i++)
        arr[i] = (Elem){ i, numbers[i]};
    qsort(arr, n, sizeof(Elem), cmp_ele);
    int t = n / 2;
    Sum sss[t];
    for ( int i = 0; i < t; i++)
        sss[i] = (Sum){arr[i].idx, arr[n-1-i].idx, arr[i].val+arr[n-1-i].val};
    qsort(sss, t, sizeof(Sum), cmp_sum);
#ifdef INC
    for ( int i = 0; i < t; i++) {
        int id[2] = {sss[i].id1, sss[i].id2};
        if ( id[0] > id[1] )
            id[0] ^= id[1] ^= id[0] ^= id[1];
        printf("%d = numbers[%d] + numbers[%d]\n", sss[i].val, id[0], id[1]);
    }
#endif
#ifdef DEC
    for ( int i = t-1; i >= 0; i--) {
        int id[2] = {sss[i].id1, sss[i].id2};
        if ( id[0] < id[1] )
            id[0] ^= id[1] ^= id[0] ^= id[1];
        printf("%d = numbers[%d] + numbers[%d]\n", sss[i].val, id[0], id[1]);
    }
#endif
}