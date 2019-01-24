#include <stdio.h>
#include <string.h>

void move(int board[4][4], int zero[2], int dir)
{
    switch(dir) {
        case 0:
            board[zero[0]][zero[1]] = board[zero[0]-1][zero[1]];
            board[zero[0]-1][zero[1]] = 0;
            zero[0]--;
            break;
        case 1:
            board[zero[0]][zero[1]] = board[zero[0]+1][zero[1]];
            board[zero[0]+1][zero[1]] = 0;
            zero[0]++;
            break;
        case 2:
            board[zero[0]][zero[1]] = board[zero[0]][zero[1]-1];
            board[zero[0]][zero[1]-1] = 0;
            zero[1]--;
            break;
        case 3:
            board[zero[0]][zero[1]] = board[zero[0]][zero[1]+1];
            board[zero[0]][zero[1]+1] = 0;
            zero[1]++;
            break;
    }
}

int puzzle(int board[4][4], int zero[2], int K)
{
    int win = 1, fault = 0;
    for ( int i = 0, num = 1; i < 16; i++, num++) {
        if ( board[i / 4][i % 4] != num % 16 ) {
            win = 0;
            fault++;
        }
    }
    if ( win )
        return 1;
    if ( fault / 2 > K )
        return 0;
    int ret = 0;
    for ( int i = 0; i < 4; i++) {
        if ( (i == 0 && zero[0] == 0) || (i == 1 && zero[0] == 3) || (i == 2 && zero[1] == 0) || (i == 3 && zero[1] == 3) )
            continue;
        int dup[4][4], z[2];
        memcpy(dup, board, sizeof(dup));
        memcpy(z, zero, sizeof(z));
        move(dup, z, i);
        ret += puzzle(dup, z, K - 1);
    }
    return !!ret;
}

int main()
{
    int K;
    int board[4][4];
    int pos0[2];
    while ( scanf("%d", &K) != EOF ) {
        for ( int i = 0; i < 4; i++) {
            for ( int j = 0; j < 4; j++) {
                scanf("%d", &board[i][j]);
                if ( board[i][j] == 0 ) {
                    pos0[0] = i;
                    pos0[1] = j;
                }
            }
        }
        printf("%d\n", puzzle(board, pos0, K));
    }
}