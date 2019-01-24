#include <stdio.h>
#include <stdlib.h>
#define MAXN 20000

int readchar() {
    static int N = 1 << 20;
    static char buf[1 << 20];
    static char *p = buf, *end = buf;
    if ( p == end ) {
        if ( (end = buf + fread(buf, 1, N, stdin)) == buf )
            return EOF;
        p = buf;
    }
    return *p++;
}
int readInt(int *x) {
    char neg, c;
    while ((c = readchar()) < '-') { if (~c) return 0; }
    neg = c == '-' ? -1 : 1;
    *x = neg == 1 ? c - '0' : 0;
    while ((c = readchar()) >= '0')
        *x = (*x << 1) + (*x << 3) + (c - '0');
    return 1;
}

typedef unsigned long long ULL;
typedef struct {
    int id;
    ULL x;
} Data;

int cmp(const void *a, const void *b) {
    Data *x = (Data*)a, *y = (Data*)b;
    if (x->x != y->x)
        return (x->x < y->x) - (y->x < x->x);
    return x->id - y->id;
}

Data d[MAXN];

int main()
{
    int M, N;
    readInt(&M);
    readInt(&N);
    int in[6];
    for ( int i = 0; i < N; i++) {
        for ( int i = 0; i < 6; i++)
            readInt(&in[i]);
        d[i].id = in[0];
        ULL sum = in[1] + in[2] + in[3] + in[4] + in[5];
        d[i].x = (ULL)in[5] | ((ULL)in[1] << 7) | ((ULL)in[4] << 14) | ((ULL)in[2] << 21) | ((ULL)in[3] << 28) | (sum << 35);
    }
    qsort(d, N, sizeof(Data), cmp);
    for ( int i = 0; i < M; i++)
        printf("%d\n", d[i].id);
    for ( int i = M; i < N && d[i].x == d[M-1].x; i++)
        printf("%d\n", d[i].id);
    return 0;
}