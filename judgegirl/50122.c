#include <stdio.h>
 
int check_edge(int r, int c, int n)
{
    // function to check if this coordinate go out the array 
    if ( r >= 0 && c >= 0 && r < n && c < n) {
        return 1;
    } else {
        return 0;
    }
}
 
int main()
{
    const int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    const int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int n, m;
    scanf("%d%d", &n, &m);
    int board[100][100] = {{0}};
    int r, c;
    int knight[m + 1][2]; // store the position of knights, m+1 because of intuitivity
    int kstep[m + 1]; // store the current steps knights have moved
 
    for ( int i = 1; i <= m; i++) {
        scanf("%d%d", &r, &c);
        board[r][c] = i * 10000;
        knight[i][0] = r;
        knight[i][1] = c;
        kstep[i] = 1; // 0 is initial position, so 1 is first step
    } // input knights's position
 
    int freeze; // check if all knights cannot move ( terminate condition )
    while ( 1 ) {
        int p, minp, minstep = 0;
        freeze = 0;
        for ( int i = 1; i <= m; i++) { // i is knights' index
            minp = 10;
            for ( int j = 0; j < 8; j++) {
                if ( check_edge(knight[i][0] + dr[j], knight[i][1] + dc[j], n) && board[knight[i][0] + dr[j]][knight[i][1] + dc[j]] == 0 ) { // if the move is valid
                    p = 0;
                    for ( int k = 0; k < 8; k++) { // count p of j index
                        if ( check_edge(knight[i][0] + dr[j] + dr[k], knight[i][1] + dc[j] + dc[k], n) && board[knight[i][0] + dr[j] + dr[k]][knight[i][1] + dc[j] + dc[k]] == 0 ) {
                            p++;
                        }
                    }
                    if ( p < minp ) {
                        minp = p;
                        minstep = j;
                    }
                }
            } // select step with min p then min index
            if ( minp < 10 ) {
                knight[i][0] += dr[minstep];
                knight[i][1] += dc[minstep];
                board[knight[i][0]][knight[i][1]] = i * 10000 + kstep[i];
                kstep[i]++;
            } else {
                freeze++;
            }
        }
        if ( freeze == m ) {
            break;
        } // end while loop if all freeze
    }
 
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            printf("%d", board[i][j]);
            if ( j != n - 1 ) {
                putchar(' ');
            }
        }
        putchar('\n'); // format required
    }
 
    return 0;
}