#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* NOTE! isblank() don't include '\n' !!! */

int main()
{
    char *ignore[4] = {"the", "at", "of", "and"};
    char s[127];
    char abbr[127];
    char c;
    int len = 0;
    int count = 0;
    int flag;
    while ( (c = getchar()) != EOF ) {
        if ( isalpha(c) ) {
            s[len] = c;
            len++;
        } else if ( isspace(c) && len > 0 ) {
            s[len] = '\0';
            len = 0;
            flag = 1;
            for ( int i = 0; i < 4; i++) {
                if ( strcmp(s, ignore[i]) == 0 ) {
                    flag = 0;
                    break;
                }
            }
            if ( flag ) {
                abbr[count] = toupper(s[0]);
                count++;
            }
        } else if ( c == '.' ) {
            s[len] = '\0';
            len = 0;
            flag = 1;
            for ( int i = 0; i < 4; i++) {
                if ( strcmp(s, ignore[i]) == 0 ) {
                    flag = 0;
                    break;
                }
            }
            if ( flag ) {
                abbr[count] = toupper(s[0]);
                count++;
            }
            abbr[count] = '\0';
            printf("%s\n", abbr);
            count = 0;
        }
    }
    return 0;
}