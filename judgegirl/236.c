#include <stdio.h>

int main(void)
{
    int a, b;
    int i, tmp;
    int f = 1;

    while ( scanf("%d", &b) != EOF) {
        if (f-- > 0) a = b;
        if ( a != b ) {
            for ( i = 1; i <= (a > b ? b : a); i++) {
                if ( a % i == 0 && b % i == 0 ) {
                    tmp = i;
                }
            }
            a = a * b / tmp;
        } else {
            a = b;
        }
    }

    printf("%d", a);
    return 0;
}
