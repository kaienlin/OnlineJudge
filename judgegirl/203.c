#include <stdio.h>

int main(void)
{
    int X, Y;
    int x1, y1, x2, y2;
    int dx1, dy1, dx2, dy2;
    int i, sec;
    scanf("%d%d%d%d%d%d%d%d%d%d%d", &X, &Y, &x1, &y1, &x2, &y2, &dx1, &dy1, &dx2, &dy2, &sec);

    for ( i = 1; i <= sec; i++) {
        x1 += dx1;
        y1 += dy1;
        x2 += dx2;
        y2 += dy2;

        if ( x1 == x2 && y1 == y2 ) {
            if ( dx1 == -dx2 ) {
                dx1 = dx1 > 0 ? -1 : 1;
                dx2 = dx2 > 0 ? -1 : 1;
            }
            if ( dy1 == -dy2 ) {
                dy1 = dy1 > 0 ? -1 : 1;
                dy2 = dy2 > 0 ? -1 : 1;
            }
        }

        if ( x1 == 1 ) dx1 = 1;
        else if ( x1 == X ) dx1 = -1;
        if ( y1 == 1 ) dy1 = 1;
        else if ( y1 == Y ) dy1 = -1;

        if ( x2 == 1 ) dx2 = 1;
        else if ( x2 == X ) dx2 = -1;
        if ( y2 == 1 ) dy2 = 1;
        else if ( y2 == Y ) dy2 = -1;
    }

    printf("%d\n%d\n%d\n%d\n", x1, y1, x2, y2);

    return 0;
}
