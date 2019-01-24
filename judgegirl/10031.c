#include <stdint.h>
#include <stdio.h>

uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t m)
{
   uint64_t d = 0, mp2 = m >> 1;
   if (a >= m) a %= m;
   if (b >= m) b %= m;
   for (int i = 0; i < 64; ++i)
   {
       d = (d > mp2) ? (d << 1) - m : d << 1;
       if (a & 0x8000000000000000ULL)
           d += b;
       if (d >= m) d -= m;
       a <<= 1;
   }
   return d;
}

int main()
{
    uint64_t a, b, n;
    while ( scanf("%llu%llu%llu", &a, &b, &n) != EOF )
        printf("%llu\n", mul_mod(a, b, n));
    return 0;
}