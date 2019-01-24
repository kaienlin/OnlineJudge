#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000100

int readchar() {
    static int buf_size = 1 << 20;
    static char buf[1 << 20];
    static char *p = buf, *end = buf;
    if ( p == end ) {
        if ( (end = buf + fread(buf, 1, buf_size, stdin)) == buf )
            return EOF;
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int nonnondayo[MAXN];

int main()
{
    int N, x, y;
    ReadInt(&N);
    for ( int i = 0; i < N; i++) {
        ReadInt(&x);
        ReadInt(&y);
        nonnondayo[i] = x * x + y * y;
    }
    qsort(nonnondayo, N, sizeof(int), cmp);
    int max_n = 0, max_d, d, n;
    for ( int i = 0; i < N; i++) {
        d = nonnondayo[i++];
        n = 1;
        for (; i < N && nonnondayo[i] == d; i++, n++);
        i--;
        if ( n > max_n )
            max_n = n, max_d = d;
    }
    printf("%d\n", max_d);
    return 0;
}