void intersection(int map[100][100], int result[4])
{
    int i, j, count;
    for ( i = 0; i < 4; i++) {
        result[i] = 0;
    }

    for ( i = 0; i < 100; i++) {
        for ( j = 0; j < 100; j++) {
            count = 0;
            if ( map[i][j] == 1 ) {
                if ( i != 0 && map[i-1][j] ) {
                    count++;
                }
                if ( i != 99 && map[i+1][j] ) {
                    count++;
                }
                if ( j != 0 && map[i][j-1] ) {
                    count++;
                }
                if ( j != 99 && map[i][j+1] ) {
                    count++;
                }

                if ( count == 4 ) {
                    result[0]++;
                } else if ( count == 3 ) {
                    result[1]++;
                } else if ( count == 2 ) {
                    if ( i != 0 && i != 99 ) {
                        if ( map[i-1][j] != map[i+1][j] ) { // NOTE! Using "&& map[i-1][j] != map[i+1][j]" will cause selection keep going even when 
                            result[2]++;                   // it confirmed this is NOT a turn
                        }
                    } else if ( j != 0 && j != 99 ) {
                        if ( map[i][j-1] != map[i][j+1] ) {
                            result[2]++;
                        }
                    } else {
                        result[2]++;
                    }
                } else if ( count == 1 ) {
                    result[3]++;
                }
            } 
        }
    }
}
