#include <bits/stdc++.h>

using namespace std;

// the substraction operation may make value becomes negative
// simply add M after substraction suffices

const int64_t M = 100000007LL;

int64_t f(int64_t x) {
    return (155136880301LL % M * x % M * x % M - 998244353LL % M * x % M + 71227122LL + M) % M;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int T; cin >> T;
    while ( T-- ) {
        int64_t x; cin >> x;
        cout << f(x % M) << '\n';
    }
}
