#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;

const int MAXN = 105;
const int MAXM = 2005;

int n, m;
bool G[MAXN][MAXN];
int P[MAXM], ans[MAXM];

inline void add_edge(int u, int v) {
    G[u][v] = G[v][u] = true;
}
inline void remove_edge(int u, int v) {
    G[u][v] = G[v][u] = false;
}
bool dfs(int v, int d) {
    ans[d] = v;
    if ( d == m )
        return true;
    for ( int u = 1; u <= n; u++) {
        if ( G[v][u] ) {
            remove_edge(v, u);
            if ( dfs(u, d+1) )
                return true;
            add_edge(v, u);
        }
    }
    return false;
}

int main()
{
    IOS;
    cin >> n >> m;
    for ( int i = 0; i <= m; i++)
        cin >> P[i];
    copy(P, P+m+1, ans);
    for ( int i = m-1; i >= 0; i--) {
        int x = P[i], y = P[i+1];
        add_edge(x, y);
        for ( int j = y+1; j <= n; j++) if ( G[x][j] ) {
            remove_edge(x, j);
            if ( dfs(j, i+1) ) {
                for ( int i = 0; i <= m; i++)
                    cout << ans[i] << " \n"[i==m];
                return 0;
            }
            add_edge(x, j);
        }
    }
    cout << "No solution\n";
    return 0;
}
