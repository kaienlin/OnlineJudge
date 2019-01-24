#include <stdio.h>
#include <string.h>

int main(void)
{
    int puz[6][6];
    int index[16];
    memset(puz, -1, sizeof(puz));

    for ( int i = 1; i <= 4; i++) {
        for ( int j = 1; j <= 4; j++) {
            scanf("%d", &puz[i][j]);
            index[puz[i][j]] = i * 10 + j;
        }
    }

    int done, cmd;
    while (1) {
        scanf("%d", &cmd);
        if ( cmd > 15 ) {
            continue;
        } else if ( cmd == 0 ) {
            done = 0;
            break;
        }
        int x = index[cmd] / 10, y = index[cmd] % 10;
        if ( puz[x + 1][y] == 0 ) {
            puz[x + 1][y] = cmd;
            puz[x][y] = 0;
            index[cmd] += 10;
        } else if ( puz[x - 1][y] == 0 ) {
            puz[x - 1][y] = cmd;
            puz[x][y] = 0;
            index[cmd] -= 10;
        } else if ( puz[x][y + 1] == 0 ) {
            puz[x][y + 1] = cmd;
            puz[x][y] = 0;
            index[cmd]++;
        } else if ( puz[x][y - 1] == 0 ) {
            puz[x][y - 1] = cmd;
            puz[x][y] = 0;
            index[cmd]--;
        } else {
            continue;
        }

        int num = 11;
        done = 1;
        for ( int i = 1; i <= 15; i++) {
            if ( index[i] != num ) {
                done = 0;
                break;
            }
            if ( i % 4 == 0 ) {
                num += 7;
            } else {
                num++;
            }
        }
        if ( done ) {
            for ( int i = 1; i <= 4; i++) {
                for ( int j = 1; j <= 4; j++) {
                    printf("%d", puz[i][j]);
                    if ( j != 4 ) {
                        putchar(' ');
                    }
                }
                putchar('\n');
            }
            printf("1 %d", cmd);
            break;
        }
    }

    if ( !done ) {
        for ( int i = 1; i <= 4; i++) {
            for ( int j = 1; j <= 4; j++) {
                printf("%d", puz[i][j]);
                if ( j != 4 ) {
                    putchar(' ');
                }
            }
            putchar('\n');
        }
        printf("0"); // forgot 0 for no win
    }

    return 0;
}