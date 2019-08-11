#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

/* This problem is equal to checking if a graph has a Euler trail or circuit.
 * Every word is like a edge, and each character from 'a' to 'z' can be regraded
 * as a vertex. Note that to check if a digraph has a Euler trail or circuit, we
 * also need to check if the graph is (weakly) connected besides the indegree and 
 * outdegree.
 *
 * To check if a digraph is weakly connected, just check if the underlying 
 * undirected graph is connected.
 */

using namespace std;

bool adj[26][26];
bool vis[26];

void dfs(int v) {
    vis[v] = true;
    for ( int u = 0; u < 26; u++ )
        if ( adj[v][u] && !vis[u] )
            dfs(u);
}

int main()
{
    IOS;
    int T; cin >> T;
    while ( T-- ) {
        int N; cin >> N;
        int in[26] = {0}, out[26] = {0};
        memset(adj, 0, sizeof(adj));
        for ( int i = 0; i < N; i++) {
            string s; cin >> s;
            int first = s.front() - 'a', back = s.back() - 'a';
            in[back]++;
            out[first]++;
            adj[first][back] = adj[back][first] = true;
        }
        int cnt[3] = {0};
        for ( int i = 0; i < 26; i++) {
            if ( in[i] != out[i] ) {
                if ( in[i] - out[i] == 1 )
                    cnt[0]++;
                else if ( out[i] - in[i] == 1 )
                    cnt[1]++;
                else
                    cnt[2]++; 
            }
        }
        if ( cnt[2] == 0 && (cnt[0] == 0 && cnt[1] == 0 || cnt[0] == 1 && cnt[1] == 1) ) {
            memset(vis, 0, sizeof(vis));
            for ( int i = 0; i < 26; i++) {
                if ( in[i] > 0 || out[i] > 0 ) {
                    dfs(i);
                    break;
                }
            }
            bool connected = true;
            for ( int i = 0; i < 26; i++)
                if ( (in[i] > 0 || out[i] > 0) && !vis[i] )
                    connected = false;
            if ( connected )
                cout << "Ordering is possible." << '\n';
            else
                cout << "The door cannot be opened." << '\n';
        } else {
            cout << "The door cannot be opened." << '\n';
        }
    }
    return 0;
}
