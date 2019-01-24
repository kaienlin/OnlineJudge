#include <stdio.h>
 
int main(void)
{
    int k, num;
    int x;
    int remainder = 0;
    int z = 0;
    scanf("%d", &k);
    while ( scanf("%d", &num) != EOF ) {
        num += remainder * 10;
        if ( num / k != 0 ) {
            z = 1;
        }
        if ( z ) {
            printf("%d\n", num / k );
        }
        remainder = num % k;
    }
    if ( z == 0 ) {
        printf("0\n");
    }

    return 0;
}
