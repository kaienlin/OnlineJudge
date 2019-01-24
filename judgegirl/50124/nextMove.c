int validMoveNum(int r, int c, int n, int visited[100][100]);
 
int nextMove(int r, int c, int n, int visited[100][100])
{
    const int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    const int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int minp = 100;
    int min_index = 0;
    int p;
    int invalid = 0;
    for ( int i = 0; i < 8; i++) {
        p = validMoveNum(r + dr[i], c + dc[i], n, visited); \
        if ( p < minp && p >= 0 ) { // p == 0 is a valid move
            minp = p;
            min_index = i;
        } else if ( p < 0 ) {
            invalid++;
        }
    }
    if ( invalid >= 8 ) {
        return -1;
    } else {
        return min_index;
    }
}