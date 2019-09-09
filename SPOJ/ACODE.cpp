#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

const int MAXN = 5000+5;

LL dp[2][MAXN];
string s;

LL solve() {
    memset(dp, 0, sizeof(dp));
    int n = s.size();
    s = " " + s;
    if ( s[1] != '0' )
        dp[0][1] = 1;
    if ( s[2] != '0' )
        dp[0][2] = dp[0][1];
    int num = (s[2]-'0') + (s[1]-'0') * 10;
    if ( num <= 26 && num >= 10 )
        dp[1][2] = 1;
    for ( int i = 3; i <= n; i++) {
        if ( s[i] != '0' )
            dp[0][i] = dp[0][i-1] + dp[1][i-1];
        int num = (s[i]-'0') + (s[i-1]-'0') * 10;
        if ( num <= 26 && num >= 10 )
            dp[1][i] = dp[0][i-2] + dp[1][i-2];
    }
    return dp[0][n] + dp[1][n];
}

int main()
{
    while ( cin >> s && s != "0" ) {
        cout << solve() << '\n';
    }
    return 0;
}
