#include <stdio.h>
#include <string.h>
#define MAXLEN 100000

char ans1[MAXLEN], ans2[MAXLEN], in[MAXLEN];

int main()
{
    int swi = 0;
    scanf("%s", ans1);
    char *sa, *sb, *si, *out;
    while ( ~scanf("%s", in) ) {
        sa = out = swi ? ans1 : ans2, sb = swi ? ans2 : ans1, si = in;
        while ( *sb != '\0' && *si != '\0' )
            if ( strncmp(sb, si, 3) <= 0 ) {
                memcpy(sa, sb, 3);
                sb += 3;
                sa += 3;
            } else {
                memcpy(sa, si, 3);
                si += 3;
                sa += 3;
            }
        strcpy(sa, *sb == '\0' ? si : sb);
        puts(out);
        swi = !swi;
    }
}