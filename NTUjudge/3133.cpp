#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }
#define int int64_t

using namespace std;
using LL = int64_t;
using pii = pair<int, int>;

const int MAXF = 1e5+5;
const int MAXN = 4e5+5;
const int INF = 1e15+77777;

struct Family {
    int S = 0, val = 0, candy = -1;
    vector<int> C;
    struct Data { int isum, csum; };
    vector<Data> seg;
    vector<int> lazy, psum;
    
    void preprocess() {
        psum.resize(S+5);
        psum[0] = C[0];
        for ( int i = 1; i < S; i++)
            psum[i] = psum[i-1] + C[i];
        range_upd(1, 0, S-1, S-1, S-1);
    }
    int sum(int l, int r) {
        return psum[r] - (l > 0 ? psum[l-1] : 0);
    }

    int lch(int v) { return 2*v; }
    int rch(int v) { return 2*v+1; }

    void push(int v, int l, int r) {
        int m = (l + r) >> 1;

        seg[lch(v)].isum += (m - l + 1) * lazy[v];
        seg[rch(v)].isum += (r - m) * lazy[v];
        seg[lch(v)].csum += sum(l, m) * lazy[v];
        seg[rch(v)].csum += sum(m+1, r) * lazy[v];

        lazy[lch(v)] += lazy[v];
        lazy[rch(v)] += lazy[v];
        lazy[v] = 0;
    }

    void combine(int v) {
        seg[v].isum = seg[lch(v)].isum + seg[rch(v)].isum;
        seg[v].csum = seg[lch(v)].csum + seg[rch(v)].csum;
    }

    Data combine(Data a, Data b) {
        a.isum += b.isum; a.csum += b.csum;
        return a;
    }

    void range_upd(int v, int tl, int tr, int l, int r) {
        if ( l > r )
            return;
        if ( tl == l && tr == r ) {
            seg[v].isum += (r - l + 1);
            seg[v].csum += sum(l, r);
            lazy[v]++;
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) >> 1;
            range_upd(lch(v), tl, tm, l, min(r, tm));
            range_upd(rch(v), tm+1, tr, max(l, tm+1), r);
            combine(v);
        }
    }

    Data query2(int v, int tl, int tr, int l, int r) {
        if ( l > r )
            return {0, 0};
        if ( tl == l && tr == r )
            return seg[v];
        int tm = (tl + tr) >> 1;
        return combine(query2(lch(v), tl, tm, l, min(r, tm)),
                       query2(rch(v), tm+1, tr, max(l, tm+1), r));
    }

    int query(int v, int tl, int tr, int l, int r) {
        if ( l > r )
            return 0;
        if ( tl == l && tr == r )
            return seg[v].csum;
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        return query(lch(v), tl, tm, l, min(r, tm)) + 
               query(rch(v), tm+1, tr, max(l, tm+1), r);
    }
/*
    int search(int v, int tl, int tr, int k) {
        if ( tl == tr )
            return tl;
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        if ( seg[lch(v)].csum <= k )
            return search(lch(v), tl, tm, k);
        return search(rch(v), tm+1, tr, k - seg[lch(v)].csum);
    }
*/
    void meow(int idx) {
        candy += 4;
        range_upd(1, 0, S-1, idx, S-2);
        int l = -1, r = S-1;
        while ( l + 1 < r ) {
            int m = (l + r) >> 1;
            if ( query(1, 0, S-1, 0, m) <= candy )
                l = m;
            else
                r = m;
        }
        if ( l == -1 ) {
            val = (candy / C[r]) * 1000;
            return;
        }
        Data q = query2(1, 0, S-1, 0, l);
        int rest = candy - q.csum;
        val = q.isum * 1000;
        val += (rest / C[r]) * 1000;
    }
} family[MAXF];

int F;
unordered_map<string, pii> mp;
queue<int> que;
int cur = 0;

void get_XP(int t) {
    que.push(t); cur += 100;
    while ( que.front() <= t - 1800 ) {
        cur -= 100;
        que.pop();
    }
}

int32_t main()
{
    IOS;
    cin >> F;
    for ( int f = 0; f < F; f++) {
        int s; cin >> s;
        family[f].S = s;
        family[f].C.resize(s+5);
        family[f].seg.resize(4*s+5, {0, 0});
        family[f].lazy.resize(4*s+5, 0);
        for ( int i = 0; i < s-1; i++) {
            string name; cin >> name;
            int c; cin >> c;
            family[f].C[i] = c;
            mp[name] = { f, i };
        }
        string name; cin >> name;
        family[f].C[s-1] = INF;
        mp[name] = { f, s-1 };
        family[f].preprocess();
    }
    int mx = 0, evo = 0;
    int n; cin >> n;
    for ( int i = 0; i < n; i++) {
        int t; cin >> t;
        get_XP(t);
        string name; cin >> name;
        pii q = mp[name];
        evo -= family[q.first].val;
        family[q.first].meow(q.second);
        evo += family[q.first].val;
        mx = max(mx, evo + cur);
    }
    cout << mx + 100 * n << "\n";
    return 0;
}
