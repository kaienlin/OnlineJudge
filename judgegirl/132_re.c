#include <stdio.h>
#include <stdlib.h>
int N, C;

void color(int idx, int result[], int adj[][20]) {
    if ( idx == N ) {
        for ( int i = 0; i < N; i++)
            printf("%d\n", result[i]);
        exit(0);
    }
    for ( int i = 1; i <= C; i++) {
        int isvalid = 1;
        for ( int j = 0; j < idx; j++)
            if ( adj[idx][j] && result[j] == i )
                isvalid = 0;
        if ( isvalid ) {
            result[idx] = i;
            color(idx + 1, result, adj);
        }
    }
}

int main()
{
    int P;
    scanf("%d%d%d", &N, &C, &P);
    int adj[20][20] = {{0}}, a, b;
    for ( int i = 0; i < P; i++) {
        scanf("%d%d", &a, &b);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    int result[8];
    color(0, result, adj);
    puts("no solution.");
    return 0;
}