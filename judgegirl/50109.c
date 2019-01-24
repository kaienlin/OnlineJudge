#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 20000

typedef struct {
    char name[16];
    int cited;
} Paper;

int cmp(const void *a, const void *b) {
    Paper *x = *(Paper**)a, *y = *(Paper**)b;
    int str = strcmp(x->name, y->name);
    if ( str ) return str;
    return y->cited - x->cited;
}

int main()
{
    int N = 0;
    Paper data[MAXN], *sort[MAXN];
    while ( ~scanf("%s%d", data[N].name, &data[N].cited) ) {
        sort[N] = &data[N];
        N++;
    }
    qsort(sort, N, sizeof(Paper*), cmp);
    char *prev = sort[0]->name;
    int max = 0;
    for ( int i = 0; i < N; i++) {
        if ( !strcmp(prev, sort[i]->name) ) {
            if ( sort[i]->cited > max )
                max++;
            else
                continue;
        } else {
            printf("%s %d\n", prev, max);
            prev = sort[i]->name;
            max = 0;
            i--;
        }
    }
    printf("%s %d\n", prev, max);
    return 0;
}