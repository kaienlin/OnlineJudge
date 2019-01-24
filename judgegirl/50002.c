#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    int A[n+2][n+2], B[n+2][n+2], live[n+1][n+1];
    memset(A, 0, sizeof A);
    memset(B, 0, sizeof B);
    memset(live, 0, sizeof live);
    int i, j;
    for ( i = 1; i <= n; i++) {
        for ( j = 1; j <= n; j++) {
            scanf("%d", &A[i][j]);
            if ( A[i][j] ) { live[i][j]++; }
        }
    } // handle input and initialize conditions

    int cr;
    int count;
    int exchange = 1;
    
    for ( cr = 1; cr <= k; cr++) {
        if ( exchange ) {
            for ( i = 1; i <= n; i++) {
                for ( j = 1; j <= n; j++) {
                    count = 0;
                    if ( A[i-1][j-1] ) { count++; }
                    if ( A[i-1][j] ) { count++; }
                    if ( A[i-1][j+1] ) { count++; }
                    if ( A[i][j-1] ) { count++; }
                    if ( A[i][j+1] ) { count++; }
                    if ( A[i+1][j-1] ) { count++; }
                    if ( A[i+1][j] ) { count++; }
                    if ( A[i+1][j+1] ) { count++; }
                    if ( A[i][j] ) {
                        if ( count < 2 || count > 3) {
                            B[i][j] = 0; 
                        }
                        if ( count == 2 || count == 3 ) {
                            B[i][j] = 1;
                            live[i][j]++;
                        }
                    } else {
                        if ( count == 3 ) { 
                            B[i][j] = 1;
                            live[i][j]++;
                        }
                        else { B[i][j] = 0; }
                    }
                }
            }
        } else {
            for ( i = 1; i <= n; i++) {
                for ( j = 1; j <= n; j++) {
                    count = 0;
                    if ( B[i-1][j-1] ) { count++; }
                    if ( B[i-1][j] ) { count++; }
                    if ( B[i-1][j+1] ) { count++; }
                    if ( B[i][j-1] ) { count++; }
                    if ( B[i][j+1] ) { count++; }
                    if ( B[i+1][j-1] ) { count++; }
                    if ( B[i+1][j] ) { count++; }
                    if ( B[i+1][j+1] ) { count++; }
                    if ( B[i][j] ) {
                        if ( count < 2 || count > 3) { A[i][j] = 0; }
                        if ( count == 2 || count == 3 ) {
                            A[i][j] = 1;
                            live[i][j]++;
                        }
                    } else {
                        if ( count == 3 ) {
                            A[i][j] = 1;
                            live[i][j]++;
                        }
                        else { A[i][j] = 0; }
                    }
                }
            }
        }
        exchange = !exchange;
    }

    int max = 0, max_index1, max_index2;

    for ( i = 1; i <= n; i++) {
        for ( j = 1; j <= n; j++) {
            printf("%d%c", exchange ? A[i][j] : B[i][j], j == n ? '\n' : ' ');
            if ( live[i][j] >= max ) {
                max = live[i][j];
                max_index1 = i;
                max_index2 = j;
            }
        }
    }

    printf("%d %d", max_index1, max_index2);

    return 0;
}