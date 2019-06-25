#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

constexpr int MAXN = 200000;
using pii = pair<int, int>;

vector<int> adj[MAXN+5];
pii deg[MAXN+5];
int size[MAXN+5];
int parent[MAXN+5];

void make_set(int u)
{
    parent[u] = u;
    size[u] = 1;
}
int find_set(int u)
{
    if ( parent[u] == u )
        return u;
    return parent[u] = find_set(parent[u]);
}
void union_set(int u, int v)
{
    u = find_set(u);
    v = find_set(v);
    if ( u != v ) {
        if ( size[u] < size[v] )
            swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin >> t;
    while ( t-- ) {
        int n, m; cin >> n >> m;
        for ( int i = 1; i <= n; i++)
            adj[i].clear();
        for ( int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for ( int i = 1; i <= n; i++) {
            deg[i] = {adj[i].size(), i};
            make_set(i);
        }
        sort(deg + 1, deg + n + 1, greater<pii>());
        vector<int> ans;
        ans.pb(deg[1].se);
        for ( auto e : adj[ deg[1].se ] )
            union_set(deg[1].se, e);
        for ( int i = 2; i <= n; i++) {
            if ( find_set(deg[i].se) != find_set(deg[1].se) ) {
                ans.pb(deg[i].se);
                union_set(deg[i].se, deg[1].se);
                bool x = false;
                for ( auto e : adj[ deg[i].se ] ) {
                    if ( find_set(e) != find_set(deg[1].se) ) {
                        x = true;
                        break;
                    }
                }
                if ( x ) {
                    for ( auto e : adj[ deg[i].se ] )
                        union_set(e, deg[1].se);
                }
            }
        }
        cout << ans.size() << '\n';
        for ( auto e : ans )
            cout << e << '\n';
    }
}
