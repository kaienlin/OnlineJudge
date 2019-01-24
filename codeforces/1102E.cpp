#include <bits/stdc++.h>
#define MAXN 200000

using namespace std;

struct Pair {
    int num;
    size_t pos;
};

struct R {
    size_t l, r;
    R(int a, int b): l(a), r(b) {}
};

Pair a[MAXN];

bool cmp(Pair x, Pair y) {
    return x.num < y.num;
}
bool cmp2(R x, R y) {
    if ( x.l != y.l )
        return x.l < y.l;
    return x.r < y.r;
}
bool overlap(R a, R &b) {
    return b.l <= a.r;
}

int main()
{
    int n;
    scanf("%d", &n);
    for ( size_t i = 0; i < n; i++) {
        scanf("%d", &a[i].num);
        a[i].pos = i;
    }
    sort(a, a + n, cmp);
    vector<R> seg;
    for ( size_t i = 0; i < n;) {
        int o = a[i].num;
        R range(MAXN, 0);
        for ( ; i < n && a[i].num == o; i++) {
            if ( a[i].pos < range.l )
                range.l = a[i].pos;
            if ( a[i].pos > range.r )
                range.r = a[i].pos;
        }
        seg.push_back(range);
    }
    sort(seg.begin(), seg.end(), cmp2);
    unsigned long long cnt = 1;
    R prev = seg[0];
    for ( auto i = seg.begin(); i != seg.end(); i++) {
        if ( overlap(prev, *i) )
            prev.r = max(prev.r, i->r);
        else {
            cnt++;
            prev = *i;
        }
    }
    unsigned long long ans = 1;
    while ( --cnt ) {
        ans <<= 1;
        ans %= 998244353;
    }
    printf("%llu\n", ans);
    return 0;
}