#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 10000 + 5;

int p[MAXN], accu[MAXN];

int main()
{
    for ( int i = 1, x = 1, cnt = 1; i <= MAXN; i++) {
        p[i] = x;
        if ( --cnt == 0 )
            cnt = ++x;
    }
    for ( int i = 1; i <= MAXN; i++)
        accu[i] = accu[i-1] + p[i];
    int q;
    while ( cin >> q && q )
        cout << q << ' ' << accu[q] << '\n';
    return 0;
}
