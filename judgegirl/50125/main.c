#include <stdio.h>
#include "findLength.h"

int main()
{
    int N;
    scanf("%d", &N);
    int grid[256][256];
    for ( int i = 0; i < N; i++) {
        for ( int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    int len, maxlen = 0;
    for ( int i = 0; i < N; i++) {
        len = findLength(grid, N, i, 0, 0, 1);
        maxlen = len > maxlen ? len : maxlen;
        len = findLength(grid, N, i, 0, 1, 1);
        maxlen = len > maxlen ? len : maxlen;
        len = findLength(grid, N, i, 0, -1, 1);
        maxlen = len > maxlen ? len : maxlen;
        len = findLength(grid, N, 0, i, 1, 0);
        maxlen = len > maxlen ? len : maxlen;
        len = findLength(grid, N, 0, i, 1, 1);
        maxlen = len > maxlen ? len : maxlen;
        len = findLength(grid, N, N - 1, i, -1, 1);
        maxlen = len > maxlen ? len : maxlen;
    }
    printf("%d", maxlen);
    return 0;
}