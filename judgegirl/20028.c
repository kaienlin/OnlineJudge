#include <stdio.h>
#include <string.h>
#define MAXN 10000

int readchar() {
    static int N = 1 << 20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if ( p == end ) {
        if ( (end = buf + fread(buf, 1, N, stdin)) == buf )
            return EOF;
        p = buf;
    }
    return *p++;
}
int readInt(int *x) {
    int c, neg;
    while ( (c = readchar()) < '-' ) { if (~c) return 0; }
    neg = c == '-' ? -1 : 1;
    *x = neg == 1 ? c-'0' : 0;
    while ( (c = readchar()) >= '0' )
        *x = (*x << 3) + (*x << 1) + c-'0';
    return 1;
}

int d[MAXN], cnt[MAXN];

int main()
{
    int n, k, ans;
    while ( readInt(&n) && readInt(&k) ) {
        memset(cnt, 0, sizeof(cnt));
        ans = 0;
        for ( int i = 0; i < n; i++) {
            readInt(&d[i]);
            if ( d[i] % 2 ) {
                for ( int j = i; j >= 0; j--) {
                    cnt[j]++;
                    if ( cnt[j] > k ) {
                        ans += i - j;
                        for ( int x = j - 1; d[x] % 2 == 0 && x >= 0; x--)
                            ans += i - x;
                        break;
                    }
                }
            }
        }
        for ( int i = n - 1; i >= 0 && cnt[i] <= k; i--) {
            ans += n - i;
        }
        printf("%d\n", ans);
    }
    return 0;
}