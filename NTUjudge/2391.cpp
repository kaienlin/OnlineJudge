#include <bits/stdc++.h>
#define FI first
#define SE second
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using pii = pair<int, int>;

const int MAXN = 3e6+5, MAXM = 18;
const LL mod = 1e9+9;

struct DSU {
    int pr[MAXN], sz[MAXN];

    void init(int N) {
        for ( int i = 0; i <= N; i++)
            mk_set(i);
    }
    void mk_set(int v) {
        pr[v] = v;
        sz[v] = 1;
    }
    int find(int v) {
        if ( v == pr[v] ) return v;
        return (pr[v] = find(pr[v]));
    }
    void unite(int v, int u) {
        v = find(v), u = find(u);
        if ( v != u ) {
            if ( sz[v] < sz[u] )
                swap(v, u);
            pr[u] = v;
            sz[v] += sz[u];
        }
    }
} DSU;

int N, M;
LL inv[MAXN], fac[MAXN], fac_inv[MAXN], pow6_inv[MAXN];

void init() {
    inv[1] = 1;
    for ( int i = 2; i <= 3*N; i++)
        inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = fac_inv[0] = pow6_inv[0] = 1;
    for ( int i = 1; i <= 3 * N; i++) {
        fac[i] = fac[i-1] * i % mod;
        fac_inv[i] = fac_inv[i-1] * inv[i] % mod;
        pow6_inv[i] = pow6_inv[i-1] * inv[6] % mod;
    }
}

LL nn;
LL calc() {
    vector<int> teams;
    for ( int i = 0; i < nn; i++)
        if ( DSU.find(i) == i )
            teams.push_back(i);
    int thr = 0, two = 0;
    for ( int i : teams ) {
        if ( DSU.sz[i] > 3 )
            return 0;
        else if ( DSU.sz[i] == 3 )
            ++thr;
        else if ( DSU.sz[i] == 2 )
            ++two;
    }
    LL rest = 3 * N - 3 * thr - 2 * two;
    LL groups = (rest - two) / 3;
    // LL g = rest -two;
    // C(rest, two) * two! * C(g, 3) * C(g-3, 3) * ... * C(6, 3) * C(3, 3) / (g/3)!
    return fac[rest] * pow6_inv[groups] % mod * fac_inv[groups] % mod;
}

int main()
{
    IOS;
    cin >> N >> M;
    init();
    set<int> S;
    vector<pii> good, bad;
    for ( int i = 1; i <= M; i++) {
        int a, b, c; cin >> a >> b >> c;
        if ( c == 0 )
            good.push_back( {a, b} );
        else
            bad.push_back( {a, b} );
        S.insert(a); S.insert(b);
    }
    map<int, int> mp;
    nn = 0;
    for ( int i : S ) {
        mp[i] = nn++;
    }
    for ( pii &p : good ) {
        p.FI = mp[p.FI];
        p.SE = mp[p.SE];
    }
    for ( pii &p : bad ) {
        p.FI = mp[p.FI];
        p.SE = mp[p.SE];
    }
    int sz = bad.size();
    LL ans = 0;
    for ( int msk = 0; msk < (1<<sz); msk++) {
        DSU.init(nn);
        for ( pii p : good )
            DSU.unite(p.FI, p.SE);
        int cnt = 0;
        for ( int j = 0; j < sz; j++) {
            if ( (msk>>j) & 1 ) {
                DSU.unite(bad[j].FI, bad[j].SE);
                ++cnt;
            }
        }
        LL r = calc();
        if ( cnt & 1 )
            ans = (ans - r + mod) % mod;
        else
            ans = (ans + r) % mod;
    }
    cout << ans << '\n';
    return 0;
}
