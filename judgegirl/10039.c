#include <stdio.h>
#define MAXS 100000

int main()
{
    char table[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char s[MAXS], from, to;
    int N;
    scanf("%s%d\n", s, &N);
    while (N--) {
        scanf("%c %c\n", &to, &from);
        for ( int i = 0; i < 26; i++)
            if ( table[i] == from )
                table[i] = to;
    }
    char *sptr = s;
    while (*sptr) {
        putchar(table[*sptr++ - 'A']);
    }
    return 0;
}