#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

int main()
{
    IOS;
    int N, Q; cin >> N >> Q;
    bitset<100005> bs;
    bs[0] = 1;
    for ( int i = 0; i < N; i++) {
        int x; cin >> x;
        bs |= bs << x;  // the essential!
    }
    int sum[100005] = {0};
    for ( int i = 1; i <= 100001; i++)
        sum[i] = sum[i-1] + bs[i];
    while ( Q-- ) {
        int l, r; cin >> l >> r;
        cout << sum[r] - sum[l-1] << '\n';
    }
    return 0;
}
