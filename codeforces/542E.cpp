#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;
using pii = pair<int, int>;

const int MAXN = 1005;

int n, m;
vector<int> G[MAXN];
int color[MAXN], vis[MAXN], dist[MAXN];
vector<int> CC;

void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

bool bfs(int src, int cid) {
    fill(color, color+n+1, -1);
    queue<int> q;
    
    bool res = true;
    color[src] = 0;
    q.push(src);
    while ( q.size() ) {
        int v = q.front(); q.pop();
        vis[v] = cid;
        for ( int u : G[v] ) {
            if ( color[u] == -1 ) {
                color[u] = 1 - color[v];
                q.push(u);
            } else if ( color[v] == color[u] ) {
                res = false;
            }
        }
    }
    return res;
}

int bfs2(int src) {
    queue<int> q;
    q.push(src);
    fill(dist, dist+n+1, -1);
    dist[src] = 0;
    int res = 0;
    while ( q.size() ) {
        int v = q.front(); q.pop();
        for ( int u : G[v] ) {
            if ( dist[u] == -1 ) {
                dist[u] = dist[v] + 1;
                res = max(res, dist[u]);
                q.push(u);
            }
        }
    }
    return res;
}

int main()
{
    IOS;
    cin >> n >> m;
    for ( int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        add_edge(a, b);
    }
    memset(vis, 0, sizeof(vis));
    int comp_no = 1;
    for ( int i = 1; i <= n; i++) {
        if ( !vis[i] ) {
            if ( bfs(i, comp_no) )
                CC.push_back(comp_no);
            ++comp_no;
        }
    }

    if ( CC.size() == 0 ) {
        cout << "-1\n";
        return 0;
    }

    int ans = 0;
    for ( int comp : CC ) {
        int diameter = 0;
        for ( int i = 1; i <= n; i++)
            if ( vis[i] == comp )
                diameter = max(diameter, bfs2(i));
        ans += diameter;
    }

    cout << ans << '\n';

    return 0;
}
