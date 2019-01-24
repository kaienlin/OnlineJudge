#include <stdio.h>
#include <string.h>

int notIn(int c, char *print)
{
    while (*print != '\0')
        if ( c == *print++ )
            return 0;
    return 1;
}

void derange(int n, int rule[10][10], char print[10], int idx)
{
    if ( idx == n ) {
        print[n] = '\0';
        puts(print);
        return;
    } else {
        for ( int i = 0; i < n; i++) {
            if ( rule[i][idx] && notIn(i + 'A', print) ) {
                char dummy[10];
                memcpy(dummy, print, sizeof(dummy));
                dummy[idx] = i + 'A';
                derange(n, rule, dummy, idx + 1);
            }
        }
    }
}

int main()
{
    int n, m;
    int rule[10][10], x, y;
    while ( scanf("%d%d", &n, &m) != EOF ) {
        memset(rule, 1, sizeof(rule));
        for ( int i = 0; i < m; i++) {
            scanf("%d%d", &x, &y);
            rule[x - 1][y - 1] = 0;
        }
        char print[10];
        memset(print, 0, sizeof(print));
        derange(n, rule, print, 0);
    }
    return 0;
}