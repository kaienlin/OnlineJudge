#include <stdio.h>
#include <string.h>

/* Things to remember:
    1. Always consider the time limit, reducing all unnecessary steps as possible
    2. When dealing with array like coordinate, write down some note on paper
    3. I spent too much time on this problem, though it is not very difficult, this is an alert.
*/

void tank_clean(int tank_x, int tank_y, int l, int w, int n, int m, int map[n][m])
{
    int i, j;
    for ( i = 0; i < l; i++) {
        for ( j = 0; j < w; j++) {
            map[tank_y + i][tank_x + j] = 0;
        }
    }
}

void tank_move(int tank_x, int tank_y, int l, int w, int n, int m, int map[n][m])
{
    int i, j;
    for ( i = 0; i < l; i++) {
        for ( j = 0; j < w; j++) {
            map[tank_y + i][tank_x + j] = 1;
        }
    }
}
 
int main(void)
{
    int n, m, l, w; // n, l//y; m, w//x  
    scanf("%d%d%d%d", &n, &m, &l, &w);
    int map[n][m];
    memset(map, 0, sizeof(map));
    int o; // number of obstacles
    int i; // counter
    int y, x;
    scanf("%d", &o);
    for ( i = 0; i < o; i++) {
        scanf("%d%d", &x, &y);
        map[y][x] = 2;
    }
    x = 0;
    y = 0;

    int instr;
    int obs;
    while ( scanf("%d", &instr) != EOF ) {
        switch(instr) {
            case 0:
                tank_move(x, y, l, w, n, m, map);
                for ( int i = 0; i < n; i++) {
                    for ( int j = 0; j < m; j++) {
                        printf("%d", map[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 1:
                if ( x + w < m ) {
                    obs = 0;
                    for ( int i = 0; i < l && obs < 2; i++) {
                        if ( map[y + i][x + w] == 2 ) {
                            obs++;
                        }
                    }
                    if ( obs < 2 ) {
                        tank_clean(x, y, l, w, n, m, map);
                        x++;
                    }
                }
                break;
            case 2:
                if ( y + l < n ) {
                    obs = 0;
                    for ( int i = 0; i < w && obs < 2; i++) {
                        if ( map[y + l][x + i] == 2 ) {
                            obs++;
                        }
                    }
                    if ( obs < 2 ) {
                        tank_clean(x, y, l, w, n, m, map);
                        y++;
                    }
                }
                break;
            case 3:
                if ( x != 0 ) {
                    obs = 0;
                    for ( int i = 0; i < l && obs < 2; i++) {
                        if ( map[y + i][x - 1] == 2 ) {
                            obs++;
                        }
                    }
                    if ( obs < 2 ) {
                        tank_clean(x, y, l, w, n, m, map);
                        x--;
                    }
                }
                break;
            case 4:
                if ( y != 0 ) {
                    obs = 0;
                    for ( int i = 0; i < w && obs < 2; i++) {
                        if ( map[y - 1][x + i] == 2 ) {
                            obs++;
                        }
                    }
                    if ( obs < 2 ) {
                        tank_clean(x, y, l, w, n, m, map);
                        y--;
                    }
                }
                break;
            case 5:
                if ( x + w < m && y + l < n ) {
                    obs = 0;
                    for ( int i = 1; i <= l && obs < 2; i++) {
                        if ( map[y + i][x + w] == 2 ) {
                            obs++;
                        }
                    }
                    for ( int i = 1; i < w && obs < 2; i++) {
                        if ( map[y + l][x + i] == 2 ) {
                            obs++;
                        }
                    }
                    if ( obs < 2 ) {
                        tank_clean(x, y, l, w, n, m, map);
                        x++;
                        y++;
                    }
                }
                break;
        }
    }
 
    return 0;
}