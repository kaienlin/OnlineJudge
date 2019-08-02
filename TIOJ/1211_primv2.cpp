#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define MAXN 10000

using namespace std;

struct Edge {
    int to, w;
    Edge(int to, int w): to(to), w(w) {}
};

struct Vertice {
    int id, min_w;
    Vertice(int id, int min_w): id(id), min_w(min_w) {}
    bool operator < (const Vertice &rhs) const { return min_w > rhs.min_w; }
};

vector< Edge > adj[MAXN + 1];
bool selected[MAXN + 1];

int prim(int n) {
    int tot = 0;
    vector<int> min_d(n+1, INT_MAX);
    min_d[1] = 0;
    priority_queue< Vertice > q;
    q.push( Vertice(1, 0) );
    memset(selected, 0, sizeof(selected));
    
    for ( int i = 1; i <= n; i++) {
        if ( q.empty() )
            return -1;

        int v = q.top().id;
        if ( selected[v] ) {  // if ( min_d[v] != q.top().min_d ) also work!
            i--;
            q.pop();
            continue;
        }
        selected[v] = true;
        tot += min_d[v];
        q.pop();

        for ( auto e : adj[v] ) {
            if ( !selected[e.to] && e.w < min_d[e.to] ) {
                min_d[e.to] = e.w;
                q.push( Vertice(e.to, e.w) );
            }
        }
    }

    return tot;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while ( cin >> n >> m && n ) {
        for ( int i = 1; i <= n; i++)
            adj[i].clear();
        for ( int i = 0; i < m; i++) {
            int u, v, w; cin >> u >> v >> w;
            adj[u].push_back( Edge(v, w) );
            adj[v].push_back( Edge(u, w) );
        }
        cout << prim(n) << '\n';
    }
}
