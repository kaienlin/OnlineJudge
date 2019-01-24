#include <stdio.h>
#include <string.h>

int main()
{
    char s[1024];
    scanf("%s", s);
    char cmd[1024];
    while ( scanf("%s", cmd) != EOF ) {
        if ( cmd[0] == 'p' ) {
            printf("%s\n", s);
        } else {
            char delimi[2] = {cmd[1], '\0'};
            char *tok = strtok(cmd + 2, delimi);
            char a[512], b[512];
            strcpy(a, tok);
            tok = strtok(NULL, delimi);
            strcpy(b, tok);
            char *seek = strstr(s, a);
            if ( seek == NULL) {continue;}
            char tmp[1024];
            strcpy(tmp, seek + strlen(a));
            strcpy(seek, b);
            strcat(seek, tmp);
        }
    }
    return 0;
}