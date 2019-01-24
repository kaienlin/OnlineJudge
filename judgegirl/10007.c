#include <stdio.h>

int main(void)
{
    int n;
    int i, num, prev, seg;
    while ( scanf("%d", &n) != EOF) {
        seg = 1;
        for ( i = 1; i <= n; i++) {
            scanf("%d", &num);
            if ( i != 1 && num != prev ) {
                seg++;
            }
            prev = num;
        }
        printf("%d\n", seg);
    }
}
