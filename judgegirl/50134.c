#include <stdio.h>

int main()
{
    int type;
    char pattern[8];
    unsigned int L;
    unsigned short S;
    char C[4];
    unsigned long long ans = 0;
    scanf("%d", &type);
    if ( !type ) {
        while ( ~scanf("%s", pattern) ) {
            scanf("%u%hu%s", &L, &S, C);
            ans = 0;
            int cnt = 0;
            for ( int i = 0; i < 4; i++) {
                if ( pattern[i] == 'L' ) {
                    ans <<= 32;
                    ans |= L;
                } else if ( pattern[i] == 'S' ) {
                    ans <<= 16;
                    ans |= S;
                } else {
                    ans <<= 8;
                    ans |= C[cnt++];
                }
            }
            printf("%llu\n", ans);
        }
    } else {
        while ( ~scanf("%s", pattern) ) {
            scanf("%llu", &ans);
            int cnt = 1;
            L = 0;
            S = 0;
            C[0] = C[1] = C[2] = 0;
            for ( int i = 3; i >= 0; i--) {
                if ( pattern[i] == 'L' ) {
                    L |= ans;
                    ans >>= 32;
                } else if ( pattern[i] == 'S' ) {
                    S |= ans;
                    ans >>= 16;
                } else {
                    C[cnt--] |= ans;
                    ans >>= 8;
                }
            }
            printf("%u %hu %s\n", L, S, C);
        }
    }
    return 0;
}