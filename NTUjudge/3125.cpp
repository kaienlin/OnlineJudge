#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using pii = pair<LL, LL>;

const int MAXN = 5005;
const int MAXK = MAXN;
const LL INF = 1e9+43;
const LL mod = 1e9+7;

string V;
LL cost[MAXN];
pii dp[MAXN][MAXK];

int main()
{
    IOS;
    int N, K; cin >> N >> K;
    cin >> V; V = "^" + V;
    for ( int i = 1; i <= N; i++)
        cin >> cost[i];

    dp[0][0] = {0, 1};

    for ( int i = 1; i <= K; i++)
        dp[0][i] = {INF, 1};

    for ( int i = 1; i <= N; i++) {

        for ( int k = 0; k <= K; k++)
            dp[i][k] = {INF, 1};

        if ( V[i] == 'B' ) {
            for ( int k = 1; k <= K; k++)
                dp[i][k] = dp[i-1][k-1];

            dp[i][0].first = (dp[i-1][0].first + cost[i]) % mod;
            dp[i][0].second = dp[i-1][0].second;

            for ( int k = 0; k < K; k++) {
                if ( dp[i-1][k+1].first + cost[i] < dp[i][k].first ) {
                    dp[i][k].first = (dp[i-1][k+1].first + cost[i]) % mod;
                    dp[i][k].second = dp[i-1][k+1].second;
                } else if ( dp[i-1][k+1].first + cost[i] == dp[i][k].first ) {
                    dp[i][k].second = (dp[i][k].second + dp[i-1][k+1].second) % mod;
                }
            }

        } else {
            for ( int k = 0; k < K; k++)
                dp[i][k] = dp[i-1][k+1];

            if ( dp[i-1][0].first < dp[i][0].first )
                dp[i][0] = dp[i-1][0];
            else if ( dp[i-1][0].first == dp[i][0].first )
                dp[i][0].second = (dp[i][0].second + dp[i-1][0].second) % mod;
        }
    }

    pii ans = {INF, 1};
    for ( int k = 0; k <= K; k++) {
        if ( dp[N][k].first < ans.first )
            ans = dp[N][k];
        else if ( dp[N][k].first == ans.first )
            ans.second = ( ans.second + dp[N][k].second ) % mod;
    }
    cout << ans.first << "\n" << ans.second << "\n";
    return 0;
}

