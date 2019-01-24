#include <stdio.h>
#define MAXN 1000001

int pref[MAXN], suf[MAXN];
int okp[MAXN], oks[MAXN];

int main()
{
    int n;
    char str[MAXN], re[MAXN];
    scanf("%d%s", &n, str);
    for ( int i = 0; i < n; i++)
        re[n-i-1] = str[i] == '(' ? ')' : '(';
    okp[0] = oks[n] = 1;
    for ( int i = 0; i < n; i++) {
        pref[i+1] = pref[i] + (str[i] == '(' ? 1 : -1);
        okp[i+1] = okp[i] && (pref[i+1] >= 0);
        suf[n-i-1] = suf[n-i] + (re[i] == '(' ? 1 : -1);
        oks[n-i-1] = oks[n-i] && (suf[n-i-1] >= 0);
    }
    int ans = 0;
    for ( int i = 0; i < n; i++) {
        if ( !okp[i] || !oks[i+1] )
            continue;
        if ( str[i] == '(' ) {
            if ( pref[i] > 0 && pref[i] - 1 - suf[i+1] == 0 )
                ans++;
        } else
            if ( pref[i] + 1 - suf[i+1] == 0 )
                ans++;
    }
    printf("%d\n", ans);
    return 0;
}