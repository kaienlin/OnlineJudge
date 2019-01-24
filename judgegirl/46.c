#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 1. Carefully deal with converting string to integer, especially multi digits number.
   2. because we need to record all characters which match maxlen, even if len == 1 we should be careful.
*/

int main()
{
    char string[500000];
    char *s = &string[250000];
    char buffer[500000];
    char cmd[3][20];
    while ( scanf("%s", cmd[0]) != EOF ) {
        if ( cmd[0][0] == 'i' ) {
            // insert
            scanf("%s%s", cmd[1], cmd[2]);
            if ( cmd[1][0] == 'l' ) {
                *(s - 1) = cmd[2][0];
                s--;
            } else if ( cmd[1][0] == 'r' ) {
                strcat(s, cmd[2]);
            } else {
                int k = atoi(cmd[1]);
                strcpy(buffer, &s[k-1]);
                s[k-1] = cmd[2][0];
                strcpy(&s[k], buffer);
            }
        } else {
            // delete
            scanf("%s", cmd[1]);
            if ( cmd[1][0] == 'l' ) {
                s++;
            } else if ( cmd[1][0] == 'r' ) {
                s[strlen(s) - 1] = '\0';
            } else {
                int k = atoi(cmd[1]);
                strcpy(buffer, &s[k]);
                strcpy(&s[k-1], buffer); // don't do strcpy(&s[k-1], &s[k]);
            }
        }
    }
    int maxlen = 0;
    int len = 0, prev = s[0], check = 0;
    char ans[100000] = "";
    int count = 0;
    for ( int i = 0; s[i] != '\0'; i++) {
        if ( s[i] == prev ) {
            len++;
            if ( len == maxlen ) {
                ans[count] = s[i];
                count++;
            } else if ( len > maxlen ) {
                memset(ans, 0, sizeof(ans));
                ans[0] = s[i];
                count = 1;
                maxlen = len;
            }
        } else {
            len = 1;
            if ( maxlen == 1 ) { // maxlen may == 1 !!!
                ans[count] = s[i];
                count++;
            }
            prev = s[i];
        }
    }
    for ( int i = 0; ans[i] != '\0'; i++) {
        printf("%c ", ans[i]);
    }
    printf("%d", maxlen);
    return 0;
}