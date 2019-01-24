#include <stdio.h>
#include <math.h>

int main(void)
{
    int a, b, c, d, e, p, q, r, s, x, y, F;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &p, &q, &r, &s, &x, &y, &F);

    int g = 0;
    g += abs(x * c + y * d) % e;
    for ( ; F > 0; F--) {
        switch ( abs(a * x + b * y) % 4 ) {
            case 0:
                y++;
                break;
            case 1:
                x++;
                break;
            case 2:
                y--;
                break;
            case 3:
                x--;
                break;
        }

        if ( x == p && y == q ) {
            x = r;
            y = s;
        } else if ( x == r && y == s ) {
            x = p;
            y = q;
        } else {
            g += abs(x * c + y * d) % e;
        }
    }

    printf("%d\n%d %d", g, x, y);

    return 0;
}