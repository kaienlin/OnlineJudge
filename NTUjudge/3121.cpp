#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

constexpr int MAXN = 1e5+5, MAXM = 2e5+5;

int N, M, T, n, m;
bool vis[MAXN];
vector<int> G[MAXN];
pii edges[MAXM];
bool c1 = true, c3 = true, c4 = true;

void India() {
    cout << "India\n";
    exit(0);
}
void Normal() {
    cout << "Normal\n";
    exit(0);
}
int dfs(int v) {
    vis[v] = true;
    int ret = 1;
    for ( int u : G[v] )
        if ( !vis[u] )
            ret += dfs(u);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> N >> M;
    cin >> T;
    int ans = -1;
    for ( int i = 0; i < T; i++) {
        cin >> n >> m;
        if ( n == N )
            c3 = false;
        if ( m == M )
            c4 = false;
        for ( int j = 0; j < m; j++) {
            int u, v; cin >> u >> v;
            if ( u > v ) {
                swap(u, v);  // u <= v
            } else if ( u == v ) {
                India();
            }
            edges[j] = {u, v};
        }
        sort(edges, edges+m);
        for ( int j = 0; j < m-1; j++)
            if ( edges[j] == edges[j+1] )
                India();

        for ( int j = 0; j < m; j++) {
            int u = edges[j].first, v = edges[j].second;
            G[u].push_back(v); G[v].push_back(u);
        }
        memset(vis, 0, sizeof(vis));
        int v = dfs(1);
        int con = int(v == n);
        if ( ans == -1 )
            ans = con;
        else if ( con != ans )
            c1 = false;
        for ( int j = 1; j <= n; j++)
            G[j].clear();
    }
    if ( c1 || c3 || c4 )
        India();
    Normal();
}
