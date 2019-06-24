#include <bits/stdc++.h>
#define MAXN 15
#define MAXT 225
#define MAXG 3
#define MOD 1000000007

using namespace std;
using LL = int64_t;

constexpr int P = (1<<16) - 1;

int n, T;
int A[MAXN][2];
unsigned dp[MAXT+1][P][MAXG];

LL solve(int t, bitset<MAXN> m, int prev)
{
    if ( t < 0 )
        return 0;
    if ( t == 0 )
        return 1;
    if ( dp[t][m.to_ulong()][prev] != -1 )
        return dp[t][m.to_ulong()][prev];
    LL ans = 0;
    for ( int i = 0; i < n; i++) {
        if ( !m[i] && A[i][1] != prev ) {
            bitset<MAXN> x(m);
            x[i] = 1;
            ans = (ans + solve(t - A[i][0], x, A[i][1])) % MOD;
        }
    }
    return dp[t][m.to_ulong()][prev] = ans;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> T;
    for ( int i = 0; i < n; i++) {
        cin >> A[i][0] >> A[i][1];
        --A[i][1];
    }
    cout << solve(T, bitset<MAXN>(0), -1) << '\n';
}
