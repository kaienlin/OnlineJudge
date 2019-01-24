#include <stdio.h>
#include <string.h>
#define AC(r, c) (r * n + c)
#define AI(r, c) (!(r==n-1&&c==0)&&!(r==0&&c==n-1))
#define AII(r, c) (!(r==0&&c==0)&&!(r==n-1&&c==n-1))

int row[15], col[15], adj1[225], adj2[225];
int board[15][15];
int n, k;

int place(int m, int idx) {
    if ( m == 0 )
        return 1;
    if ( n*n - idx < m )
        return 0;
    int r = idx / n, c = idx % n;
    if ( row[r] == k )
        return place(m, (r+1)*n);
    int rx = r, cx = c, ry = r, cy = c;
    while (rx&&cx) {rx--, cx--;}
    while (ry && cy != n - 1) {ry--, cy++;}
    if ( row[r] < k && col[c] < k && ( AI(r, c) ? adj1[AC(rx, cx)] < k : 1 ) && (AII(r, c) ? adj2[AC(ry, cy)] < k : 1) ) {
        row[r]++;
        col[c]++;
        adj1[AC(rx, cx)]++;
        adj2[AC(ry, cy)]++;
        board[r][c] = 'o';
        if ( place(m - 1, idx + 1) )
            return 1;
        else {
            row[r]--;
            col[c]--;
            adj1[AC(rx, cx)]--;
            adj2[AC(ry, cy)]--;
            board[r][c] = '.';
        }
    }
    return place(m, idx + 1);
}

void print() {
    for ( int i = 0; i < n; i++)
        for ( int j = 0; j < n; j++) {
            printf("%c", board[i][j]);
            if ( j == n - 1 )
                puts("");
        }
}

int main()
{
    int m;
    while (~scanf("%d%d%d", &n, &m, &k)) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(adj1, 0, sizeof(adj1));
        memset(adj2, 0, sizeof(adj2));
        memset(board, '.', sizeof(board));
        if ( place(m, 0) )
            print();
        else
            puts("N");
    }
    return 0;
}