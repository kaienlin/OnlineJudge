#include <stdio.h>
#include <string.h>
#define MAXS 100000
#define MAXLL 12500

int main()
{
    int T;
    scanf("%d", &T);
    char s[MAXS];
    long long d[MAXLL];
    if ( T ) {
        int N;
        scanf("%d", &N);
        memset(s, 0, sizeof(s));
        for ( int i = 0; i < N; i++) {
            scanf("%lld", &d[i]);
            for ( int j = 0; j < 8; j++)
                s[i*8+j] |= d[i] >> 8 * (7 - j);
        }
        puts(s);
    } else {
        scanf("%s", s);
        memset(d, 0, sizeof(d));
        int cnt = 0, bc = 0;
        for ( int i = 0; s[i] != '\0'; i++) {
            d[cnt] |= s[i];
            bc++;
            if ( bc == 8 ) {
                bc = 0;
                cnt++;
            } else {
                d[cnt] <<= 8;
            }
        }
        d[cnt] <<= 8 * (7 - bc);
        for ( int i = 0; i <= cnt; i++)
            printf("%lld\n", d[i]);
    }
    return 0;
}