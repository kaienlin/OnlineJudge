#include <stdio.h>
 
int main()
{
    long long x;
    int count;
    while ( scanf("%lld", &x) != EOF ) {
        count = 0;
        for ( int i = 0; i < sizeof(x) * 8; i++) {
            if ( (x >> i) & 1 ) {
                count++;
            }
        }
        printf("%d\n", count);
    }
 
    return 0;
}