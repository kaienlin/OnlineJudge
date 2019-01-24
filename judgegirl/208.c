#include <stdio.h>

int main()
{
    int w, l;
    scanf("%d%d", &w, &l);
    char one[2], zero[2];
    scanf("%s%s", one, zero);
    unsigned int bits[w * l / 32 + 1];
    for ( int i = 0; i < w * l / 32 + 1; i++) {
        scanf("%d", &bits[i]);
    }
    int c = 0;
    int n = 0;
    int mask = 1 << 31;
    for ( int i = 0; i < w * l; i++) {
        if ( (bits[c] << n) & mask) {
            putchar(one[0]);
        } else {
            putchar(zero[0]);
        }
        if ( (i + 1) % w == 0 ) {
            putchar('\n');
        }
        if ( n == 31 ) {
            n = 0;
            c++;
            continue;
        }
        n++;
    }
    return 0;
}