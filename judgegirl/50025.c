#include <stdio.h>
#include <string.h>

int n;
int friend[100][100], picked[100];
int solved = 0;

void indep(int m, int idx, int invalid[]) {
    if ( m == 0 ) {
        int f = 0;
        for ( int i = 0; i < n; i++) {
            if ( f && picked[i] )
                putchar(' ');
            if ( picked[i] ) {
                printf("%d", i);
                f = 1;
            }
        }
        putchar('\n');
        solved = 1;
        return;
    }
    int cnt = 0;
    for ( int i = idx; i < n; i++)
        if ( !invalid[i] )
            cnt++;
    if ( cnt < m ) {return;}
    if ( !invalid[idx] ) {
        int inv_cpy[100];
        memcpy(inv_cpy, invalid, sizeof(inv_cpy));
        for ( int i = 0; i < n; i++)
            if ( friend[idx][i] )
                inv_cpy[i] = 1;
        picked[idx] = 1;
        indep(m - 1, idx + 1, inv_cpy);
    }
    if ( solved ) {return;}
    picked[idx] = 0;
    indep(m, idx + 1, invalid);
    if ( solved ) {return;}
}

int main()
{
    int m;
    while ( scanf("%d%d", &n, &m) != EOF ) {
        for ( int i = 0; i < n; i++)
            for ( int j = 0; j < n; j++)
                scanf("%d", &friend[i][j]);
        int invalid[100] = {0};
        memset(picked, 0, sizeof(picked));
        solved = 0;
        indep(m, 0, invalid);
        if ( !solved )
            puts("no solution");
    }
    return 0;
}