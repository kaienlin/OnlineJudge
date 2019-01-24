#include <stdio.h>

int main(void)
{
    int n, i;
    scanf("%d", &n);
    for ( i = 1; i < n; i++) {
        printf("%d\n", i);
    }
    for ( i = n; i > 0; i--) {
        printf("%d\n", i);
    }
    return 0;
}
