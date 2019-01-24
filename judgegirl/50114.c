#include <stdio.h>
#include <math.h>

int main(void)
{
    int x[5], y[5];
    int i;

    for ( i = 0; i < 4; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }

    x[4] = x[0];
    y[4] = y[0];

    int perimeter = 0, area;

    for ( i = 0; i < 4; i++) {
        perimeter += abs(x[i] - x[i+1]) + abs(y[i] - y[i+1]);
    }

    for ( i = 0; i < 4; i++) {
        area += 2 * x[i] * y[i];
        area -= 2 * y[i] * x[i+1];
    }

    area = abs(area) / 2;

    printf("%d\n%d", perimeter, area);

    return 0;
}
