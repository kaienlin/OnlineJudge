#include <stdio.h>
#include <ctype.h>

int main()
{
    int digit = 0;
    int letter = 0;
    int vowel = 0;
    int consonant = 0;
    char c;

    while ( (c = getchar()) != EOF) {
        if ( isdigit(c) )
            digit++;
        else if ( isalpha(c) ) {
            letter++;
            // uppercase should be considered!
            if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'O')
                vowel++;
            else
                consonant++;
        }
    }
    printf("%d %d %d %d", digit, letter, vowel, consonant);
    return 0;
}