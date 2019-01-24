#include <stdio.h>

int main(void)
{
    int s, f, t;
    scanf("%d%d%d", &s, &f, &t);
    printf("%d\n%d\n%d", 4 * s - f / 2 - 2 * t, f / 2 - 4 * s + 3 * t, s - t);
    return 0;
}