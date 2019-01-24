#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int a[n][n];
    int i, count = 0;
    int odd, even = 0;

    for ( i = 0; i < n; i++) {
        scanf("%d", &a[i][0]);
        a[i][1] = 0;
    }

    for ( i = 0; i < n; i++) {
        if ( a[i][0] % 2 == 0 ) {
            a[i][1] = 1;
            even++;
        }
    }

    odd = n - even;

    for ( i = 0; i < n; i++) {
        if ( !a[i][1] ) {
            printf("%d", a[i][0]);
            count++;
            if ( count < odd ) {
                printf(" ");
            }
        }
    }

    printf("\n");

    count = 0;

    for ( i = 0; i < n; i++) {
        if ( a[i][1] ) {
            printf("%d", a[i][0]);
            count++;
            if ( count < even ) {
                printf(" ");
            }
        } 
    }

    return 0;
}
