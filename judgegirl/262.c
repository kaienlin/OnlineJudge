#include <stdio.h>
 
int main()
{
    int x, len, maxlen;
    while ( scanf("%d", &x) != EOF ) {
        maxlen = 0;
        len = 0;
        for ( int i = 0; i < sizeof(x) * 8; i++) {
            if ( (x >> i) & 1 ) {
                len++;
            } else {
                len = 0;
            }
            if ( len > maxlen ) {
                maxlen = len;
            }
        }
        printf("%d\n", maxlen);
    }
 
    return 0;
}