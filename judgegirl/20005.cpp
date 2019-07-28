#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define MAXN 1024
#define MAXW 5000000
 
using namespace std;
 
int p[MAXN], w[MAXN];
unsigned dp[MAXW + 1];
 
unsigned knapsack(unsigned W, unsigned N)
{
    memset(dp, 0, sizeof(dp));
    for ( int i = 0; i < N; i++)
        for ( int j = W; j - w[i] >= 0; j--)
            dp[j] = max(dp[j], dp[ j - w[i] ] + p[i]);
    return dp[W];
}
 
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    unsigned M, N;
    while ( cin >> M >> N ) {
        for ( int i = 0; i < N; i++)
            cin >> p[i] >> w[i];
        cout << knapsack(M, N) << endl;
    }
}
