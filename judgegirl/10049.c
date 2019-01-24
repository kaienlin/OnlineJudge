#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define T 160000

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}

double frandom()
{
    return rand() * 1.f / RAND_MAX;
}

int main()
{
    int N, A, B, cs = 1;
    int pos[8][2];
    while ( scanf("%d%d%d", &N, &A, &B) != EOF ) {
        for ( int i = 0; i < N; i++)
            scanf("%d%d", &pos[i][0], &pos[i][1]);
        int cnt[8] = {0};
        double x, y, min;
        for ( int i = 0; i < T; i++) {
            x = A * frandom();
            y = B * frandom();
            min = __DBL_MAX__;
            int min_j;
            for ( int j = 0; j < N; j++) {
                double d = distance(x, y, (double)pos[j][0], (double)pos[j][1]);
                if ( d < min ) {
                    min_j = j;
                    min = d;
                }
            }
            cnt[min_j]++;
        }
        printf("Case #%d:\n", cs++);
        for ( int i = 0; i < N; i++)
            printf("%.lf\n", (cnt[i] / (double)T * 100));
    }
    return 0;
}