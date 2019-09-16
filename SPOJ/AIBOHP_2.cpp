#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

const int MAXN = 6105;
int dp[MAXN][MAXN];
string s;
int solve(int l, int r) {
    if ( l >= r )
        return 0;
    if ( dp[l][r] != -1 )
        return dp[l][r];
    if ( s[l] == s[r] )
        return dp[l][r] = solve(l+1, r-1);
    else
        return dp[l][r] = (1 + min(solve(l+1, r), solve(l, r-1)));
}

int main()
{
    int T; cin >> T;
    while ( T-- ) {
        cin >> s;
        memset(dp, -1, sizeof(dp));
        cout << solve(0, s.size()-1) << '\n';
    }
    return 0;
}
