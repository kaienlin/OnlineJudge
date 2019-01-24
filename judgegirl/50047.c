void game_of_cell(int grid[50][50],int outcome[50][50],int N)
{
    int tmp[52][52] = {{0}};
    int tmp2[52][52] = {{0}};
    for ( int i = 1; i <= 50; i++) {
        for ( int j = 1; j <= 50; j++) {
            tmp[i][j] = grid[i - 1][j - 1];
        }
    } // make another array for simplicity

    int healthy;
    const int dr[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    const int dc[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    int cur = 1;
    while ( N-- ) {
        if ( cur ) {
            for ( int i = 1; i <= 50; i++) {
                for ( int j = 1; j <= 50; j++) {
                    healthy = 0;
                    for ( int k = 0; k < 8; k++) {
                        if ( tmp[i + dr[k]][j + dc[k]] == 2 ) {
                            healthy++;
                        }
                    }
                    if ( tmp[i][j] == 2 ) {
                        if ( healthy < 2 ) {
                            tmp2[i][j] = 0;
                        } else if ( healthy > 3 ) {
                            tmp2[i][j] = 1;
                        } else {
                            tmp2[i][j] = 2;
                        }
                    } else if ( tmp[i][j] == 1 && healthy == 2 ) {
                        tmp2[i][j] = 2;
                    } else if ( tmp[i][j] == 0 && healthy == 3 ) {
                        tmp2[i][j] = 2;
                    } else {
                        tmp2[i][j] = tmp[i][j];
                    }
                }
            }
        } else {
            for ( int i = 1; i <= 50; i++) {
                for ( int j = 1; j <= 50; j++) {
                    healthy = 0;
                    for ( int k = 0; k < 8; k++) {
                        if ( tmp2[i + dr[k]][j + dc[k]] == 2 ) {
                            healthy++;
                        }
                    }
                    if ( tmp2[i][j] == 2 ) {
                        if ( healthy < 2 ) {
                            tmp[i][j] = 0;
                        } else if ( healthy > 3 ) {
                            tmp[i][j] = 1;
                        } else {
                            tmp[i][j] = 2;
                        }
                    } else if ( tmp2[i][j] == 1 && healthy == 2 ) {
                        tmp[i][j] = 2;
                    } else if ( tmp2[i][j] == 0 && healthy == 3 ) {
                        tmp[i][j] = 2;
                    } else {
                        tmp[i][j] = tmp2[i][j];
                    }
                }
            }
        }
        cur = !cur;
    }
    if ( cur ) {
        for ( int i = 1; i <= 50; i++) {
            for ( int j = 1; j <= 50; j++) {
                outcome[i - 1][j - 1] = tmp[i][j];
            }
        }
    } else {
        for ( int i = 1; i <= 50; i++) {
            for ( int j = 1; j <= 50; j++) {
                outcome[i - 1][j - 1] = tmp2[i][j];
            }
        }
    }
}
