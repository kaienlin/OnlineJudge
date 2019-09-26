#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

const int MAXN = 12, MAXK = 98;

LL dp[MAXN][MAXK];

void solve() {
    dp[1][0] = 1;
    for ( int n = 2; n <= MAXN; n++) {
        for ( int k = 0; k <= MAXK; k++) {
            int v = 0;
            for ( int j = 0; j <= n-1 && j <= k; j++)
                v += dp[n-1][k-j];
            dp[n][k] = v;
        }
    }
}

int main()
{
    IOS;
    solve();
    int d; cin >> d;
    while ( d-- ) {
        int n, k; cin >> n >> k;
        cout << dp[n][k] << '\n';
    }
    return 0;
}
