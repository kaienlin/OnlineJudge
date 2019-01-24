#include "fs.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

Account buf[1024];

int isInvalid(char *str) {
    while ( *str != '\0' ) {
        if ( !isalpha(*str) && (*str != ' ') ) // the problem description says "space"
            return 1;
        str++; // I appears to forget this statement frequently.....
    }
    return 0;
}

int cmp(const void *a, const void *b) {
    Account *x = (Account*)a, *y = (Account*)b;
    return strcmp(x->name, y->name);
}

int main()
{
    char in_name[128], out_name[128];
    scanf("%s%s", in_name, out_name);
    FILE *fin, *fout;
    fin = fopen(in_name, "rb");
    assert(fin != NULL);
    int n, cnt = 0;
    while ( (n = fread(&buf[cnt], sizeof(Account), 1, fin)) != 0 ) {
        if ( buf[cnt].balance < 0 || !(buf[cnt].gender == 1 || buf[cnt].gender == 0) || isInvalid(buf[cnt].name) )
            continue;
        else
            cnt++;
    }
    fclose(fin);
    qsort(buf, cnt, sizeof(Account), cmp);
    fout = fopen(out_name, "wb");
    fwrite(buf, sizeof(Account), cnt, fout);    
    fclose(fout);
    return 0;
}