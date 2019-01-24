#include <stdio.h>
#include <string.h>

int main()
{
    char word[32];
    char *de = "aeiou";
    int cnt = 0;
    char prev = 'z';
    while (scanf("%s", word) != EOF) {
        char *s = strtok(word, de);
        while (s != NULL) {
            for ( int i = 0; s[i] != '\0'; i++) {
                if ( s[i] > prev )
                    cnt++;
                prev = s[i];
            }
            s = strtok(NULL, de);
        }
    }
    printf("%d\n", cnt);
    return 0;
}