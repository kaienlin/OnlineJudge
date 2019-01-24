#include <stdio.h>
#include <stdlib.h>
#define MAXN 11

int rec(int idx, int N, int d, int min, int relation[][MAXN], int used[], int pos[], int line[]) {
    if ( d >= min )
        return min;
    if ( idx == N )
        return d;
    for ( int i = 0; i < N; i++) {
        if ( !used[i] ) {
            used[i] = 1;
            pos[i] = idx;
            line[idx] = i;
            int add = 0;
            for ( int j = 0; j < idx; j++)
                if ( relation[i][ line[j] ] )
                    add += idx - pos[ line[j] ];
            if ( d + add >= min ) {
                used[i] = 0;
                continue;
            }
            min = rec(idx + 1, N, d + add, min, relation, used, pos, line);
            used[i] = 0;
        }
    }
    return min;
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    int relation[MAXN][MAXN] = {{0}};
    int a, b;
    while (M--) {
        scanf("%d%d", &a, &b);
        relation[a][b] = 1;
        relation[b][a] = 1;
    }
    int position[MAXN], used[MAXN] = {0}, line[MAXN];
    printf("%d\n", rec(0, N, 0, __INT_MAX__, relation, used, position, line));
    return 0;
}