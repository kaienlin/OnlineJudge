#include <stdio.h>

int main()
{
    unsigned int n, k;
    scanf("%d%d", &n, &k);
    int least = __builtin_popcount(n);
    if ( k < least ) {
        puts("NO");
        return 0;
    }
    int remain = k - least;
    int num[32] = {0};
    for ( int i = 31; i >= 0; i--) {
        if ( n & (1 << i) )
            num[i]++;
        if ( num[i] )
            if ( remain > 0 && i )
                while ( remain > 0 && num[i] > 0 )
                    num[i]--, num[i-1] += 2, remain--;
    }
    if ( remain > 0 ) {
        puts("NO");
        return 0;
    }
    puts("YES");
    int f = 0;
    for ( int i = 0; i < 31; i++) {
        if ( num[i] ) {
            if ( f ) putchar(' ');
            int p = 1 << i;
            while ( num[i]-- ) {
                printf("%d", p);
                if ( num[i] )
                    putchar(' ');
            }
            f = 1;
        }
    }
    return 0;
}