#include <stdio.h>

int main()
{
    int n;
    while ( scanf("%d", &n) != EOF ) {
        if ( n >= 1000 ) {
            printf("%d ", n / 1000);
            n %= 1000;
        } else {
            printf("0 ");
        }
        if ( n >= 500 ) {
            printf("%d ", n / 500);
            n %= 500;
        } else {
            printf("0 ");
        }
        if ( n >= 100 ) {
            printf("%d ", n / 100);
            n %= 100;
        } else {
            printf("0 ");
        }
        if ( n >= 50 ) {
            printf("%d ", n / 50);
            n %= 50;
        } else {
            printf("0 ");
        }
        if ( n >= 10 ) {
            printf("%d ", n / 10);
            n %= 10;
        } else {
            printf("0 ");
        }
        if ( n >= 5 ) {
            printf("%d ", n / 5);
            n %= 5;
        } else {
            printf("0 ");
        }
        if ( n >= 1 ) {
            printf("%d\n", n);
        } else {
            printf("0\n");
        }
    }
    return 0;
}