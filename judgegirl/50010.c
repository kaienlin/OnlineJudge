#include <stdio.h>
#include <string.h>
 
int main()
{
    char buffer[200000] = "";
    char *s = &buffer[100000];
    char cmd[32] = "";
    char x[2];
    char y[2];
    char *c;
    char buf[100000];
    scanf("%s", s);
    while ( scanf("%s", cmd) != EOF ) {
        if ( strcmp(cmd, "end") == 0 ) {break;}
        else if ( strcmp(cmd, "replace") == 0 ) {
            scanf("%s%s", x, y);
            c = s;
            while ( *c != '\0' ) {
                if ( *c == x[0] ) {
                    *c = y[0];
                }
                c++;
            }
        } else if ( strcmp(cmd, "remove") == 0 ) {
            scanf("%s", x);
            c = s;
            while ( *c != '\0' ) {
                if ( *c == x[0] ) {
                    int i = 0;
                    while ( c[i] != '\0' ) {
                        c[i] = c[i + 1];
                        i++;
                    }
                    c--; // Without this statement, it will ignore one character
                }
                c++;
            }
        } else if ( strcmp(cmd, "addhead") == 0 ) {
            scanf("%s", x);
            *(s - 1) = x[0];
            s--;
        } else if ( strcmp(cmd, "addtail") == 0 ) {
            scanf("%s", x);
            strcat(s, x);
        } else {
            printf("invalid command %s", cmd);
            return 0; // immediately stop program
        }
    }
    printf("%s", s);
    return 0;
}