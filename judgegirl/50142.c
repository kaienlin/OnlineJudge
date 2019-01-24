#include <stdio.h>
#include <string.h>
#define MAXK 20
#define MAXNAME 32
 
int main()
{
    int k;
    scanf("%d", &k);
    char fname[MAXNAME];
    char str[MAXK][4];
    FILE *fin[MAXK];
    for ( int i = 0; i < k; i++) {
        scanf("%s", fname);
        fin[i] = fopen(fname, "rt");
        fread(str[i], sizeof(char), 3, fin[i]);
        str[i][3] = '\0';
    }
    scanf("%s", fname);
    FILE *fout = fopen(fname, "wt");
    int rest = k;
    while ( rest > 1 ) {
        int min = 0;
        for ( int i = 1; i < k; i++)
            if ( strncmp(str[min], str[i], 3) > 0 )
                min = i;
        fwrite(str[min], sizeof(char), 3, fout);
        if ( fread(str[min], sizeof(char), 3, fin[min]) == 0 ) {
            rest--;
            str[min][0] = str[min][1] = str[min][2] = 127;
        }
    }
    int n;
    char buf[256];
    for ( int i = 0; i < k; i++)
        if ( str[i][0] != 127 ) {
            fwrite(str[i], 1, 3, fout);
            while ( n = fread(buf, 1, 256, fin[i]) )
                fwrite(buf, 1, n, fout);
            break;
        }
    for ( int i = 0; i < k; i++)
        fclose(fin[i]);
    fclose(fout);
    return 0;
}