#include <stdio.h>

int main(void)
{
    int n;
    int i;
    int num;
    int max, min;
    int done = 0;

    while ( 1 && !done && scanf("%d", &n) != EOF ) {
        max = -10000;
        min = 10000;
        for ( i = 0; i < n; i++) {
            if ( scanf("%d", &num) == EOF ) {
                done = 1;
                break;
            }
            
            if ( num > max ) {
                max = num;
            }
            if ( num < min ) {
                min = num;
            }
        }
        if ( i == n ) {
            printf("%d\n", max);
        } else {
            printf("%d\n", min);
        }
    }
    return 0;
}
