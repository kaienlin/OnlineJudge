#include <stdio.h>

int go(int map[12][12], int x, int y, int r, int c)
{
    if ( x == r - 1 ) {
        for ( int i = y; i < c; i++) {
            if ( !map[x][i] ) {
                return 0;
            }
        }
        return 1;
    } else if ( y == c - 1 ) {
        for ( int i = x; i < r; i++) {
            if ( !map[i][y] ) {
                return 0;
            }
        }
        return 1;
    } else {
        return (map[x + 1][y] ? go(map, x + 1, y, r, c) : 0) + (map[x][y + 1] ? go(map, x, y + 1, r, c) : 0);
    }
}

int main()
{
    int r, c;
    scanf("%d%d", &r, &c);
    int map[12][12];
    for ( int i = r - 1; i >= 0; i--) {
        for ( int j = 0; j < c; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    printf("%d", go(map, 0, 0, r, c));
    return 0;
}
