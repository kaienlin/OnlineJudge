#include "attraction.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Attraction *a;
    long long cmp;
} D;

/* Since N can be 2^32-1, the min distance (N/2)*10+x could be larger than __INT_MAX__ */

long long min_dist(int N, Attraction *p) {
    const int table[4] = {1, 2, 3, 4};
    long long ary[4] = {p->y, N - p->x - 1, N - p->y - 1, p->x};
    long long min = 0x7fffffffLL + 1;
    int min_idx;
    for ( int i = 0; i < 4; i++)
        if ( ary[i] < min )
            min = ary[i], min_idx = i;
    return min * 10 + (long long)table[min_idx];
}
int cmp(const void *a, const void *b) {
    D *d1 = *(D**)a, *d2 = *(D**)b;
    if ( d1->cmp == d2->cmp ) {
        Attraction *a1 = (Attraction*)d1->a, *a2 = (Attraction*)d2->a;
        if ( a1->x == a2->x ) {
            if ( d1->cmp % 10 == 4 )
                return (a1->y < a2->y) - (a1->y > a2->y);
            return (a1->y > a2->y) - (a1->y < a2->y);
        } else {
            if ( d1->cmp % 10 == 3 )
                return (a1->x < a2->x) - (a1->x > a2->x);
            return (a1->x > a2->x) - (a1->x < a2->x);
        }
    }
    return (d1->cmp > d2->cmp) - (d1->cmp < d2->cmp);
}

D data[MAXM];

int main(int argc, char *argv[])
{
    int N, M;
    scanf("%d%d", &N, &M);
    FILE *f = fopen(argv[1], "rb");
    Attraction buffer[MAXM];
    fread(buffer, sizeof(Attraction), MAXM, f);
    D *sort[MAXM];
    for ( int i = 0; i < M; i++) {
        data[i].a = &buffer[i];
        data[i].cmp = min_dist(N, &buffer[i]);
        sort[i] = &data[i];
    }
    qsort(sort, M, sizeof(D*), cmp);
    for ( int i = 0; i < M; i++)
        printf("%d %d\n", sort[i]->a->x, sort[i]->a->y);
    return 0;
}