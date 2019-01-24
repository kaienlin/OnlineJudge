#include <stdio.h>

int main(void)
{
    int n, m, rule, ball;
    scanf("%d%d%d", &n, &m, &rule);
    if ( rule == 0 ) {
        while ( scanf("%d", &ball) != EOF ) {
            if ( ball <= n ) {
                n -= ball;
            } else if ( ball <= m ) {
                m -= ball;
            }
            printf("%d %d\n", n, m);
        }
    } else {
        while ( scanf("%d", &ball) != EOF ) {
            if ( ball <= n && ball <= m ) {
                if ( n <= m ) {
                    n -= ball;
                } else {
                    m -= ball;
                }
            } else if ( ball <= n ) {
                n -= ball;
            } else if ( ball <= m ) {
                m -= ball;
            }
            printf("%d %d\n", n, m);
        }
    }
    return 0;
}
