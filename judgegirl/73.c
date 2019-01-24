#include <stdio.h>

int main(void)
{
    int n;
    int remain0 = 0, remain1 = 0, remain2 = 0;
    int i, x;
    scanf("%d", &n);

    for ( i = 1; i <= n; i++) {
        scanf("%d", &x);
        switch ( x % 3 ) {
            case 0:
                remain0++;
                break;
            case 1:
                remain1++;
                break;
            case 2:
                remain2++;
                break;
        }
    }
    printf("%d %d %d", remain0, remain1, remain2);
}
