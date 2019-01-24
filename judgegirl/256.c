#include <stdio.h>
#include <stdlib.h>

// Things to remember: the return type of compare function is int but the number we compare is
// long long, so I cannot simply return the difference of the two long long integers
 
int cmp(const void *a, const void *b)
{
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    int x1 = 0, y1 = 0;
    long long mask = 1;
    for ( int i = 0; i < 64; i++) {
        if ( (x >> i) & mask ) {
            x1++;
        }
        if ( (y >> i) & mask ) {
            y1++;
        }
    }
    if ( x1 == y1 ) {
        if ( x == y ) {
            return 0;
        } else if ( x > y ) {
            return 1;
        } else {
            return -1;
        }
    } else {
        if ( x1 > y1 ) {
            return 1;
        } else {
            return -1;
        }
    }
}
 
int main()
{
    long long num[1000];
    int i;
    for ( i = 0; scanf("%lld", &num[i]) != EOF; i++) {
        ;
    }
    qsort(num, i, sizeof(long long), cmp);
    for ( int j = 0; j < i; j++) {
        printf("%lld", num[j]);
        if ( j != i - 1 ) {
            putchar('\n');
        }
    }
    return 0;
}