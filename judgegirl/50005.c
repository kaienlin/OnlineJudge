#include <stdio.h>
#include <math.h>
 
int main()
{
    int n, k, m, d;
    scanf("%d%d%d%d", &n, &k, &m, &d);
    int matrix[n][n];
    int pattern[k][k];
    int sum = 0;
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for ( int i = 0; i < k; i++) {
        for ( int j = 0; j < k; j++) {
            scanf("%d", &pattern[i][j]);
            sum += pattern[i][j];
        }
    }
    int match_r = -1, match_c = -1;
    int no_match, sum_d;
    for ( int i = 0; i <= n - k; i++) {
        for ( int j = 0; j <= n - k; j++) {
            no_match = 0;
            sum_d = 0;
            for ( int x = 0; x < k; x++) {
                for ( int y = 0; y < k; y++) {
                    sum_d += matrix[i + x][j + y];
                    if ( matrix[i + x][j + y] != pattern[x][y] ) {
                        no_match++;
                    }
                }
            }
            if ( no_match <= m && abs(sum - sum_d) <= d ) {
                match_r = i;
                match_c = j;
            } 
        }
    }
 
    printf("%d %d", match_r, match_c);
 
    return 0;
}