#include <bits/stdc++.h>

using namespace std;
using ULL = uint64_t;

ULL f(ULL x) {
    return 256743000 * x * x - 769715000 * x + 512972514;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T; cin >> T;
    while ( T-- ) {
        ULL x; cin >> x;
        cout << f(x) << '\n';
    }
}
