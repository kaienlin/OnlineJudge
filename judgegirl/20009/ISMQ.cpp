#include <bits/stdc++.h>

using namespace std;

const int MAXN = (1<<24) + 5;

int n, p;
uint32_t bit[MAXN];
inline int lowbit(int x) { return x & -x; }
uint32_t qry(int idx) {
    uint32_t ret = 0;
    for ( ; idx > 0; idx -= lowbit(idx) )
        ret = max(ret, bit[idx]);
    return ret;
}
void add(int idx, uint32_t val) {
    for ( ; idx <= n; idx += lowbit(idx) )
        bit[idx] = max(bit[idx], val);
}
int mp(int i) { return n - i + 1; }
void init_ISMQ(int N) {
    n = N; p = 1;
    memset(bit, 0, sizeof(bit));
}
void append_ISMQ(uint32_t V) {
    add(mp(p), V);
    ++p;
}
uint32_t query_ISMQ(uint32_t L) {
    return qry(mp(L+1));
}
