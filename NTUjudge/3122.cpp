#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }
using namespace std;
using LL = int64_t;

constexpr int MAXN = 2e5+10;
constexpr LL mod = 1e9+9;

struct Item {
    LL one, two, thr;
    Item(): one(0),two(0),thr(0) {};
    Item(LL _1, LL _2, LL _3): one(_1),two(_2),thr(_3) {}
} seg[4 * MAXN];

bool tag[4 * MAXN];

LL A[MAXN];

inline int lch(int v) { return 2 * v; }
inline int rch(int v) { return 2 * v + 1; }
inline LL mylog(LL a, LL e) {
    int ans = 0;
    while ( a /= e ) ++ans;
    return ans;
}

Item combine(Item a, Item b) {
    Item ret;
    ret.one = (a.one + b.one) % mod;
    ret.two = ((a.two + a.one * b.one % mod) % mod + b.two) % mod;
    ret.thr = ((((a.thr + a.one * b.two % mod) % mod) + (a.two * b.one % mod)) % mod + b.thr) % mod;
    return ret;
}

void pull(int v) {
    if ( tag[lch(v)] && tag[rch(v)] )
        tag[v] = true;
    else
        tag[v] = false;
}

void build_seg(int v, int tl, int tr) {
    if ( tl == tr ) {
        seg[v] = Item(A[tl], 0, 0);
        tag[v] = (A[tl] == 0);
    } else {
        int tm = (tl + tr) >> 1;
        build_seg(lch(v), tl, tm);
        build_seg(rch(v), tm+1, tr);
        seg[v] = combine(seg[lch(v)], seg[rch(v)]);
        pull(v);
    }
}

Item query(int v, int tl, int tr, int l, int r) {
    if ( l > r || tag[v] )
        return Item(0, 0, 0);
    if ( l == tl && r == tr )
        return seg[v];
    int tm = (tl + tr) >> 1;
    return combine(query(lch(v), tl, tm, l, min(r, tm)), query(rch(v), tm+1, tr, max(l, tm+1), r));
}

void updx(int v, int tl, int tr, LL e) {
    if ( tl == tr ) {
        seg[v].one = mylog(seg[v].one, e);
        tag[v] = (seg[v].one == 0);
    } else {
        int tm = (tl + tr) >> 1;
        updx(lch(v), tl, tm, e);
        updx(rch(v), tm+1, tr, e);
        seg[v] = combine(seg[lch(v)], seg[rch(v)]);
        pull(v);
    }
}

void upd1(int v, int tl, int tr, int l, int r, LL e) {
    if ( tr < l || tl > r || tag[v] ) return;
    if ( tl == tr ) {
        seg[v].one = mylog(seg[v].one, e);
        tag[v] = (seg[v].one == 0);
    } else {
        int tm = (tl + tr) >> 1;
        upd1(lch(v), tl, tm, l, r, e);
        upd1(rch(v), tm+1, tr, l, r, e);
        seg[v] = combine(seg[lch(v)], seg[rch(v)]);
        pull(v);        
    }
}

void upd2(int v, int tl, int tr, int pos, int new_val) {
    if ( tl == tr ) {
        seg[v] = Item(new_val, 0, 0);
        tag[v] = (new_val == 0);
    } else {
        int tm = (tl + tr) >> 1;
        if ( pos <= tm )
            upd2(lch(v), tl, tm, pos, new_val);
        else
            upd2(rch(v), tm+1, tr, pos, new_val);
        seg[v] = combine(seg[lch(v)], seg[rch(v)]);
        pull(v);
    }
}

int main()
{
    IOS;
    int N, Q, l, r, e, x, y; cin >> N >> Q;
    for ( int i = 1; i <= N; i++)
        cin >> A[i];
    build_seg(1, 1, N);
    while ( Q-- ) {
        int cmd; cin >> cmd;
        switch ( cmd ) {
            case 1:
                cin >> l >> r >> e;
                upd1(1, 1, N, l, r, e);
                break;
            case 2:
                cin >> x >> y;
                upd2(1, 1, N, x, y);
                break;
            case 3:
                cin >> l >> r;
                cout << query(1, 1, N, l, r).thr << '\n';
                break;
        }
    }
    return 0;
}
