#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

int main()
{
    IOS;
    int q; cin >> q;
    while ( q-- ) {
        int n; cin >> n;
        int cnt[32] = {0};
        for ( int i = 0; i < n; i++) {
            int x; cin >> x;
            int p = 31-__builtin_clz(x);
            cnt[p]++;
        }
        for ( int i = 0; i < 11; i++) {
            cnt[i + 1] += cnt[i] / 2;
            cnt[i] %= 2;
        }
        if ( cnt[11] ) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
