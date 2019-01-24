#include <stdio.h>
#include <string.h>
#define MAXN 10
#define MAXM 256
#define MAXSTR 64

int pos[MAXN][1 << 16];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    char name[MAXN][MAXSTR+1];
    int num;
    for ( int i = 0; i < n; i++) {
        scanf("%s", name[i]);
        strcat(name[i], " ");
        for ( int r = 0; r < m; r++) {
            for ( int c = 0; c < m; c++) {
                scanf("%d", &num);
                pos[i][num] = r * 1000 + c;
            }
        }
    }
    int t = m * m;
    int row[MAXN][MAXM] = {{0}}, col[MAXN][MAXM] = {{0}}, adj[MAXN][2] = {{0}};
    int win_num = 0;
    char output[32768] = "";
    while (t--) {
        scanf("%d", &num);
        for ( int i = 0; i < n; i++) {
            int r = pos[i][num] / 1000, c = pos[i][num] % 1000;
            row[i][r]++;
            col[i][c]++;
            if ( r == c ) {adj[i][0]++;}
            if ( r + c == m - 1 ) {adj[i][1]++;}
            if ( row[i][r] == m || col[i][c] == m || adj[i][0] == m || adj[i][1] == m ) {
                win_num = num;
                strcat(output, name[i]);
            }
        }
        if ( win_num ) {
            output[strlen(output)-1] = '\0';
            printf("%d ", win_num);
            puts(output);
            break;
        }
    }
}