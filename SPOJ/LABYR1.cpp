#include <bits/stdc++.h>
#define fi first
#define se second

/* Take use of algorithm to find the diameter of a tree.
 * The original approach is using DFS, but this problem requires
 * us to find the maximum of the length of all pairs' shortest path.
 * Therefore, I use BFS to implement exactly the same algorithm.
 * However, someone in discuss area claims that it can be solve with one DFS, 
 * but I still cannot figure it out.
 */

using namespace std;
using pii = pair<int, int>;
using pip = pair<int, pii>;

constexpr int MAXL = 1e3+5, MAXN = 1e6+5;
const vector<pii> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int R, C;
bool grid[MAXL][MAXL];
bool vis[MAXL][MAXL];
int dist[MAXL][MAXL];

pip bfs(pii v) {
    memset(vis, 0, sizeof(vis));
    pip ret = {0, v};
    queue<pii> q;
    q.push( v );
    dist[v.fi][v.se] = 0;
    while ( !q.empty() ) {
        pii u = q.front(); q.pop();
        int i = u.fi, j = u.se;
        vis[i][j] = true;
        ret = max(ret, make_pair(dist[i][j], u));
        for ( pii d : dir ) {
            if ( grid[i + d.fi][j + d.se] && !vis[i + d.fi][j + d.se] ) {
                q.push( {i + d.fi, j + d.se} );
                dist[i + d.fi][j + d.se] = dist[i][j] + 1;
            }
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while ( T-- ) {
        memset(grid, 0, sizeof(grid));
        cin >> C >> R;
        pii start = make_pair(-1, -1);
        for ( int i = 1; i <= R; i++) {
            string ln; cin >> ln;
            for ( int j = 1; j <= C; j++)
                if ( ln[j-1] == '.' )
                    grid[i][j] = true, start = {i, j};
                
        }
        if ( start == make_pair(-1, -1) ) {
            cout << "Maximum rope length is 0.\n";
            continue;
        }
        pii a = bfs(start).se;
        int ans = bfs(a).fi;
        cout << "Maximum rope length is " << ans << ".\n";
    }
}
