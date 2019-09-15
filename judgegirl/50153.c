#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    int perimeter = a + b + c + d + e + f + (a+c+e) + (b+d+f);
    int area = a * (b + d + f) + c * (d + f) + e * f;
    printf("%d\n%d\n", perimeter, area);
    return 0;
}
