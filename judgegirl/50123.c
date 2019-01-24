#include <stdio.h>

int grid[1000][1000] = {{0}};

int main()
{
    int n, k, x, y;
    scanf("%d%d%d%d", &n, &k, &x, &y);
    int count = 1;
    if ( k != 1 ) {
        k--;
        while ( k-- ) {
            x++;
            y--;
            if ( x == n ) {
                x = 0;
            }
            if ( y < 0 ) {
                y = n - 1;
            }
        }
    }
    while ( count <= n * n ) {
        grid[x][y] = count;
        count++;
        x--;
        y++;
        if ( x == -1 ) {
            x = n - 1;
        }
        if ( y == n ) {
            y = 0;
        }
        if ( grid[x][y] != 0 ) {
            x++;
            y--;
            if ( x == n ) {
                x = 0;
            }
            if ( y == -1 ) {
                y = n - 1;
            }
            x++;
            if ( x == n ) {
                x = 0;
            }
        }
    }
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            printf("%d%c", grid[i][j], j != n - 1 ? ' ' : '\n');
        }
    }
    return 0;
}