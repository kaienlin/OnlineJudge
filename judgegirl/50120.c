#include <stdio.h>
#include <string.h>
 
int main(void)
{
    int n;
    scanf("%d", &n);
    int grid[n][n];
    int i, j;
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
 
    int maxlen = 0;
    int len = 0;
    int prev = 0;
 
    for ( i = 0; i < n; i++) {
        len = 0;
        prev = 0;
        for ( j = 0; j < n; j++) {
            if ( grid[i][j] == 1 && len == 0 ) {
                len++;
                prev = 1;
            } else if ( len > 0 && prev == 1 && grid[i][j] == 1 ) {
                len++;
            } else {
                len = 0;
                prev = 0;
            }
            if ( len > maxlen ) {
                maxlen = len;
            }
        }
    }
 
    for ( j = 0; j < n; j++) {
        len = 0;
        prev = 0;
        for ( i = 0; i < n; i++) {
            if ( grid[i][j] == 1 && len == 0 ) {
                len++;
                prev = 1;
            } else if ( len > 0 && prev == 1 && grid[i][j] == 1 ) {
                len++;
            } else {
                len = 0;
                prev = 0;
            }
            if ( len > maxlen ) {
                maxlen = len;
            }
        }
    }
 
    for ( i = 0; i < n; i++) {
        len = 0;
        prev = 0;
        for ( j = 0; j <= n - i - 1; j++) {
            if ( grid[i+j][j] == 1 && len == 0 ) {
                len++;
                prev = 1;
            } else if ( len > 0 && prev == 1 && grid[i+j][j] == 1 ) {
                len++;
            } else {
                len = 0;
                prev = 0;
            }
            if ( len > maxlen ) {
                maxlen = len;
            }
        }
    }
 
    for ( j = 1; j < n; j++) {
        len = 0;
        prev = 0;
        for ( i = 1; i <= n - j; i++) {
            if ( grid[i - 1][j + i - 1] == 1 && len == 0 ) {
                len++;
                prev = 1;
            } else if ( len > 0 && prev == 1 && grid[i - 1][j + i - 1] ) {
                len++;
            } else {
                len = 0;
                prev = 0;
            }
            if ( len > maxlen ) {
                maxlen = len;
            }
        }
    }
 
    printf("%d", maxlen);
 
    return 0;
}