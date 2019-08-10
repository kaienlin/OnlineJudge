#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
// using namespace __gnu_pbds;
using pii = pair<int, int>;

constexpr int MAXN = 1e4+5;

int N;
unordered_map<string, int> mp;
vector<pii> G[MAXN];

void clean() {
    mp.clear();
    for ( int i = 1; i <= N; i++)
        G[i].clear();
}
int dijkstra(int src, int dst) {
    unsigned d[MAXN];
    memset(d, -1, sizeof(d));
    d[src] = 0;
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    pq.push( {0, src} );
    while ( !pq.empty() ) {
        int v = pq.top().second, dv = pq.top().first;
        pq.pop();
        if ( dv != d[v] ) continue;
        if ( v == dst ) return dv;
        for ( pii &e : G[v] ) {
            int to = e.second, wei = e.first;
            if ( dv + wei < d[to] ) {
                d[to] = dv + wei;
                pq.push( {d[to], to} );
            }
        }
    }
    return d[dst];
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T; cin >> T;
    while ( T-- ) {
        cin >> N;
        for ( int i = 1; i <= N; i++) {
            string name; cin >> name;
            mp[name] = i;
            int p; cin >> p;
            while ( p-- ) {
                int to, wei; cin >> to >> wei;
                G[i].push_back( {wei, to} );
            }
        }
        int q; cin >> q;
        while ( q-- ) {
            string from, to; cin >> from >> to;
            cout << dijkstra(mp[from], mp[to]) << '\n';
        }
        clean();
    }
}
