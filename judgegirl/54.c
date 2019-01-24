#include <stdio.h>

int main(void)
{
    int i, j;
    int x, y;
    int count = 0;
    scanf("%d%d", &x, &y);

    for ( i = 1; i <= 6; i++) {
        if ( y % 100 == x ) {
            count++;
        }
        y /= 10;
    }
    printf("%d", count);
    return 0;
}
