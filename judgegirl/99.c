#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    char player_name[n][64]; 
    int player_board[n][m][m];
    int player_score[n][m][m];
    int player_win[n];
    int board_index[m * m + 1][n][2];
    int i, j, k, l;
    int num, win_num, bingo = 0;
    int count, total_winners = 0;
    
    for ( i = 0; i < n; i++) {
        scanf("%s", player_name[i]);
        player_win[i] = 0;
        for ( j = 0; j < m; j++) {
            for ( k = 0; k < m; k++) {
                scanf("%d", &player_board[i][j][k]);
                board_index[ player_board[i][j][k] ][i][0] = j;
                board_index[ player_board[i][j][k] ][i][1] = k;
                player_score[i][j][k] = 0;
            }
        }
    }

    for ( i = 1; i <= m * m; i++) {
        scanf("%d", &num);
        if ( !bingo ) {
            for ( j = 0; j < n; j++) {
                player_score[j][board_index[num][j][0]][ board_index[num][j][1] ] = 1;
            } // set all the corresponding number to 1 on player_score
        
            if ( i >= m ) {
                for ( j = 0; j < n; j++) {
                    count = 0;
                    for ( k = 0; k < m && !player_win[j]; k++) {
                        if ( player_score[j][k][k] ) {
                            count++;
                        } else {
                            break;
                        }
                        if ( count == m ) {
                            win_num = num;
                            bingo = 1;
                            player_win[j] = 1;
                            total_winners++;
                            break;
                        }
                    } // check diagonal line 1

                    count = 0;
                    for ( k = 0; k < m && !player_win[j]; k++) {
                        if ( player_score[j][k][m-k-1] ) {
                            count++;
                        } else {
                            break;
                        }
                        if ( count == m ) {
                            win_num = num;
                            bingo = 1;
                            player_win[j] = 1;
                            total_winners++;
                            break;
                        }
                    } // check diagonal line 2

                    for ( k = 0; k < m && !player_win[j]; k++) {
                        count = 0;
                        for ( l = 0; l < m; l++) {
                            if ( player_score[j][k][l] ) {
                                count++;
                            }
                            else {
                                break;
                            }
                        }
                        if ( count == m ) {
                            win_num = num;
                            bingo = 1;
                            player_win[j] = 1;
                            total_winners++;
                            break;
                        }
                    } // check horizontal lines
                    
                    for ( k = 0; k < m && !player_win[j]; k++) {
                        count = 0;
                        for ( l = 0; l < m; l++) {
                            if ( player_score[j][l][k] ) {
                                count++;
                            } else {
                                break;
                            }
                        }
                        if ( count == m ) {
                            win_num = num;
                            bingo = 1;
                            player_win[j] = 1;
                            total_winners++;
                            break;
                        }
                    } // check vertical lines
                } 
            } // check if anyone wins
        }
    }

    printf("%d ", win_num);
    for ( i = 0, j = 0; i < n && j <= total_winners; i++) {
        if ( player_win[i] ) {
            printf("%s", player_name[i]);
            j++;
            if ( j != total_winners ) {
                printf(" ");
            }
        }
    } // note the output format

    return 0;
}
