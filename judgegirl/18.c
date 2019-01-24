#include <stdio.h>

int main(void)
{
    int r, c;
    scanf("%d%d", &r, &c);
    int a[r][c];
    int i, j;
    int check;

    for ( i = 0; i < r; i++) {
        for ( j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    } 

    for ( i = 0; i < r; i++) {
        for ( j = 0; j < c; j++) {
            check = 1;
            if ( i != 0 && a[i][j] <= a[i-1][j] ) {
                check = 0;
                continue;
            }
            if ( i != r - 1 && a[i][j] <= a[i+1][j] ) {
                check = 0;
                continue;
            }
            if ( j != 0 && a[i][j] <= a[i][j-1] ) {
                check = 0;
                continue;
            }
            if ( j != c - 1 && a[i][j] <= a[i][j+1] ) {
                check = 0;
                continue;
            }
            if ( check ) printf("%d\n", a[i][j]);
        }
    }

    return 0;
}
