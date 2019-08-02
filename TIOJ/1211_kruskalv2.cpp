#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define MAXN 10000

using namespace std;

// Disjoint Set Union
int parent[MAXN+1], size[MAXN+1];

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}
int find_set(int v) {
    if ( v == parent[v] )
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_set(int u, int v) {
    if ( u != v ) {
        if ( size[u] < size[v] )
            swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
}
// Disjoint Set Union

struct Edge {
    int u, v, w;
    Edge(int u=-1, int v=-1, int w=-1): u(u), v(v), w(w) {}   // Need default constructor
    bool operator < (const Edge &rhs) const { return w < rhs.w; }
};

vector<Edge> edges;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    while ( cin >> n >> m && n ) {
        edges.clear();
        for ( int i = 1; i <= n; i++)
            make_set(i);
        for ( int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back( Edge(u, v, w) );
        }
        sort(edges.begin(), edges.end());
        uint64_t cost = 0;
        for ( auto &e : edges ) {
            int a = find_set(e.u), b = find_set(e.v);
            if ( a != b ) {
                cost += e.w;
                union_set(a, b);
            }
        }

        if ( size[ find_set(1) ] != n )  // Don't forget find_set()
            cout << "-1" << '\n';
        else
            cout << cost << '\n';
    }
}
