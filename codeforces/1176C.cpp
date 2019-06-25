#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 500000;

int A[MAXN], m[64];

int main()
{
    m[4] = 1, m[8] = 2, m[15] = 3, m[16] = 4, m[23] = 5, m[42] = 6;
    ios::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;
    for ( int i = 0; i < n; i++) {
        int x; cin >> x;
        A[i] = m[x];
    }
    int cnt[7] = {INT_MAX}, ans = 0;
    for ( int i = 0; i < n; i++) {
        cnt[A[i]]++;
        cnt[A[i] - 1]--;
        if ( cnt[A[i] - 1] < 0 ) {
            ans++;
            cnt[A[i]]--;
            cnt[A[i] - 1]++;
        }
    }
    for ( int i = 1; i <= 5; i++)
        ans += cnt[i] * i;
    cout << ans << '\n';
}
