#include <stdio.h>

void cmd_0(FILE *fin) {
    int toprint;
    fread(&toprint, 4, 1, fin);
    printf("%d", toprint);
}
void cmd_1(FILE *fin) {
    char toprint[5];
    fread(toprint, 1, 4, fin);
    toprint[4] = '\0';
    printf("%s", toprint);
}
void cmd_2(FILE *fin) {
    int buf;
    fread(&buf, 4, 1, fin);
    char c;
    fread(&c, 1, 1, fin);
    while (c) {
        putchar(c);
        fread(&c, 1, 1, fin);
    }
}
void cmd_3(FILE *fin) {
    int offset;
    fread(&offset, 4, 1, fin);
    fseek(fin, -8, SEEK_CUR);
    fseek(fin, offset, SEEK_CUR);
}
void cmd_4(FILE *fin) {
    int offset;
    fread(&offset, 4, 1, fin);
    fseek(fin, offset, SEEK_SET);
}
void cmd_5(FILE *fin) {
    int offset;
    fread(&offset, 4, 1, fin);
    fseek(fin, offset, SEEK_END);
}
int main()
{
    char filename[16];
    scanf("%s", filename);
    FILE *fin = fopen(filename, "rb");
    int type;
    while ( !feof(fin) ) {
        fread(&type, 4, 1, fin);
        switch (type) {
            case 0:
                cmd_0(fin);
                break;
            case 1:
                cmd_1(fin);
                break;
            case 2:
                cmd_2(fin);
                break;
            case 3:
                cmd_3(fin);
                break;
            case 4:
                cmd_4(fin);
                break;
            case 5:
                cmd_5(fin);
                break;
            default:
                printf("Seek end");
                return 0;
        }
    }
    return 0;
}