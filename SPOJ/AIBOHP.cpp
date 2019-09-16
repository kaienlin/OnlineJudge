#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

const int MAXN = 6100 + 5;

int dp[MAXN][MAXN];
int lcs(string &a, int na, string &b, int nb) {
    memset(dp, 0, sizeof(dp));
    a = "^" + a;
    b = "^" + b;
    for ( int i = 1; i <= na; i++)
        for ( int j = 1; j <= nb; j++) {
            if ( a[i] == b[j] )
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    return dp[na][nb];
}

string a, b;

int main()
{
    IOS;
    int T; cin >> T;
    while ( T-- ) {
        cin >> a;
        b = a; reverse(b.begin(), b.end());
        int n = a.size();
        int v = lcs(a, n, b, n);
        cout << n - v << '\n';
    }
    return 0;
}
