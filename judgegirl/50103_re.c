#include <stdio.h>
#define MAXM 1024

typedef unsigned char UC;

UC mirror(UC c) {
    UC ret = 0, mask = 1;
    for ( int i = 0; i < 8; i++) {
        ret <<= 1;
        ret |= c & 1;
        c >>= 1;
    }
    c = ret;
    return c;
}
long fsize(FILE *f) {
    fseek(f, 0, SEEK_END);
    return ftell(f);
}
void shift_mirror(FILE *fin, FILE *fout, int N) {
    int fs = fsize(fin);
    int idx = fs - N - 1;
    while ( !fseek(fin, idx, SEEK_SET) ) {
        UC r = fgetc(fin);
        fputc(mirror(r), fout);
        idx--;
    }
    idx = fs - 1;
    int end = fs - N - 1;
    while ( idx != end ) {
        fseek(fin, idx, SEEK_SET);
        UC r = fgetc(fin);
        fputc(mirror(r), fout);
        idx--;
    }
}

int main()
{
    char in[17], out[17];
    int N;
    scanf("%s%s%d", in, out, &N);
    FILE *fin = fopen(in, "rb"), *fout = fopen(out, "wb");
    shift_mirror(fin, fout, N);
    fclose(fin);
    fclose(fout);
    return 0;
}