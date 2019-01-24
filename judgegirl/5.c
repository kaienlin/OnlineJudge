#include <stdio.h>

int main(void)
{
    int h, w, d;
    scanf("%d%d%d", &h, &w, &d);
    printf("%d\n%d", 2 * ( h * w + h * d + w * d), h * w * d);
    return 0;
}