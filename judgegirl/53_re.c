#include <stdio.h>
#include <stdlib.h>
int N, set[16];
int print[16], used[16];

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
void go(int idx) {
    if ( idx == N ) {
        for ( int i = 0; i < N; i++)
            printf("%d%c", print[i], " \n"[i==N-1]);
        return;
    }
    for ( int i = 0; i < N; i++)
        if ( !used[i] ) {
            print[idx] = set[i];
            used[i] = 1;
            go(idx+1);
            used[i] = 0;
        }
}
int main()
{
    scanf("%d", &N);
    for ( int i = 0; i < N; i++)
        scanf("%d", &set[i]);
    qsort(set, N, sizeof(int), cmp);
    go(0);
    return 0;
}