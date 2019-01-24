#include <stdio.h>
#include <stdlib.h>

#define square(x) ((x) * (x))

int city[100000][2];

int cmp(const void *a, const void *b)
{
    int x1 = ((int *)a)[0];
    int y1 = ((int *)a)[1];
    int x2 = ((int *)b)[0];
    int y2 = ((int *)b)[1];
    int dis1 = x1 * x1 + y1 * y1;
    int dis2 = x2 * x2 + y2 * y2;
    if ( dis1 > dis2 ) {
        return 1;
    } else if ( dis1 < dis2 ) {
        return -1;
    } else if ( x1 != x2 ) {
        return x1 - x2;
    } else if ( y1 != y2 ) {
        return y1 - y2;
    } else {
        return 0;
    }
}

int main()
{
    int i = 0;
    while ( scanf("%d%d", &city[i][0], &city[i][1]) != EOF ) {i++;}
    qsort(city, i, sizeof(int) * 2, cmp);
    int sum = city[0][0] * city[0][0] + city[0][1] * city[0][1];
    for ( int j = 0; j < i - 1; j++) {
        sum += square(city[j][0] - city[j + 1][0]) + square(city[j][1] - city[j + 1][1]);
    }
    printf("%d", sum);
    return 0;
}