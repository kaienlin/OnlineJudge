#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* The possible cause of RE on judge system but normal on local devices is "the stack size limit of operating system".
   In the beginning, I use a combination[128] to pass the information, but it make program prone to stack overflow, so I
   change to a combination[26] and make some alternation, then it works properly on judge system.

   In conclusion, be careful about passing array in recursion, make the passed array as small as possible.
*/

int convert(char *string, char *combination)
{
    char s[64];
    strcpy(s, string);
    for ( int i = 0; s[i] != '\0'; i++)
        if ( s[i] >= 'A' && s[i] <= 'Z' )
            s[i] = combination[s[i] - 'A'];
    return atoi(s);
}

void half_convert(char *s, char *combo)
{
    for ( int i = 0; s[i] != '\0'; i++)
        if ( s[i] >= 'A' && s[i] <= 'Z' )
            s[i] = combo[s[i] - 'A'];
}

void solve(char *c, int count, char *s1, char *s2, char *s, char *combination, int index)
{
    int a = convert(s1, combination), b = convert(s2, combination), p = convert(s, combination);
    if ( a * b == p ) {
        half_convert(s1, combination);
        half_convert(s2, combination);
        half_convert(s, combination);
        printf("%s x %s = %s\n", s1, s2, s);
        exit(0);
    } else {
        if ( index >= count ) {return;}
        for ( int i = '0'; i <= '9'; i++) {
            char new_com[128];
            strcpy(new_com, combination);
            new_com[c[index] - 'A'] = i;
            solve(c, count, s1, s2, s, new_com, index + 1);
        }
    }
}

int main()
{
    char s1[8], s2[8], s[16];
    scanf("%s%s%s", s1, s2, s);
    char c[64];
    int table[128] = {0};
    for ( int i = 0; s1[i] != '\0'; i++) {table[s1[i]] = 1;}
    for ( int i = 0; s2[i] != '\0'; i++) {table[s2[i]] = 1;}
    for ( int i = 0; s[i] != '\0'; i++) {table[s[i]] = 1;}
    int count = 0;
    for ( int i = 'A'; i <= 'Z'; i++)
        if ( table[i] )
            c[count++] = i;

    char combination[26];
    memset(combination, '0', sizeof(combination));
    solve(c, count, s1, s2, s, combination, 0);
    return 0;
}