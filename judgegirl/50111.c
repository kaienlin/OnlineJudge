#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000
int N, adj[MAXN][MAXN], table[MAXN][MAXN], num[MAXN], path[MAXN], visit[MAXN];

int cycle(int idx, int prev, int z) {
    if ( idx == N ) {
        if ( !adj[prev][0] )
            return 0;
        for ( int i = 0; i < N; i++)
            printf("%d ", path[i]);
        printf("%d\n", path[0]);
        exit(0);
    }
    if ( z == 0 )
        return 0;
    for ( int i = 0; i < num[prev]; i++) {
        if ( !visit[ table[prev][i] ] ) {
            path[idx] = table[prev][i];
            visit[ path[idx] ] = 1;
            cycle(idx + 1, path[idx], adj[ path[idx] ][0] ? z - 1 : z);
            visit[ path[idx] ] = 0;
        }
    }
    return 0;
}
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int main()
{
    int E, Z = 0;
    scanf("%d%d", &N, &E);
    int x, y;
    while (E--) {
        scanf("%d%d", &x, &y);
        adj[x][y] = 1;
        adj[y][x] = 1;
        table[x][num[x]++] = y;
        table[y][num[y]++] = x;
        if ( x == 0 || y == 0 )
            Z++;
    }
    for ( int i = 0; i < N; i++)
        qsort(table[i], num[i], sizeof(int), cmp);
    path[0] = 0;
    visit[0] = 1;
    if ( !cycle(1, 0, Z) )
        puts("NO SOLUTION");
}