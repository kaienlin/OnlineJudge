#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char word[128];
    char *ignore[4] = {"of", "and", "the", "at"};
    int isvalid;
    while ( scanf("%s", word) != EOF ) {
        int len = strlen(word);
        if ( word[len - 1] == '.' ) {
            word[len-1] = '\0';
            isvalid = 1;
            for ( int i = 0; i < 4; i++)
                if ( strcmp(word, ignore[i]) == 0 )
                    isvalid = 0;
            if ( isvalid )
                putchar(toupper(word[0]));
            putchar('\n'); // NOTICE! ignored word can be last word of a sentence! So don't put newline and character together.
        } else {
            isvalid = 1;
            for ( int i = 0; i < 4; i++)
                if ( strcmp(word, ignore[i]) == 0 )
                    isvalid = 0;
            if ( isvalid )
                putchar(toupper(word[0]));
        }
    }
    return 0;
}