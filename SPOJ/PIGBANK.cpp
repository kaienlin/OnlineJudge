#include <bits/stdc++.h>

// unbounded knapsack problem

using namespace std;

constexpr int MAXW = 1e4+5, MAXN = 505, INF = 1e9+42342;

int dp[MAXW], val[MAXN], wei[MAXN];

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T; cin >> T;
    while ( T-- ) {
        int E, F; cin >> E >> F;
        F -= E;
        int N; cin >> N;
        for ( int i = 1; i <= N; i++)
            cin >> val[i] >> wei[i];

        fill(dp, dp+F+1, INF);
        dp[0] = 0;
        for ( int w = 1; w <= F; w++)
            for ( int i = 1; i <= N; i++)
                if ( wei[i] <= w )
                    dp[w] = min(dp[w], dp[w - wei[i]] + val[i]);
        if ( dp[F] == INF )
            cout << "This is impossible.\n";
        else
            cout << "The minimum amount of money in the piggy-bank is " << dp[F] << ".\n";
    }
}
