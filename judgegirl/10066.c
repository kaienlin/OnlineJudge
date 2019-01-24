#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SQUARE(x) ((x)*(x))
#define T 400000

double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
    return SQUARE(x1-x2) + SQUARE(y1-y2) + SQUARE(z1-z2);
}
double frandom() {
    return (double)rand() / RAND_MAX;
}
int main()
{
    int R, N, cs = 1;
    double x, y, z;
    int pos[8][3];
    while (scanf("%d%d", &R, &N) != EOF) {
        for ( int i = 0; i < N; i++)
            scanf("%d%d%d", &pos[i][0], &pos[i][1], &pos[i][2]);
        int cnt[8] = {0};
        for ( int i = 0; i < T; i++) {
            double x = frandom() * 2 - 1, y = frandom() * 2 - 1, z = frandom() * 2 - 1;
            if ( SQUARE(x) + SQUARE(y) + SQUARE(z) > 1.0 ) {
                i--;
                continue;
            }
            x *= R, y *= R, z *= R;
            double d, min = __DBL_MAX__;
            int min_j;
            for ( int j = 0; j < N; j++) {
                if ( (d = dist(x, y, z, pos[j][0], pos[j][1], pos[j][2])) < min ) {
                    min = d;
                    min_j = j;
                }
            }
            cnt[min_j]++;
        }
        printf("Case #%d:\n", cs++);
        for ( int i = 0; i < N; i++)
            printf("%.lf\n", cnt[i] / (double)T * 100);
    }
    return 0;
}