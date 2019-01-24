#include <stdio.h>

int chx(int x, int y, int n, int m) {
    if ( x == 0 && y == 0 )
        return 1;
    if ( x == 1 && y == m - 1 )
        return -1;
    if ( y % 2 == 0 && x != n - 1 && x != 0 )
        return 1;
    if ( y % 2 == 1 && x < n && x > 1 )
        return -1;
    return 0;
}

int chy(int x, int y, int n, int m) {
    if ( x == 0 && y != 0 )
        return -1;
    if ( x == 1 && y % 2 == 1 && y != m - 1 )
        return 1;
    if ( x == n - 1 && y % 2 == 0 )
        return 1;
    return 0;
}

int main()
{
    int n, m, x, y;
    int dx, dy;
    while ( ~scanf("%d%d%d%d", &n, &m, &x, &y) ) {
        int t = n * m + 1;
        while (t--) {
            printf("%d %d\n", x, y);
            dx = chx(x, y, n, m);
            dy = chy(x, y, n, m);
            x += dx;
            y += dy;
        }
    }
}