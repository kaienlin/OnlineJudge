#include <bits/stdc++.h>
#define MAXN 15

using namespace std;

int a[MAXN], n;
bool dp[MAXN][360];

bool brute_force(int idx, int degree) {
    if ( degree >= 360 )
        degree %= 360;
    else if ( degree < 0 )
        degree = 360 + (degree % 360);
    if ( !dp[idx][degree] )
        return false;
    if ( idx == n ) {
        if ( degree == 0 )
            return true;
        else
            return false;
    }
    bool r1 = brute_force(idx + 1, degree + a[idx]);
    bool r2 = brute_force(idx + 1, degree - a[idx]);
    if ( !r1 && !r2 )
        return (dp[idx][degree] = false);
    else
        return true;
}

int main()
{
    scanf("%d", &n);
    for ( int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    memset(dp, 1, sizeof(dp));
    bool result = brute_force(0, 0);
    if ( result )
        puts("YES");
    else
        puts("NO");
    return 0;
}