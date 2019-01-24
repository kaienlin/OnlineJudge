#include <stdio.h>

int main(void)
{
    int x;
    int count;
    while ( scanf("%d", &x) != EOF ) {
        count = 0;
        for ( int i = 0; i < 32; i++) {
            if ( (x >> i) & 1 ) { count++; }
        }
        printf("%d\n", count);
    }
    return 0;
}