#include <stdio.h>
#include <string.h>

/* The simplified edition of problem "Typesetting" */

void printLine(char token[257][257], int chcnt, int tkcnt, int m)
{
    // there are tkcnt - 1 gaps to fill, tkcnt - 1 could be 0
    // there are m - chcnt spaces to be filled in gaps 
    if ( tkcnt - 1 == 0 ) {
        printf("%s", token[0]);
        int n = m - strlen(token[0]);
        while (n--) {putchar(' ');}
        puts("");
        return;
    } else {
        int base = (m - chcnt) / (tkcnt - 1), ex = (m - chcnt) % (tkcnt - 1);
        for ( int i = 0; i < tkcnt; i++) {
            printf("%s", token[i]);
            if ( i != tkcnt - 1 ) // be careful that there should not be excessive spaces at the tail
                for ( int j = 0; j < base; j++)
                    putchar(' ');
            if ( ex-- > 0 ) 
                putchar(' ');
        }
        puts("");
        return;
    }
}

int main()
{
    int m;
    scanf("%d", &m);
    char token[257][257];
    int chcnt = 0, tkcnt = 0;
    while ( scanf("%s", token[tkcnt]) != EOF ) {
        chcnt += strlen(token[tkcnt]);
        tkcnt++;
        if ( chcnt + tkcnt - 1 > m ) {
            printLine(token, chcnt - strlen(token[tkcnt - 1]), tkcnt - 1, m);
            strcpy(token[0], token[tkcnt - 1]);
            tkcnt = 1;
            chcnt = strlen(token[0]);
        } else if ( chcnt + tkcnt - 1 == m ) {
            for ( int i = 0; i < tkcnt; i++)
                printf("%s%c", token[i], " \n"[i == tkcnt - 1]);
            tkcnt = 0;
            chcnt = 0;
        } else if ( chcnt + tkcnt - 1 < m ) {
            continue;
        }
    }
    if ( chcnt != 0 ) {
        printLine(token, chcnt, tkcnt, m);
    }
    return 0;
}