#include <bits/stdc++.h>

// Algorithm: Bipartite Graph Checking

using namespace std;

constexpr int MXN = 2000+5;

bool vis[MXN], color[MXN];
vector<int> adj[MXN];

void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void clean(int n) {
    for ( int i = 1; i <= n; i++)
        adj[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(color, 0, sizeof(vis));
}
bool dfs(int u) {
    for ( int v : adj[u] ) {
        if ( vis[v] ) {
            if ( color[v] == color[u] )
                return false;
        } else {
            vis[v] = true;
            color[v] = !color[u];
            if ( !dfs(v) )
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T; cin >> T;
    for ( int scenario = 1; scenario <= T; scenario++) {
        int n, m; cin >> n >> m;
        for ( int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            add_edge(u, v);
        }
        
        bool result = true;
        for ( int i = 1; i <= n; i++) {
            if ( !vis[i] ) {
                if ( !dfs(i) )
                    result = false;
            }
        }
        cout << "Scenario #" << scenario << ":\n";
        if ( result )
           cout << "No suspicious bugs found!\n";
        else
           cout << "Suspicious bugs found!\n"; 

        clean(n);
    }
}
