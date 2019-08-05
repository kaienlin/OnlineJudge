#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MXN = 1e5+5;

struct Record {
    int mx, mx_f;
    gp_hash_table<int, int> ht;
} mem[MXN], *mem_ptr[MXN];

vector<int> adj[MXN];
int N;
int f[MXN], ans[MXN];

Record* new_rec(int v) {
    Record *ret = &mem[v];
    ret->mx = 1;
    ret->mx_f = f[v];
    ret->ht.clear();
    return ret;
}
Record* combine(Record* a, Record* b) {
    if ( a->ht.size() < b->ht.size() )
        swap(a, b);
    for ( auto &p : b->ht ) {
        int cnt = a->ht[p.first] += p.second;
        if ( cnt > a->mx || cnt == a->mx && p.first < a->mx_f )
            a->mx = cnt, a->mx_f = p.first;
    }
    return a;
}
void DFS(int v) {
    Record *r = mem_ptr[v] = new_rec(v);
    r->ht[f[v]] += 1;
    for ( int u : adj[v] ) {
        DFS(u);
        r = combine(r, mem_ptr[u]);
    }
    mem_ptr[v] = r;
    ans[v] = r->mx_f;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T; cin >> T;
    while ( T-- ) {
        int root = -1;
        cin >> N;
        for ( int i = 1; i <= N; i++) {
            int m; cin >> m;
            if ( m > 0 )
                adj[m].push_back(i);
            else
                root = i;
        }
        for ( int i = 1; i <= N; i++)
            cin >> f[i];
        DFS(root);
        for ( int i = 1; i <= N; i++)
            cout << ans[i] << (" \n"[i == N]);
        for ( int i = 1; i <= N; i++)
            adj[i].clear();
    }
}
