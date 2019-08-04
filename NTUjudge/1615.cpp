#include <bits/stdc++.h>

// my stupid code:
//     1. forget to handle leaves in function dfs_1
//     2. confused with i and Pi ( line 59 )

using namespace std;

constexpr int MaxN = 1000000;

vector<int> G[MaxN];
int dep[MaxN];
int max_dep[MaxN];
int len[MaxN];
vector<int> leaves;

void dfs_1(int v)
{
    if ( G[v].size() == 0 ) {
        max_dep[v] = dep[v];
        return;
    }
    int mx = -1;
    for ( int ch : G[v] ) {
        dfs_1(ch);
        mx = max(mx, max_dep[ch]);
    }
    max_dep[v] = mx;
}

void dfs_2(int v)
{
    if ( G[v].size() == 0 ) {
        leaves.push_back(len[v]);
        return;
    }
    int longest = G[v][0];
    for ( int ch : G[v] ) {
        if ( max_dep[ch] > max_dep[longest] )
            longest = ch;
        len[ch] = 1;
    }
    len[longest] += len[v];  // equal to len[v] + 1
    for ( int ch : G[v] )
        dfs_2(ch);
}

bool cmp(int a, int b) { return a > b; }

int main()
{
    int T; scanf("%d", &T);
    while ( T-- ) {
        int N, K; scanf("%d %d", &N, &K);
        dep[0] = 0;
        for ( int i = 1; i <= N-1; i++) {
            int Pi; scanf("%d", &Pi);
            G[Pi].push_back(i);
            dep[i] = dep[Pi] + 1;
        }

        dfs_1(0);
        len[0] = 0;
        dfs_2(0);
        sort(leaves.begin(), leaves.end(), cmp);

        int ans = 0;
        if ( leaves.size() <= K ) {
            ans = N - 1;
        } else {
            for ( int i = 0; i < K; i++)
                ans += leaves[i];
        }

        printf("%d\n", ans);

        for ( int i = 0; i < N; i++) G[i].clear();
        leaves.clear();
    }
}
