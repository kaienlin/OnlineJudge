#include <stdio.h>

int fsize(FILE *f) {
    fseek(f, 0, SEEK_END);
    int ret = ftell(f);
    rewind(f);
    return ret;
}
int pos(int idx, int N, int size) {
    int p = size - idx;
    if ( p <= N )
        return size - N + p - 1;
    else
        return p - N - 1;
}
unsigned char mirror(unsigned char c) {
    unsigned char ret = 0;
    for ( int i = 0; i < 8; i++) {
        ret <<= 1;
        ret |= (c & (unsigned char)1);
        c >>= 1;
    }
    return ret;
}
int main()
{
    char fin_name[17], fout_name[17];
    int N;
    scanf("%s %s %d", fin_name, fout_name, &N);
    FILE *fin = fopen(fin_name, "rb");
    FILE *fout = fopen(fout_name, "wb");
    int size = fsize(fin);
    for ( int i = 0; i < size; i++) {
        unsigned char c = fgetc(fin);
        fseek(fout, pos(i, N, size), SEEK_SET);
        unsigned char write = mirror(c);
        fputc(write, fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}