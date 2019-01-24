#include <stdio.h>

/* a b c
     a b c
   a - - c*/

int main(void)
{
    int digit, prev;
    int zeros = 0;
    int even = 0;
    int eleven = 0;
    int count = 0;
    int x = 0;
    
    while ( scanf("%d", &digit) != EOF ) {
        if ( digit == 0 ) {
            zeros++;
        }
        prev = digit;
        count++;
        if ( count % 2 == 0 ) {
            x -= digit;
        } else {
            x += digit;
        }
    }
    if ( prev % 2 == 0 ) {
        even = 1;
    }
    if ( x % 11 == 0 ) {
        eleven = 1;
    }
    
    printf("%d\n%d\n%d\n%d", count, even, zeros, eleven);
    return 0;
}
