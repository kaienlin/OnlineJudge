#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int n, m;
    int head[2], tail[2];
    scanf("%d%d", &n, &m);
    scanf("%d%d%d%d", &head[0], &head[1], &tail[0], &tail[1]);
    int q, cmd; // q is the number of cmd
    scanf("%d", &q);

    int grid[n][m];
    memset(grid, 0, sizeof(grid));
    
    int len;
    int horizontal;
    if ( head[0] == tail[0] ) {
        len = abs(head[1] - tail[1]) + 1;
        horizontal = 1;
    } else {
        len = abs(head[0] - tail[0]) + 1;
        horizontal = 0;
    }
    int x[len], y[len]; // indicate the position of caterpillar
    int min_x = head[0] > tail[0] ? tail[0] : head[0];
    int min_y = head[1] > tail[1] ? tail[1] : head[1];
    for ( int i = 0; i < len; i++) {
        if ( horizontal ) {
            x[i] = head[0];
            y[i] = min_y == head[1] ? head[1] + i : head[1] - i;
        } else {
            x[i] = min_x == head[0] ? head[0] + i : head[0] - i;
            y[i] = head[1];
        }
    } // to handle the problem that head's index might less than tail's index 

    int head_index = 0;
    int tail_index = len - 1;
    int mes = 0;

    for ( int i = 1; i <= q && !mes; i++) {
        scanf("%d", &cmd);
        switch(cmd) {
            case 0:
                if ( x[head_index] + 1 >= n ) {
                    i = q + 1;
                    break;
                } else {
                    for ( int j = 0; j < len; j++) {
                        if ( j != tail_index && x[head_index] + 1 == x[j] && y[head_index] == y[j]) {
                            mes = 1;
                            break;
                        }
                    }
                    if ( mes ) {
                        break;
                    }
                    x[tail_index] = x[head_index] + 1;
                    y[tail_index] = y[head_index];
                    head_index = tail_index;
                    tail_index--;
                    if ( tail_index < 0 ) {
                        tail_index = len - 1;
                    }
                }
                break;
            case 1:
                if ( x[head_index] - 1 < 0 ) {
                    i = q + 1;
                    break;
                } else {
                    for ( int j = 0; j < len; j++) {
                        if ( j != tail_index && x[head_index] - 1 == x[j] && y[head_index] == y[j]) {
                            mes = 1;
                            break;
                        }
                    }
                    if ( mes ) {
                        break;
                    }
                    x[tail_index] = x[head_index] - 1;
                    y[tail_index] = y[head_index];
                    head_index = tail_index;
                    tail_index--;
                    if ( tail_index < 0 ) {
                        tail_index = len - 1;
                    }
                }
                break;
            case 2:
                if ( y[head_index] + 1 >= m ) {
                    i = q + 1;
                    break;
                } else {
                    for ( int j = 0; j < len; j++) {
                        if ( j != tail_index && x[head_index] == x[j] && y[head_index] + 1 == y[j]) {
                            mes = 1;
                            break;
                        }
                    }
                    if ( mes ) {
                        break;
                    }
                    x[tail_index] = x[head_index];
                    y[tail_index] = y[head_index] + 1;
                    head_index = tail_index;
                    tail_index--;
                    if ( tail_index < 0 ) {
                        tail_index = len - 1;
                    }
                }
                break;
            case 3:
                if ( y[head_index] - 1 < 0 ) {
                    i = q + 1;
                    break;
                } else {
                    for ( int j = 0; j < len; j++) {
                        if ( j != tail_index && x[head_index] == x[j] && y[head_index] - 1 == y[j]) {
                            mes = 1;
                            break;
                        }
                    }
                    if ( mes ) {
                        break;
                    }
                    x[tail_index] = x[head_index];
                    y[tail_index] = y[head_index] - 1;
                    head_index = tail_index;
                    tail_index--;
                    if ( tail_index < 0 ) {
                        tail_index = len - 1;
                    }
                }
                break;
        }
    }

    int done;
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < m; j++) {
            done = 0;
            for ( int k = 0; k < len; k++) {
                if ( i == x[k] && j == y[k] ) {
                    putchar('1');
                    done = 1;
                }
            }
            if ( !done ) {
                putchar('0');
            } 
        }
        putchar('\n');
    }

    return 0;
}