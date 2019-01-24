#include <stdio.h>
#include <stdlib.h>

int K, L, N;
char print[1024];

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

void build(int idx, int prev) {
    if ( N == 0 )
        exit(0);
    print[idx] = prev + 'a';
    if ( idx == L - 1 && N > 0 ) {
        N--;
        print[L] = '\0';
        puts(print);
        return;
    }
    int list[32];
    for ( int i = 1; i <= K; i++)
        list[i-1] = (prev + i) % 26;
    qsort(list, K, sizeof(int), cmp);
    for ( int i = 0; i < K; i++) {
        build(idx + 1, list[i]);
    }
}

int main()
{
    char C, tmp[2];
    scanf("%s%d%d%d", tmp, &K, &L, &N);
    C = tmp[0];
    build(0, C - 'a');
    return 0;
}