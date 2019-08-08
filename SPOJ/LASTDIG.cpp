#include <bits/stdc++.h>

using namespace std;

#define int int64_t
int pw(int a, int n) {
    int ret = 1;
    for (; n > 0; n >>= 1) {
        if ( n & 1 ) ret = ret * a % 10;
        a = a * a % 10;
    }
    return ret;
}
#undef int

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int T; cin >> T;
    while ( T-- ) {
        int64_t a, n;
        cin >> a >> n;
        cout << pw(a, n) << '\n';
    }
}
