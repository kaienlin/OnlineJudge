#include <bits/stdc++.h>
#define MAXN 200000
#define NINF -999999999999999LL

using namespace std;
using LL = long long;

int n;
vector<int> adj[MAXN+1];
LL val[MAXN+1];
bool visited[MAXN+1];

struct R {
    LL tot, one, two;
};

R dfs(int u) {
    LL tot = val[u], one = NINF, two = NINF;
    visited[u] = true;
    LL mx = NINF, mx2 = NINF;  // max 2 values for one
    for ( int e : adj[u] ) {
        if ( !visited[e] ) {
            R ret = dfs(e);
            tot += ret.tot;
            one = max(one, ret.one);
            two = max(two, ret.two);
            if ( ret.one > mx )
                swap(ret.one, mx);
            if ( ret.one > mx2 )
                mx2 = ret.one;
        }
    }
    if ( !(mx == NINF || mx2 == NINF) )  // if there are at least 2 "one" != NINF
        two = max(two, mx + mx2);
    one = max(one, tot);
    return {tot, one, two};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for ( int i = 1; i <= n; i++)
        cin >> val[i];
    for ( int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LL ans = dfs(1).two;
    if ( ans == NINF )
        cout << "Impossible" << '\n';
    else
        cout << ans << '\n';
}
