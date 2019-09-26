#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

const int MAXN = 2005;

int n, m;
string N, M;
int val[27];
int dp[MAXN][MAXN];

int solve() {
    N = " " + N; M = " " + M;
    for ( int i = 1; i <= n; i++) {
        for ( int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if ( N[i] == M[j] )
                dp[i][j] = max(dp[i-1][j-1] + val[N[i]-'a'], dp[i][j]);
        }
    }
    return dp[n][m];
}

int main()
{
    IOS;
    cin >> n >> m;
    for ( int i = 0; i < 26; i++)
        cin >> val[i];
    cin >> N >> M;
    cout << solve() << '\n';
    return 0;
}
