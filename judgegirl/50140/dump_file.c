#include <stdio.h>
#include <assert.h>
#define MAXB 65536

int main(int argc, char *argv[])
{
    assert(argc == 2);
    FILE *fin = fopen(argv[1], "rb");
    unsigned char c[MAXB];
    int n;
    while ( n = fread(c, sizeof(unsigned char), MAXB, fin) ) {
        for ( int i = 0; i < n; i++)
            printf("%02x ", c[i]);
    }
    fclose(fin);
    return 0;
}