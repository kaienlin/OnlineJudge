#include <bits/stdc++.h>
#define MAXN 200

using namespace std;

int paper[MAXN];
int dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while ( T-- ) {
        int N, M; cin >> N >> M;
        for ( int i = 0; i < N; i++) {
            cin >> paper[i];
            dp[i][i] = 1;
        }
        for ( int l = N - 1; l >= 0; l--) {
            for ( int r = l + 1; r < N; r++) {
                dp[l][r] = INT_MAX;
                for ( int k = l; k + 1 <= r; k++)
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
                dp[l][r] -= (paper[l] == paper[r]);
            }
        }
        cout << dp[0][N-1] << '\n';
    }
}
