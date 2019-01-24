#include <stdio.h>

int main(void)
{
    int x, n, result = 1;
    scanf("%d%d", &x, &n);
    for (register int i = 1; i <= n; i++) {
        result *= x;
    }
    printf("%d", result);
    return 0;
}
