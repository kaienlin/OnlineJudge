#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int q; cin >> q;
    while (q--) {
        uint64_t n, ans = 0; cin >> n;
        for ( ; n % 2 == 0; n /= 2)
            ++ans;
        for ( ; n % 3 == 0; n /= 3)
            ans += 2;
        for ( ; n % 5 == 0; n /= 5)
            ans += 3;
        if ( n == 1 ) cout << ans << '\n';
        else cout << -1 << '\n';
    }
}
