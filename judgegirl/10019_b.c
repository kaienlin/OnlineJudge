#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[128];
    memset(s, 0, sizeof(s));
    while ( fgets(s, 128, stdin) != NULL ) {
        char *sptr = s;
        while ( *sptr != '\0' ) {
            if ( isspace(*sptr) ) {
                sptr++;
            } else {
                break;
            }
        }
        char *p = &s[127];
        while ( !isgraph(*p) ) {
            *p = '\0';
            p--;
        }
        printf("%s\n", sptr);
        memset(s, 0, sizeof(s));
    }
    return 0;
}