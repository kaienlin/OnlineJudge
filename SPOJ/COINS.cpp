#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

ULL solve(ULL n) {
    if ( n <= 11 ) return n;
    return solve(n/2) + solve(n/3) + solve(n/4);
}

int main()
{
    ULL x;
    while ( cin >> x )
        cout << solve(x) << '\n';
    return 0;
}
