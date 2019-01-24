#include <stdio.h>
#include <math.h>

// still needed to optimize

int overlap2(int r1[4], int r2[4])
{
    if ( abs(r1[0] + r1[2] - r2[0] - r2[2]) <= (r1[2] > r2[2] ? r1[2] : r2[2]) - (r1[0] > r2[0] ? r2[0] : r1[0]) && 
         abs(r1[1] + r1[3] - r2[1] - r2[3]) <= (r1[3] > r2[3] ? r1[3] : r2[3]) - (r1[1] > r2[1] ? r2[1] : r1[1]) ) {
        int x[4], y[4];
        x[0] = r1[0]; x[1] = r1[2]; x[2] = r2[0]; x[3] = r2[2];
        y[0] = r1[1]; y[1] = r1[3]; y[2] = r2[1]; y[3] = r2[3];

        for ( int i = 0; i < 4; i++) {
            for ( int j = 0; j < 3; j++) {
                if ( x[j] > x[j+1] ) {
                    int tmp = x[j];
                    x[j] = x[j+1];
                    x[j+1] = tmp;
                }
                if ( y[j] > y[j+1] ) {
                    int tmp = y[j];
                    y[j] = y[j+1];
                    y[j+1] = tmp;
                }
            }
        }
        return abs((x[2] - x[1]) * (y[2] - y[1]));
    }
    return 0;
}

int overlap3(int r1[4], int r2[4], int r3[4])
{
    if ( overlap2(r1, r2) > 0 && overlap2(r2, r3) > 0 && overlap2(r1, r3) > 0 ) {
        int x[6], y[6];
        x[0] = r1[0], x[1] = r1[2], x[2] = r2[0], x[3] = r2[2], x[4] = r3[0], x[5] = r3[2];
        y[0] = r1[1], y[1] = r1[3], y[2] = r2[1], y[3] = r2[3], y[4] = r3[1], y[5] = r3[3];
        for ( int i = 0; i < 6; i++) {
            for ( int j = 0; j < 5; j++) {
                if ( x[j] > x[j+1] ) {
                    int tmp = x[j];
                    x[j] = x[j+1];
                    x[j+1] = tmp;
                }
                if ( y[j] > y[j+1] ) {
                    int tmp = y[j];
                    y[j] = y[j+1];
                    y[j+1] = tmp;
                }
            }
        }
        return abs((x[3] - x[2]) * (y[3] - y[2]));
    }
    return 0;
}

int main(void)
{
    int rec[3][4];
    int i, j;

    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 4; j++) {
            scanf("%d", &rec[i][j]);
        }
    }

    int area = 0;

    for ( i = 0; i < 3; i++) {
        area += (rec[i][2] - rec[i][0]) * (rec[i][3] - rec[i][1]);
    }
    area -= overlap2(rec[0], rec[1]) + overlap2(rec[1], rec[2]) + overlap2(rec[2], rec[0]);
    area += overlap3(rec[0], rec[1], rec[2]);

    printf("%d\n", area);

    return 0;
}
