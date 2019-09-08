#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;
using pii = pair<int, int>;

const int MAXN = 205;
int n, F[MAXN], dist[MAXN];
bool vis[MAXN];

pii dfs(int v, int d, int o) {
    vis[v] = true;
    dist[v] = d;
    if ( vis[F[v]] ) {
        if ( F[v] == o )
            return {d+1, F[v]};
        else
            return {dist[F[v]], F[v]};
    }
    return dfs(F[v], d+1, o);
}

LL lcm(LL a, LL b) {
    return a / __gcd(a, b) * b;
}

int main()
{
    IOS;
    cin >> n;
    for ( int i = 1; i <= n; i++)
        cin >> F[i];
    LL mx = 0, llcm = 1;
    for ( int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        pii r = dfs(i, 0, i);
        // cout << i << ": " << r.first << " " << r.second << '\n';
        if ( i == r.second ) {
            llcm = lcm(llcm, r.first);
        } else {
            mx = max(mx, (LL)r.first);
        }
    }
    LL ans = llcm;
    while ( ans < mx )
       ans += llcm; 
    cout << ans << '\n';
    return 0;
}
