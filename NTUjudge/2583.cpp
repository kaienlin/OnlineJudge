#include <bits/stdc++.h>

using namespace std;
using LL = int64_t;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T; cin >> T;
    while ( T-- ) {
        int N, W, H; cin >> N >> W >> H;
        LL sum = (LL)W * H;
        while ( N-- ) {
            LL x; cin >> x;
            if ( sum >= 0 )
                sum -= x;
        }
        if ( sum != 0 ) cout << "NO\n";
        else cout << "YES\n";
    }
}
