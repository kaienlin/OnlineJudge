#include <bits/stdc++.h>
#define MAXN 300000
 char _;
#define RC(c) do{while((c=getchar())<'a');}while(0)
#define RIT(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define WI(_x) do{int64_t x=_x;if(!x){putchar('0');putchar('\n');break;}else if(x<0){putchar('-');x=-x;}char buf[128];int t=0;while(x){buf[t++]=x%10+'0';x/=10;}while(t--)putchar(buf[t]);putchar('\n');}while(0)


using namespace std;
using ULL = unsigned long long;

struct Edge {
    int u, v, w;
};

struct Item {
    int id, edge_id;
    ULL dist, last_edge;
    bool operator < (const Item &rhs) const { return (dist != rhs.dist) ? (dist > rhs.dist) : (last_edge > rhs.last_edge); }
};

int n, m;
Edge edges[MAXN + 1];
vector<int> adj[MAXN + 1];
priority_queue< Item > pq;
ULL min_d[MAXN + 1];
bool selected[MAXN + 1];
vector<int> ans;

ULL dijkstra(int src) {
    memset(min_d, -1, sizeof(min_d));
    min_d[src] = 0;
    pq.push( {src, 0, 0, 0} );
    memset(selected, 0, sizeof(selected));
    ULL ret = 0;
    while ( !pq.empty() ) {
        Item q = pq.top(); pq.pop();
        int v = q.id;
        ULL d_v = q.dist;
        if ( selected[v] )
            continue;
        ret += q.last_edge;
        selected[v] = true;
        if ( q.edge_id != 0 )
            ans.push_back(q.edge_id);
        for ( int e : adj[v] ) {
            Edge eg = edges[e];
            int to = eg.u == v ? eg.v : eg.u;
            unsigned w = eg.w;
            if ( d_v + w <= min_d[to] ) {
                min_d[to] = d_v + w;
                pq.push( {to, e, min_d[to], w} );
            }
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    RIT(n); RIT(m);
    for ( int i = 1; i <= m; i++) {
        int u, v, w;
        RIT(u); RIT(v); RIT(w);
        edges[i] = {u, v, w};
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
    int src; RIT(src);
    cout << dijkstra(src) << '\n';
    for ( int e : ans )
        cout << e << ' ';
    cout << '\n';
}
