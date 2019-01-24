#include <stdio.h>

int aplusb(int vx, int vy, int vx1, int vy1, int vx2, int vy2)
{
    // a * vx1 + b * vx2 = vx
    // a * vy1 + b * vy2 = vy
    // delta = vx1 * vy2 - vx2 * vy1
    // delta a = vx * vy2 - vx2 * vy
    // delta b = vx1 * vy - vx * vy1
    if ( vx1 * vy2 - vx2 * vy1 == 0 ) { return 1; }
    double a, b;
    a = ((double)vx * vy2 - (double)vx2 * vy) / ((double)vx1 * vy2 - (double)vx2 * vy1);
    b = ((double)vx1 * vy - (double)vx * vy1) / ((double)vx1 * vy2 - (double)vx2 * vy1);
    if ( a > 0 && b > 0 ) { return 1; }
    else if ( a == 0 && b > 0 ) { return 1; }
    else if ( a > 0 && b == 0 ) { return 1; }
    else if ( a == 0 && b == 0 ) { return 1; }
    else { return 0; }
}

int main(void)
{
    int x[3], y[3];
    int tmp_x[3], tmp_y[3];
    int i, j;
    int count = 0;
    int minx = 1000, maxx = -1000, miny = 1000, maxy = -1000;
    for ( i = 0; i < 3; i++) {
        scanf("%d%d", &x[i], &y[i]);
        maxx = x[i] > maxx ? x[i] : maxx;
        minx = x[i] < minx ? x[i] : minx;
        maxy = y[i] > maxy ? y[i] : maxy;
        miny = y[i] < miny ? y[i] : miny;
    }
    
    for ( i = minx; i <= maxx; i++) {
        for ( j = miny; j <= maxy; j++) {
            if ( aplusb(x[0] - i, y[0] - j, i - x[1], j - y[1], i - x[2], j - y[2])
              && aplusb(x[0] - (i+1), y[0] - j, (i+1) - x[1], j - y[1], (i+1) - x[2], j - y[2])
              && aplusb(x[0] - i, y[0] - (j-1), i - x[1], (j-1) - y[1], i - x[2], (j-1) - y[2])
              && aplusb(x[0] - (i+1), y[0] - (j-1), (i+1) - x[1], (j-1) - y[1], (i+1) - x[2], (j-1) - y[2]) ) {
                  count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}