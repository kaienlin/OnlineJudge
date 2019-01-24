/* 
 * Why I spent so much time ( an hour ) : 
 *   1. not notice that I refer outside the array
 *   2. not clearly realize the task description
*/

int record[1024][1024] = {{0}};

int valid(int r, int c, int n, int m)
{
    if ( r >= 0 && r < n && c >= 0 && c < m ) {
        return 1;
    }
    return 0;
}

void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[])
{
    const int dr[8] = {0, 0, 1, -1, 1, -1, -1, 1};
    const int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int count = 0;
    int a = 1, b = 1;
    
    while ( 1 ) {
        if ( !a && !b ) {break;}
        record[A_r][A_c] = 'a';
        record[B_r][B_c] = 'b';

        int maxa = -1, minb = 1 << 30;
        int da, db;
        for ( int i = 0; i < 8; i++) {
            if ( map[A_r + dr[i]][A_c + dc[i]] > maxa && map[A_r + dr[i]][A_c + dc[i]] > map[A_r][A_c] && a && valid(A_r + dr[i], A_c + dc[i], N, M)) {
                da = i;
                maxa = map[A_r + dr[i]][A_c + dc[i]];
            }
            if ( map[B_r + dr[i]][B_c + dc[i]] < minb && map[B_r + dr[i]][B_c + dc[i]] < map[B_r][B_c] && b && valid(B_r + dr[i], B_c + dc[i], N, M)) {
                db = i;
                minb = map[B_r + dr[i]][B_c + dc[i]];
            }
        }

        if ( maxa == -1 && a ) {
            directionA[count] = -1;
            a = 0;
        }
        if ( minb == 1 << 30 && b ) {
            directionB[count] = -1;
            b = 0;
        }

        if ( a ) {
            directionA[count] = da;
            A_r += dr[da];
            A_c += dc[da];
        }
        if ( b ) {
            directionB[count] = db;
            B_r += dr[db];
            B_c += dc[db];
        }
        
        count++;

        if ( A_r == B_r && A_c == B_c ) {
            directionA[count] = -1;
            directionB[count] = -1;
            break;
        }
        if ( record[A_r][A_c] == 'b') {
            directionA[count] = -1;
            a = 0;
        }
        if ( record[B_r][B_c] == 'a') {
            directionB[count] = -1;
            b = 0;
        }
    }
}
