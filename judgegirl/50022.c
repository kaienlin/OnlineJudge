#include <stdio.h>
#include <string.h>

int matrix[16][16];
int m, n;

int solve(int idx, int r_sum[], int c_sum[], int used[]) {
    if ( idx >= n * m ) {
        for ( int i = 0; i < m; i++)
            if ( r_sum[i] )
                return 0;
        for ( int i = 0; i < n; i++)
            if ( c_sum[i] )
                return 0;
        return 1;
    }
    int r = idx / n, c = idx % n;
    if ( r > 0 && c == 0 ) {
        if ( r_sum[r-1] )
            return 0;
    }
    int ret = 0;
    for ( int i = 0; i < n * m; i++) {
        if ( !used[i] ) {
            if ( r_sum[r] < i + 1 || c_sum[c] < i + 1 )
                break;
            int r_cpy[16], c_cpy[16], copy[16];
            memcpy(copy, used, sizeof(copy));
            memcpy(r_cpy, r_sum, sizeof(r_cpy));
            memcpy(c_cpy, c_sum, sizeof(c_cpy));
            matrix[r][c] = i + 1;
            r_cpy[r] -= i + 1;
            c_cpy[c] -= i + 1;
            copy[i] = 1;
            ret += solve(idx + 1, r_cpy, c_cpy, copy);
            if ( ret > 0 )
                break;
        }
    }
    return !!ret;
}

int main()
{
    int r_sum[16], c_sum[16];
    while (~scanf("%d%d", &m, &n)) {
        for ( int i = 0; i < m; i++)
            scanf("%d", &r_sum[i]);
        for ( int i = 0; i < n; i++)
            scanf("%d", &c_sum[i]);
        int used[16] = {0};
        if ( solve(0, r_sum, c_sum, used) )
            for ( int i = 0; i < m; i++)
                for ( int j = 0; j < n; j++)
                    printf("%d%c", matrix[i][j], " \n"[j == n-1]);
        else
            puts("no solution");
    }
    return 0;
}