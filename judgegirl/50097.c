#include <string.h>
/* 
    1. I did not realize that when doing "T_big shift", I should copy belt[0] ~ belt[T_big - 1] to buffer so that I can 
      copy it back to tail of belt afterwards.
    2. Be careful about how to deal with signed bits operation.
*/
void transmission(long long int belt[],int N,int T)
{
    if ( T == 0 ) {return;}
    int T_small = T % 64;
    int T_big = T / 64 % N;
    static long long buffer[1048576];
    memcpy(buffer, belt, sizeof(long long) * T_big);
    memmove(&belt[0], &belt[T_big], sizeof(long long) * (N - T_big));
    memcpy(&belt[N - T_big], buffer, sizeof(long long) * T_big);
    while (T_small--) {
        unsigned long long msb = (belt[0] & 0x8000000000000000) >> 63, tmp;
        for ( int i = N - 1; i >= 0; i--) {
            tmp = (belt[i] & 0x8000000000000000) >> 63;
            belt[i] <<= 1;
            belt[i] |= msb;
            msb = tmp;
        }
    }
}
