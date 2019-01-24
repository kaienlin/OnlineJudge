#include <stdio.h>

int filesize(FILE *f) {
    fseek(f, 0, SEEK_END);
    return ftell(f);
}
unsigned char add_byte(unsigned char b1, unsigned char b2, int *carry) {
    int ret = b1 + b2 + *carry;
    *carry = ret > 255 ? 1 : 0;
    return (unsigned char)ret;
}
int main()
{
    char f1[32], f2[32], fo[32];
    scanf("%s%s%s", f1, f2, fo);
    FILE *fin1 = fopen(f1, "rb"), *fin2 = fopen(f2, "rb");
    FILE *fout = fopen(fo, "wb");
    int size1 = filesize(fin1), size2 = filesize(fin2);
    int outsize = size1 > size2 ? size1 : size2;
    fseek(fin1, -1, SEEK_END);
    fseek(fin2, -1, SEEK_END);
    fseek(fout, outsize - 1, SEEK_SET);
    unsigned char byte1, byte2;
    int carry = 0;
    while ( size1 > 0 || size2 > 0 ) {
        if ( size1 > 0 )
            fread(&byte1, 1, 1, fin1);
        else
            byte1 = 0;
        if ( size2 > 0 )
            fread(&byte2, 1, 1, fin2);
        else
            byte2 = 0;
        unsigned char to_write = add_byte(byte1, byte2, &carry);
        fwrite(&to_write, 1, 1, fout);
        fseek(fout, -2, SEEK_CUR);
        size1--;
        size2--;
        fseek(fin1, -2, SEEK_CUR);
        fseek(fin2, -2, SEEK_CUR);
    }
    fclose(fin1);
    fclose(fin2);
    fclose(fout);
    return 0;
}