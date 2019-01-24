#include <stdio.h>

int main(void)
{
    int x[3], y[3];
    int i;
    for (i = 0; i < 3; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    int dx = x[1] + x[2] - x[0];
    int dy = y[1] + y[2] - y[0];
    int ex = x[0] + x[2] - x[1];
    int ey = y[0] + y[2] - y[1];
    int fx = x[0] + x[1] - x[2];
    int fy = y[0] + y[1] - y[2];
    printf("%d\n%d\n%d\n%d\n%d\n%d\n", dx, dy, ex, ey, fx, fy);
    return 0;
}
