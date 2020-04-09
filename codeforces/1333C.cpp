#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using I64 = int64_t;
using U64 = uint64_t;
using pii = pair<int, int>;

constexpr int max_n = 2e5+5;

int A[max_n];
LL prefix_sum[max_n];

int main()
{
    IOS;
    int n; cin >> n;
    for ( int i = 1; i <= n; i++ )
        cin >> A[i];

    for ( int i = 1; i <= n; i++ )
        prefix_sum[i] = prefix_sum[i-1] + A[i];
    
    LL ans = 0;
    map<LL, int> mp;
    int lowest = n + 1;
    for ( int i = n; i >= 0; i-- ) {
        auto it = mp.find(prefix_sum[i]);
        lowest = min(it == mp.end() ? n+1 : it->second, lowest);
        ans += lowest - i - 1;
        mp[prefix_sum[i]] = i;
    }
    
    cout << ans << '\n';

    return EXIT_SUCCESS;
}
