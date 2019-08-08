#include <bits/stdc++.h>

using namespace std;

constexpr int MAXVAL = 1e7+5, MAXN = 2e5+5;

int N, M;
int bit[MAXVAL], A[MAXN];

inline int lowbit(int x) { return x & (-x); }

void add(int idx, int delta) {
    for ( ; idx <= M; idx += lowbit(idx) )
        bit[idx] += delta;
}

int sum(int idx) {
    int ret = 0;
    for ( ; idx > 0; idx -= lowbit(idx) )
        ret += bit[idx];
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T; cin >> T;
    while ( T-- ) {
        cin >> N;
        M = -1;
        for ( int i = 1; i <= N; i++) {
            cin >> A[i];
            M = max(M, A[i]);
        }
        unsigned long long ans = 0;  // be careful of overflow...
        memset(bit, 0, sizeof(bit));
        for ( int i = N; i >= 1; i--) {
            ans += sum(A[i]-1);
            add(A[i], 1);
        }
        cout << ans << '\n';
    }
}
