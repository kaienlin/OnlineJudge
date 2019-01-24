#include <stdio.h>
 
typedef unsigned long long ULL;
 
int hamming(ULL code, int index, unsigned char c)
{
    return __builtin_popcountll(((code >> ((7 - index) * 8)) & 0x00000000000000FF) ^ c);
}
 
unsigned char extract(ULL code, int index)
{
    unsigned char ret = 0;
    ret |= (code >> (7 - index) * 8) & 0x00000000000000FF;
    return ret;
}
 
int main()
{
    int N, M, P;
    scanf("%d%d%d", &N, &M, &P);
    ULL valid[3] = {0};
    for ( int i = 0; i < M; i++) {
        scanf("%llu", &valid[i]);
    }
    unsigned char text;
    for ( int i = 0; i < P; i++) {
        scanf("%hhu", &text);
        for ( int i = 0; i < N; i++) {
            int hd = hamming(valid[i / 8], i % 8, text);
            if ( hd == 0 ) {
                printf("%hhu\n", text);
                break;
            } else if ( hd == 1 ) {
                printf("%hhu\n", extract(valid[i / 8], i % 8));
                break;
            }
        }
    }
    return 0;
}