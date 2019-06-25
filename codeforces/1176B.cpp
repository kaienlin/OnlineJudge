#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 100;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        int cnt[3] = {0};
        for ( int i = 0; i < n; i++) {
            int a; cin >> a;
            ++cnt[a % 3];   
        }
        int ans = cnt[0];
        if ( cnt[1] < cnt[2] ) swap(cnt[1], cnt[2]);
        ans += cnt[2];
        cnt[1] -= cnt[2];
        ans += cnt[1] / 3;
        cout << ans << '\n';
    }
}
