#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

constexpr int MAXN = 200000;
constexpr int INF = 1e9;

int n, m;
vector< vector<int> > adj;
vector<int> dist(MAXN+5);

void bfs(int src)
{
    fill(dist.begin(), dist.begin() + n + 1, INF);
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while ( !q.empty() ) {
        int v = q.front(); q.pop();
        for ( auto to : adj[v] ) {
            if ( dist[to] == INF ) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin >> t;
    while ( t-- ) {
        cin >> n >> m;
        adj = vector< vector<int> >(n+1);
        for ( int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        bfs(1);
        vector<int> even, odd;
        for ( int i = 1; i <= n; i++) {
            if ( dist[i] & 1 )
                odd.pb(i);
            else
                even.pb(i);
        }
        if ( even.size() < odd.size() ) {
            cout << even.size() << '\n';
            for ( auto e : even )
                cout << e << " ";
        } else {
            cout << odd.size() << '\n';
            for ( auto e : odd )
                cout << e << " ";
        }
        cout << '\n';
    }
}
