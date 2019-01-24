#include <stdio.h>

int table[14][14], min = __INT_MAX__, N;
int visited[14];

void travel(int idx, int dist, int cnt) {
    if ( dist >= min )
        return;
    if ( cnt == N ) {
        min = dist;
        return;
    }
    if ( cnt == N - 1 )
        travel(0, dist + table[idx][0], cnt+1);
    for ( int i = 1; i < N; i++) {
        if ( i != idx && !visited[i] ) {
            visited[i] = 1;
            travel(i, dist + table[idx][i], cnt+1);
            visited[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &N);
    for ( int i = 0; i < N; i++)
        for ( int j = 0; j < N; j++)
            scanf("%d", &table[i][j]);
    travel(0, 0, 0);
    printf("%d", min);
    return 0;
}