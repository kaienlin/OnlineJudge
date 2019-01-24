#include <stdio.h>
#include <ctype.h>

/* In this case, strlen() appears to behave unexpectedly, the reason still not found. */

int main()
{
    char s[101];
    char c;
    int next;
    int set = 1;

    while ( set ) {
        next = 0;
        while ( (c = getchar()) != '\n' ) {
            if ( c == EOF ) {
                set = 0;
                break;
            }
            if ( !isspace(c) ) {
                s[next] = c;
                next++;
            } else if ( isspace(c) && next > 0 ) {
                s[next] = c;
                next++;
            } else {
                continue;
            }
        }
        s[next] = '\0';
        if ( !set ) {
            break;
        }
        for ( int i = next - 1; i >= 0; i--) {
            if ( isspace(s[i]) ) {
                s[i] = '\0';
            } else {
                break;
            }
        }
        for ( int i = 0; s[i] != '\0'; i++) {
            putchar(s[i]);
        }
        putchar('\n');
    }
    return 0;
}