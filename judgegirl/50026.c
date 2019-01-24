#include <stdio.h>
#include <ctype.h>

int main()
{
    char filename[256];
    scanf("%s", filename);
    FILE *fin = fopen(filename, "r");
    int c;
    int byte = 0, line = 0, word = 0;
    int state = 0, postfix = 0;
    while ( (c = fgetc(fin)) != EOF ) {
        byte++;
        postfix++;
        if ( c == '\n' ) {
            line++;
            postfix = 0;
        }
        if ( state == 0 && isalpha(c) )
            state = 1;
        if ( state == 1 && !isalpha(c) ) {
            state = 0;
            word++;
        }
    }
    if ( state )
        word++;
    if ( postfix > 0 )
        line++;
    printf("%d %d %d", line, word, byte);
    fclose(fin);
    return 0;
}