#include <stdio.h>
#include <string.h>

int rec(int p[], int n)
{
    int cnt_0 = 0, dec = 1;;
    for ( int i = 0; i < n; i++) {
        if ( p[i] == 0 )
            cnt_0++;
        if ( p[i] < 0 || (i != n - 1) && p[i] < p[i+1] ) {
            dec = 0;
            break;
        }
    }
    if ( cnt_0 == n )
        return 1;
    if ( !dec )
        return 0;
    int ret = 0;
    for ( int i = 0; i < n; i++) {
        int dup[n];
        memcpy(dup, p, sizeof(dup));
        dup[i]--;
        ret += rec(dup, n);
    }
    return ret;
}

int main()
{
    int T, n;
    int p[1000];
    scanf("%d", &T);
    for ( int i = 1; i <= T; i++) {
        scanf("%d", &n);
        for ( int j = 0; j < n; j++)
            scanf("%d", &p[j]);
        printf("Case %d: %d\n", i, rec(p, n) % 1000000009);
    }
    return 0;
}