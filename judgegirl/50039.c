#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    printf("%d\n%d %d %d", a * d + b * e + c * f, b * f - c * e, c * d - a * f, a * e - b * d);
    return 0;
}
