#include <stdio.h>

int da, db, dc;
int ea, eb, ec;
int fa, fb, fc;

int composition(int a, int b, int c)
{
    if ( a < 0 || b < 0 || c < 0 ) {
        return 0;
    } else if ( a == 0 && b == 0 && c == 0 ) {
        return 1;
    } else {
        return composition(a - da, b - db, c - dc) || composition(a - ea, b - eb, c - ec) || composition(a - fa, b - fb, c - fc);
    }
}

void iterate(int n)
{
    if ( n == 0 ) { return; }
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%s\n", composition(a, b, c) ? "yes" : "no");
    iterate(n - 1);
}

int main()
{
    scanf("%d%d%d", &da, &db, &dc);
    scanf("%d%d%d", &ea, &eb, &ec);
    scanf("%d%d%d", &fa, &fb, &fc);
    int n;
    scanf("%d", &n);
    iterate(n);
    return 0;
}