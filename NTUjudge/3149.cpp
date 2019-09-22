#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }
#define FI first
#define SE second

using namespace std;
using LL = int64_t;
using ULL = uint64_t;
using pii = pair<int, int>;

const int MAXN = 1e5+5;
const int MAXM = 1e5+5;

struct Boomerang {
    int u, v, w;
};

int N, M;
stack<int> G[MAXN];
bool used[MAXN];
pii edges[MAXM];
vector<Boomerang> ans;

int neigh(int eid, int u) { return edges[eid].FI == u ? edges[eid].SE : edges[eid].FI; }

int take_edge(int v) {
    while ( G[v].size() ) {
        int eid = G[v].top(); G[v].pop();
        if ( !used[eid] ) {
            used[eid] = true;
            return eid;
        }
    }
    return -1;
}
int dfs(int v, int from_edge) {
    while ( G[v].size() ) {
        int ed1 = take_edge(v);
        if ( ed1 == -1 )  // no more edges can be taken
            return from_edge;
        
        int to1 = neigh(ed1, v);
        int r1 = dfs(to1, ed1);
        if ( r1 == -1 )
            continue;

        int ed2 = take_edge(v);
        if ( ed2 == -1 ) {  // we have one edge alone
            if ( from_edge != -1 ) {
                ans.push_back( {neigh(from_edge, v), v, neigh(ed1, v)} );
                return -1;
            }
            return -1;
        }

        int to2 = neigh(ed2, v);
        int r2 = dfs(to2, ed2);

        if ( r2 == -1 ) {
            G[v].push(ed1);
            used[ed1] = false;
            continue;
        }

        ans.push_back( {to1, v, to2} );
    }
}

int main()
{
    IOS;
    cin >> N >> M;
    for ( int i = 0; i < M; i++) {
        cin >> edges[i].FI >> edges[i].SE;
        G[edges[i].FI].push(i);
        G[edges[i].SE].push(i);
    }
    for ( int i = 1; i <= N; i++)
        dfs(i, -1);
    
    cout << ans.size() << '\n';
    for ( Boomerang &it : ans )
        cout << it.u << " " << it.v << " " << it.w << '\n';
    return 0;
}
