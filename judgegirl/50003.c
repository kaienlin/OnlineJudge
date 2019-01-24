#include <stdio.h>
#include <math.h>

int main(void)
{
    int l, x, y;
    scanf("%d%d%d", &l, &x, &y);
    int graph[101][101] = {{0}}; // graph[x][y]
    int n;
    int pos_x, pos_y;
    
    for ( int i = 1; i <= l; i++) {
        scanf("%d", &n);
        for ( int j = 1; j <= n; j++) {
            int prev_x = pos_x, prev_y = pos_y;
            scanf("%d%d", &pos_x, &pos_y);
            if ( j == 1 ) {
                continue;
            } else if ( pos_x >= 0 && pos_x < y && pos_y >= 0 && pos_y < x ) {
                if ( prev_x == pos_x ) {
                    // draw horizontal line
                    int x_start = pos_y > prev_y ? prev_y : pos_y;
                    for ( int k = 0; k <= abs(pos_y - prev_y); k++ ) {
                        graph[x_start + k][pos_x] = 1;
                    }
                } else if ( prev_y == pos_y ) {
                    // draw vertical line
                    int y_start = pos_x > prev_x ? prev_x : pos_x;
                    for ( int k = 0; k <= abs(pos_x - prev_x); k++ ) {
                        graph[pos_y][y_start + k] = 1;
                    }
                } else if ( abs(pos_x - prev_x) == abs(pos_y - prev_y) ) {
                    // draw 45 degree line
                    int x_start, y_start = pos_x > prev_x ? prev_x : pos_x;
                    int m;
                    if ( pos_y > prev_y && y_start == prev_x) {
                        x_start = prev_y;
                        m = 1;
                    } else if ( prev_y > pos_y && y_start == pos_x ) {
                        x_start = pos_y;
                        m = 1; // miss this statement!
                    } else {
                        m = -1;
                        x_start = pos_y > prev_y ? pos_y : prev_y;
                    }
                    if ( m == 1 ) {
                        for (int k = 0; k <= abs(pos_x - prev_x); k++) {
                            graph[x_start + k][y_start + k] = 1;
                        } 
                    } else {
                        for (int k = 0; k <= abs(pos_x - prev_x); k++) {
                            graph[x_start - k][y_start + k] = 1;
                        }
                    }
                } else {
                    printf("ERROR %d %d", i, j);
                    return 0;
                }
            } else {
                printf("ERROR %d %d", i, j);
                return 0;
            }
        }
    }
    for ( int i = x - 1; i >= 0; i--) {
        for ( int j = 0; j < y; j++) {
            printf("%d", graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}