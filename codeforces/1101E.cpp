#include <bits/stdc++.h>
#define ISWAP(x, y) {int t = x; x = y; y = t;}

using namespace std;

int readchar() {
    static int N = 1 << 20;
    static char buf[1 << 20];
    static char *p = buf, *end = buf;
    if ( p == end ) {
        if ( (end = buf + fread(buf, 1, N, stdin)) == buf )
            return EOF;
        p = buf;
    }
    return *p++;
}
int readInt(int *x) {
    char neg, c;
    while ((c = readchar()) < '-' ) { if ( c == EOF ) return 0; }
    neg = c == '-' ? -1 : 1;
    *x = neg == 1 ? c - '0' : 0;
    while ((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + (c - '0');
    *x *= neg;
    return 1;
}
int readStr(char *s) {
    while ((*s = readchar()) < '!' ) { if ( *s == EOF ) return 0; }
    s++;
    while ((*s = readchar()) >= '!' )
        s++;
    *s = '\0';
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int maxl = 0, maxw = 0;
    while (n--) {
        char t[2];
        int l, w;
        readStr(t); readInt(&l); readInt(&w);
        if ( l < w )
            ISWAP(l, w); // assert that l >= w
        if ( t[0] == '+' ) {
            maxl = l > maxl ? l : maxl;
            maxw = w > maxw ? w : maxw;
        } else {
            if ( l >= maxl && w >= maxw )
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}