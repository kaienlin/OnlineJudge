#include <bits/stdc++.h>

using namespace std;

inline int64_t f(int64_t x) {
    return x*(x*(x*(x*(182*x-2721)+15396)-40707)+49546)/24-903;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T; cin >> T;
    while ( T-- ) {
        int64_t x; cin >> x;
        cout << f(x) << '\n';
    }
}
