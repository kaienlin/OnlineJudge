#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

const int MAXN = 105;
int a[MAXN], timer[MAXN];
bool state[MAXN];

int main()
{
    IOS;
    int n; cin >> n;
    string s; cin >> s;
    for ( int i = 0; i < n; i++)
        cin >> a[i] >> timer[i];
    int ans = 0;
    for ( int i = 0; i < n; i++) {
        state[i] = (s[i] == '1');
        ans += state[i];
    }
    int t = 125;
    while ( t-- ) {
        int cnt = 0;
        for ( int i = 0; i < n; i++) {
            --timer[i];
            if ( timer[i] == 0 ) {
                state[i] = !state[i];
                timer[i] = a[i];
            }
            cnt += state[i];
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}
