#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 38+5;

bool mark[MAXN];
int dp[MAXN][MAXN];

int solve(int L, int R) {
    if ( dp[L][R] != -1 )
        return dp[L][R];
    if ( L > R )  // empty range
        return 1;
    if ( mark[R] )  // if index R should be open bracket, [L, R] is not balanced
        return 0;
    int ret = 0;
    // enumerate the position of the closing bracket of the open bracket at L
    for ( int m = L+1; m <= R; m++)
        if ( !mark[m] && (m-1 == L || !mark[m-1]) )
            ret += solve(L+1, m-1) * solve(m+1, R);
    return dp[L][R] = ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while ( T-- ) {
        int n, k; cin >> n >> k;
        memset(mark, 0, sizeof(mark));
        for ( int i = 0; i < k; i++) {
            int x; cin >> x;
            mark[x] = true;
        }
        memset(dp, -1, sizeof(dp));
        cout << solve(1, 2*n) << '\n';
    }
}
