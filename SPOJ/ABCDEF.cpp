#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

const int MAXN = 101;

LL A[MAXN];

unordered_map<LL, LL> mp;

int main()
{
    IOS;
    int N; cin >> N;
    for ( int i = 0; i < N; i++)
        cin >> A[i];

    for ( int i = 0; i < N; i++)
        for ( int j = 0; j < N; j++)
            for ( int k = 0; k < N; k++)
                ++mp[A[i] * A[j] + A[k]];

    LL ans = 0;
    for ( int i = 0; i < N; i++)
        for ( int j = 0; j < N; j++)
            for ( int k = 0; k < N; k++)
                if ( A[i] != 0 )
                    ans += mp[A[i] * (A[j] + A[k])];

    cout << ans << '\n';
    return 0;
}
