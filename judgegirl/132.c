#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fill(int n, int a[n][n], int color[n], int c, int index)
{
    if ( index >= n ) {
        for ( int i = 0; i < n; i++) {
            for ( int j = 0; a[i][j] != -1; j++) {
                if ( color[a[i][j]] == color[i] ) {
                    return;
                }
            }
        }
        for ( int i = 0; i < n; i++) {
            printf("%d\n", color[i]);
        }
        exit(0);
    } else {
        for ( int i = 1; i <= c; i++) {
            int dup[n];
            for ( int i = 0; i < index; i++) {
                dup[i] = color[i];
                for ( int j = 0; a[i][j] != -1; j++) {
                    if ( color[a[i][j]] == color[i] ) {
                        return;
                    }
                }
            }
            dup[index] = i;
            fill(n, a, dup, c, index + 1);
        }
    }
}

int main()
{
    int n, c, p;
    scanf("%d%d%d", &n, &c, &p);
    int adj[n][n];
    memset(adj, -1, sizeof(adj));
    int x, y;
    int count[n];
    memset(count, 0, sizeof(count));
    for ( int i = 0; i < p; i++) {
        scanf("%d%d", &x, &y);
        adj[x][count[x]++] = y;
        adj[y][count[y]++] = x;
    }
    int color[n];
    memset(color, 0, sizeof(color));
    fill(n, adj, color, c, 0);
    printf("no solution.\n");
    return 0;
}