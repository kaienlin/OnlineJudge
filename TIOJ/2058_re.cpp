#include <bits/stdc++.h>
 char _;
#define RC(c) do{while((c=getchar_unlocked())<'a');}while(0)
#define RIT(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define WI(_x) do{int64_t x=_x;if(!x){putchar_unlocked('0');putchar_unlocked('\n');break;}else if(x<0){putchar_unlocked('-');x=-x;}char buf[128];int t=0;while(x){buf[t++]=x%10+'0';x/=10;}while(t--)putchar_unlocked(buf[t]);putchar_unlocked('\n');}while(0)
#pragma GCC optimize("O3")
#define MAXN 100000

using namespace std;
using ULL = unsigned long long;
using pui = pair<ULL, int>;

int N, M, A, B;
vector< pair<int, int> > adj1[MAXN];

ULL dijkstra(int src, int dst, vector< pair<int, int> > adj[], ULL d1[], ULL d2[]) {
    memset(d1, 0xFFFFFFFF, sizeof(ULL)*N);
    memset(d2, 0xFFFFFFFF, sizeof(ULL)*N);
    d1[src] = 0;
    priority_queue< pui, vector<pui>, greater<pui> > pq;
    pq.push({0, src});

    while ( !pq.empty() ) {
        int v = pq.top().second;
        ULL d_v = pq.top().first;  // Be careful of overflow......
        pq.pop();
        if ( d_v > d2[v] )  // d_v must be the shortest or second shortest
            continue;
        for ( auto e : adj[v] ) {
            int to = e.first;
            ULL dd = d_v + e.second;
            if ( dd < d1[to] ) {
                swap(dd, d1[to]);
                pq.push( {d1[to], to} );
            }
            if ( dd < d2[to] && dd > d1[to] ) {
                d2[to] = dd;
                pq.push( {d2[to], to} );
            }

        }
    }
    return d1[dst];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    RIT(T);
    while ( T-- ) {
        RIT(N); RIT(M); RIT(A); RIT(B);
        for ( int i = 0; i < N; i++)
            adj1[i].clear();
        for ( int i = 0; i < M; i++) {
            int u, v, w;
            RIT(u); RIT(v); RIT(w);
            adj1[u].push_back( {v, w} );
        }

        ULL d1[MAXN], d2[MAXN];
        ULL shortest = dijkstra(A, B, adj1, d1, d2);
        ULL sec_shortest = d2[B];
        ULL ans = sec_shortest - shortest;
        WI(ans);
    }
}
