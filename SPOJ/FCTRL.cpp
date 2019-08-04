#include <bits/stdc++.h>

using namespace std;

constexpr int MXN = 1e9;
vector<int> pfive;

int Z(int x) {
    int ans = 0;
    for ( int p : pfive ) {
        int add = x / p;
        if ( !add ) break;
        ans += add;
    }
    return ans;
}

int main()
{
    for ( int i = 5; i <= MXN; i *= 5)
        pfive.push_back(i);
    int T; cin >> T;
    while ( T-- ) {
        int x; cin >> x;
        cout << Z(x) << '\n';
    }
}
