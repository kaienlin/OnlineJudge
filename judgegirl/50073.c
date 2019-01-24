#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXNAME 12
#define MAXN 1024

typedef struct {
    char name[MAXNAME];
    int w;
} Record;

int cmp(const void *a, const void *b) {
    Record *x = *(Record**)a, *y = *(Record**)b;
    if ( x->w != y->w )
        return (x->w > y->w) - (y->w > x->w);
    return strcmp(x->name, y->name);
}

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1], "rb");
    Record data[MAXN], *sort[MAXN];
    int N;
    for ( N = 0; fread(data[N].name, sizeof(char), MAXNAME, fin); N++) {
        fread(&data[N].w, sizeof(int), 1, fin);
        sort[N] = &data[N];
    }
    qsort(sort, N, sizeof(Record*), cmp);
    int current_bin = sort[0]->w / 1000, sum = 0;
    for ( int i = 0; i < N; i++) {
        int idx = sort[i]->w / 1000;
        if ( idx != current_bin ) {
            printf("%d\n", sum);
            current_bin = idx;
            sum = 1;
        } else {
            sum++;
        }
    }
    printf("%d\n", sum);
    puts(sort[0]->name);
    int max = sort[N-1]->w, idx = N-1;
    while ( sort[idx-1]->w == max )
        idx--;
    puts(sort[idx]->name);
    if ( N % 2 == 0 )
        printf("%lld\n", ((long long)sort[N/2]->w + sort[N/2-1]->w) / 2);
    else
        printf("%d\n", sort[N/2]->w);
    return 0;
}