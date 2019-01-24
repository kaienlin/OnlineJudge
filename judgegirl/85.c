#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000000

int readchar() {
    static int N = 1<<22;
    static char buf[1<<22];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf)
            return EOF;
        p = buf;
    }
    return *p++;
}
int ReadUint(unsigned *x) {
    char c;
    while((c = readchar()) < '0')    {if(c == EOF) return 0;}
    *x = c - '0';
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    return 1;
}

int cmp(const void *a, const void *b) {
    return (*(unsigned*)a > *(unsigned*)b) - (*(unsigned*)a < *(unsigned*)b);
}

unsigned date[MAXN]; // global variables has more available memory than main()
 
int main(void)
{
    int n;
    ReadUint(&n);
    unsigned x;
    for ( int i = 0; i < n; i++) {
        ReadUint(&date[i]);
        date[i] <<= 4;
        ReadUint(&x);
        date[i] |= x;
        date[i] <<= 5;
        ReadUint(&x);
        date[i] |= x;
    }
    qsort(date, n, sizeof(unsigned), cmp);
    for ( int i = 0; i < n; i++)
        printf("%u %u %u\n", date[i] >> 9, (date[i] >> 5) & 0x0000000F, date[i] & 0x0000001F );
    return 0;
}
