#include <stdio.h>

int main(void)
{
    int x, y;
    int a, b, c, d, e, f;
    int n;
    scanf("%d%d%d%d", &x, &a, &b, &c);
    scanf("%d%d%d%d", &y, &d, &e, &f);
    scanf("%d", &n);

    // 0 paper
    // 1 scissor
    // 2 stone

    int count = 0;
    for ( int i = 1; i <= n;) {
        if ( x % 3 == 0 ) {
            switch ( y % 3 ) {
                case 0:
                    count++;
                    break;
                case 1:
                    count++;
                    printf("1 %d\n", count);
                    count = 0;
                    i++;
                    break;
                case 2:
                    count++;
                    printf("0 %d\n", count);
                    count = 0;
                    i++;
                    break;
            }
        } else if ( x % 3 == 1 ) {
            switch ( y % 3 ) {
                case 0:
                    count++;
                    printf("0 %d\n", count);
                    count = 0;
                    i++;
                    break;
                case 1:
                    count++;
                    break;
                case 2:
                    count++;
                    printf("1 %d\n", count);
                    count = 0;
                    i++;
                    break;
            }
        } else if ( x % 3 == 2 ) {
            switch ( y % 3 ) {
                case 0:
                    count++;
                    printf("1 %d\n", count);
                    count = 0;
                    i++;
                    break;
                case 1:
                    count++;
                    printf("0 %d\n", count);
                    count = 0;
                    i++;
                    break;
                case 2:
                    count++;
                    break;
            }
        }
        x = (a * x + b) % c;
        y = (d * y + e) % f;
    }

    return 0;
}
