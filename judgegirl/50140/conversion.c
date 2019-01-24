#include <stdio.h>

void bin2ascii(char input_file[32], char output_file[32], char dict[17]) {
    FILE *fin = fopen(input_file, "rb");
    FILE *fout = fopen(output_file, "wt");
    unsigned char byte;
    while ( fread(&byte, 1, 1, fin) ) {
        fputc(dict[ (byte & 0xF0) >> 4 ], fout);
        fputc(dict[ byte & 0x0F ], fout);
    }
    fclose(fin);
    fclose(fout);
}
void ascii2bin(char input_file[32], char output_file[32], char dict[17]) {
    FILE *fin = fopen(input_file, "r");
    FILE *fout = fopen(output_file, "wb");
    unsigned int table[256] = {'\0'};
    for ( int i = 0; i < 16; i++)
        table[dict[i]] = i;
    char c[2];
    unsigned char write = 0;
    while ( fread(c, sizeof(char), 2, fin) ) {
        write += (unsigned char)table[c[0]];
        write <<= 4;
        write += (unsigned char)table[c[1]];
        fwrite(&write, sizeof(char), 1, fout);
        write = 0;
    }
    fclose(fin);
    fclose(fout);
}