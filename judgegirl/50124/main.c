#include <stdio.h>
 
int validMoveNum(int r, int c, int n, int visited[100][100]);
int nextMove(int r, int c, int n, int visited[100][100]);
 
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int knights[m + 1][2];
    int kstep[m + 1];
    int board[100][100] = {{0}};
    int r, c;
    for ( int i = 1; i <= m; i++) {
        scanf("%d%d", &r, &c);
        knights[i][0] = r;
        knights[i][1] = c;
        kstep[i] = 1;
        board[r][c] = 10000 * i;
    }
 
    const int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    const int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int d;
    int freeze = 0;
 
    while ( 1 ) {
        freeze = 0;
        for ( int i = 1; i <= m; i++) {
            r = knights[i][0];
            c = knights[i][1];
            d = nextMove(r, c, n, board);
            if ( d != -1 ) {
                board[r + dr[d]][c + dc[d]] = 10000 * i + kstep[i];
                kstep[i]++;
                knights[i][0] = r + dr[d];
                knights[i][1] = c + dc[d];
            } else {
                freeze++;
            }
        }
        if ( freeze == m ) {
            break;
        }
    }
 
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            printf("%d%c", board[i][j], j == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}