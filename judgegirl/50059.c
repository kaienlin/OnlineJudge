#include <stdio.h>

int main()
{
    char s[33];
    scanf("%s", s);
    int N;
    scanf("%d", &N);
    unsigned int data[20000];
    for ( int i = 0; i < N; i++)
        scanf("%u", &data[i]);
    int times = N * 32 / 5, decode, cur_d = 0, cur_bit = 0;
    for ( int i = 0; i < times; i++) {
        decode = 0;
        for ( int j = 4; j >= 0; j--) {
            if ( cur_bit == 32 ) {
                cur_d++;
                cur_bit = 0;
            }
            if ( data[cur_d] & 0x80000000 )
                decode += 1 << j;
            data[cur_d] <<= 1;
            cur_bit++;
        }
        putchar(s[decode]);
    }
    return 0;
}