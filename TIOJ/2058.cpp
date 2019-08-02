#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;
using ULL = unsigned long long;
using pui = pair<ULL, int>;

int N, M, A, B;
vector< pair<int, int> > adj1[MAXN], adj2[MAXN];

ULL dijkstra(int src, int dst, vector< pair<int, int> > adj[], ULL min_d[]) {
    memset(min_d, 0xFFFFFFFF, sizeof(ULL)*N);
    min_d[src] = 0;
    priority_queue< pui, vector<pui>, greater<pui> > pq;
    pq.push({0, src});

    while ( !pq.empty() ) {
        int v = pq.top().second;
        ULL d_v = pq.top().first;  // Be careful of overflow......
        pq.pop();
        if ( d_v != min_d[v] )
            continue;
        for ( auto e : adj[v] ) {
            int to = e.first;
            int wei = e.second;
            if ( d_v + wei < min_d[to] ) {
                min_d[to] = min_d[v] + wei;
                pq.push({min_d[to], to});
            }
        }
    }
    return min_d[dst];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while ( T-- ) {
        cin >> N >> M >> A >> B;
        for ( int i = 0; i < N; i++) {
            adj1[i].clear();
            adj2[i].clear();
        }
        for ( int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj1[u].push_back( {v, w} );
            adj2[v].push_back( {u, w} );
        }

        ULL d1[MAXN], d2[MAXN];
        ULL shortest = dijkstra(A, B, adj1, d1);
        dijkstra(B, B, adj2, d2);  // 在反向圖上以dest爲src做Dijkstra
        ULL sec_shortest = ULLONG_MAX;

        for ( int i = 0; i < N; i++) {  // 枚舉所有edge
            for ( auto edge : adj1[i] ) {
                ULL d = d1[i] + d2[edge.first] + edge.second;
                if ( d > shortest && d < sec_shortest )
                    sec_shortest = d;
            }
        }

        cout << sec_shortest - shortest << '\n';
    }
}
