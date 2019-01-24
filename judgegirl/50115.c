#include <stdio.h>

int main(void)
{
    int a, b, h, c, d;
    scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
    printf("%d", (a * b * h) / (a * b - c * d));
    return 0;
}
