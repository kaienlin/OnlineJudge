#include <stdio.h>
#include <math.h>
 
int main()
{
    int x, y, z;
    int mx, my, mz;
    int bx, by, bz;
    int N;
    scanf("%d%d%d", &x, &y, &z);
    scanf("%d%d%d%d%d%d", &mx, &my, &mz, &bx, &by, &bz);
    scanf("%d", &N);
 
    int cmd;
    int b = 1;
    for ( int i = 1; i <= N; i++) {
        scanf("%d", &cmd);
        switch ( cmd ) {
            case 1:
                x++;
                break;
            case 2:
                x--;
                break;
            case 3:
                y++;
                break;
            case 4:
                y--;
                break;
            case 5:
                z++;
                break;
            case 6:
                z--;
                break;
        }
        if ( abs(x - mx) + abs(y - my) + abs(z - mz) < 10 ) {
            i = N + 1;
            break;
        } else if ( b && abs(x - bx) + abs(y - by) + abs(z - bz) < 10 ) {
            x = bx;
            y = by;
            z = bz;
            b = 0;
        }
        if ( i <= N && i % 5 == 0 ) {
            printf("%d %d %d\n", x, y, z);
        }
    }
 
    return 0;
}