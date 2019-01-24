#include <bits/stdc++.h>
#define MAXN 200001
using namespace std;

int main()
{
    int n, k;
    char s[MAXN];
    scanf("%d%d%s", &n, &k, s);
    int cnt[26] = {0}, x = 0;
    for ( int i = 0; i < n;) {
        int len = 0;
        char c = s[i];
        for (; i < n && s[i] == c; i++, len++);
        cnt[c-'a'] += len / k;
        if ( cnt[c-'a'] > x )
            x = cnt[c-'a'];
    }
    printf("%d\n", x);
    return 0;
}