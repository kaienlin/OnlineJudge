/* 反省: 未看清楚題目, 誤以為invalid move會使玩家喪失該回合移動權 
   WA*6 */

#include <stdio.h>

int main(void)
{
    int n; // total moves
    scanf("%d", &n);

    int ttt[3][3] = {{0}}; // grid
    int i, j; // counter
    int x, y; // the position of chess
    int win = 0; // 0 = nobody wins, 1 = white wins, 2 = black wins
    int win_confirm = 0; // ensure winner will not be changed
    int current_player = 2;

    for (i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);

        // check if move is valid
        if ( x <= 2 && x >= 0 && y <= 2 && y >= 0 && ttt[x][y] == 0) {
            ttt[x][y] = current_player; // 2 is black, 1 is white
            current_player = current_player - 1 ? 1 : 2; 
        } else {
            continue;
        }

        // check if anyone wins
        for (j = 0; j < 3; j++) {
            if ( ttt[j][0] == ttt[j][1] && ttt[j][0] == ttt[j][2] && ttt[j][0] != 0 && win_confirm == 0) {
                win = ttt[j][0];
                win_confirm = 1;
            }
        }
        for (j = 0; j < 3; j++) {
            if ( ttt[0][j] == ttt[1][j] && ttt[0][j] == ttt[2][j] && ttt[0][j] != 0 && win_confirm == 0) {
                win = ttt[0][j];
                win_confirm = 1;
            }
        }
        if ( ttt[0][0] == ttt[1][1] && ttt[0][0] == ttt[2][2] && ttt[0][0] != 0 && win_confirm == 0) {
            win = ttt[0][0];
            win_confirm = 1;
        }
        if ( ttt[0][2] == ttt[1][1] && ttt[0][2] == ttt[2][0] && ttt[0][2] != 0 && win_confirm == 0) {
            win = ttt[0][2];
            win_confirm = 1;
        } // end check
    }

    switch (win) {
        case 0:
            printf("There is a draw.");
            break;
        case 1:
            printf("White wins.");
            break;
        case 2:
            printf("Black wins.");
            break;
    }
    return 0;
}
