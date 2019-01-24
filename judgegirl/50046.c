#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int p[m][m];
    int w[m][m];
    int c;
    int t = 2 * m * m;
    int h;
    for ( int i = 0; i < m; i++) {
        for ( int j = 0; j < m; j++) {
            w[i][j] = 1;
        }
    }

    for ( int i = 1; i <= n; i++) {
        scanf("%d", &c);
        h = 0;
        for ( int j = 0; j < m; j++) {
            for ( int k = 0; k < m; k++) {
                scanf("%d", &p[j][k]);
                h += w[j][k] * p[j][k];
            }
        }
        if ( h >= t ) {
            // accept
            if ( c == 1 ) {
                continue;
            } else {
                for ( int j = 0; j < m; j++) {
                    for ( int k = 0; k < m; k++) {
                        if ( p[j][k] && w[j][k] >= 2 ) {
                            w[j][k] /= 2;
                        }
                    }
                }
            }
        } else {
            // reject
            if ( c == 1 ) {
                for ( int j = 0; j < m; j++) {
                    for ( int k = 0; k < m; k++) {
                        if ( p[j][k] ) {
                            w[j][k] *= 2;
                        }
                    }
                }
            } else {
                continue;
            }
        }
    }

    int q;
    int pixel;
    scanf("%d", &q);
    for ( int i = 1; i <= q; i++) {
        h = 0;
        for ( int j = 0; j < m; j++) {
            for ( int k = 0; k < m; k++) {
                scanf("%d", &pixel);
                h += w[j][k] * pixel;
            }
        }
        if ( h >= t ) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}