#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char s[100];
    scanf("%s", &s);

    int letter[26] = {0};
    for ( int i = 0; s[i] != '\0'; i++) {
        if ( isalpha(s[i]) ) {
            letter[tolower(s[i]) - 'a']++;
        }
    }
    for ( int i = 0; i < 26; i++) {
        printf("%d\n", letter[i]);
    }
    return 0;
}