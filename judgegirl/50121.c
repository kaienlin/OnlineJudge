#include <stdio.h>
#include <string.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int man_r, man_c, energy;
    scanf("%d%d%d", &man_r, &man_c, &energy);
    int O;
    scanf("%d", &O);
    int map[n][m];
    memset(map, 0, sizeof(map));
    map[man_r][man_c] = energy;

    int r, c, w;
    for ( int i = 0; i < O; i++) {
        scanf("%d%d%d", &r, &c, &w);
        map[r][c] = w;
    }

    int cmd, sum_w, i;
    int tmp_r, tmp_c;
    while ( scanf("%d", &cmd) != EOF ) {
        switch ( cmd ) {
            case 0:
                for ( int i = 0; i < n; i++) {
                    for ( int j = 0; j < m; j++) {
                        printf("%d", map[i][j]);
                        if ( j != m - 1 ) {
                            printf(" ");
                        } else {
                            printf("\n");
                        }
                    }
                }
                break;
            case 1:
                // c++
                sum_w = 0;
                for ( i = 1; map[man_r][man_c + i] != 0 && man_c + i < m; i++) {
                    sum_w += map[man_r][man_c + i];
                }
                if ( man_c + i > m - 1 ) {
                    sum_w = energy + 1;
                    break;
                }
                if ( energy >= sum_w ) {
                    for ( ; i >= 1; i--) {
                        swap(&map[man_r][man_c + i], &map[man_r][man_c + i - 1]);
                    }
                } else {
                    break;
                }
                man_c++;
                energy -= sum_w;
                map[man_r][man_c] = energy;
                break;
            case 2:
                // r++
                sum_w = 0;
                for ( i = 1; map[man_r + i][man_c] != 0 && man_r + i < n; i++) {
                    sum_w += map[man_r + i][man_c];
                }
                if ( man_r + i > n - 1) {
                    sum_w = energy + 1;
                    break;
                }
                if ( energy >= sum_w ) {
                    for ( ; i >= 1; i--) {
                        swap(&map[man_r + i][man_c], &map[man_r + i - 1][man_c]);
                    }
                } else {
                    break;
                }
                man_r++;
                energy -= sum_w;
                map[man_r][man_c] = energy;
                break;
            case 3:
                // c--
                sum_w = 0;
                for ( i = 1; map[man_r][man_c - i] != 0 && man_c - i >= 0; i++) {
                    sum_w += map[man_r][man_c - i];
                }
                if ( man_c - i < 0 ) {
                    sum_w = energy + 1;
                    break;
                }
                if ( energy >= sum_w ) {
                    for ( ; i >= 1; i--) {
                        swap(&map[man_r][man_c - i], &map[man_r][man_c - i + 1]);
                    }
                } else {
                    break;
                }
                man_c--;
                energy -= sum_w;
                map[man_r][man_c] = energy;
                break;
            case 4:
                // r--
                sum_w = 0;
                for ( i = 1; map[man_r - i][man_c] != 0 && man_r - i >= 0; i++) {
                    sum_w += map[man_r - i][man_c];
                }
                if ( man_r - i < 0 ) {
                    sum_w = energy + 1;
                    break;
                }
                if ( energy >= sum_w ) {
                    for ( ; i >= 1; i--) {
                        swap(&map[man_r - i][man_c], &map[man_r - i + 1][man_c]);
                    }
                } else {
                    break;
                }
                man_r--;
                energy -= sum_w;
                map[man_r][man_c] = energy;
                break;
        }
    }

    return 0;
}