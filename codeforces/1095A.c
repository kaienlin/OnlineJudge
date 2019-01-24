#include <stdio.h>

int main()
{
    int n;
    char str[64];
    scanf("%d%s", &n, str);
    char *s = str;
    for ( int i = 1; *s; i++) {
        putchar(*s);
        s += i;
    }
    return 0;
}