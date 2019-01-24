#include <stdio.h>

int main(void)
{
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    int x = 2 * e;
    printf("%d\n%d", ( a * b + a * c + b * c ) * 2 + ( a + b + c- 3 * x ) * 8 * d
                   , a * b * c - (( a - x ) * ( b + c - 2 * x ) + ( c - x ) * ( b - x )) * d * 2 );
    return 0;
}
