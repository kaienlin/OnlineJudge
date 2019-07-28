#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int T; cin >> T;
    while ( T-- ) {
        int N; cin >> N;
        for ( int i = 0; i < N - 2; i++) cout << "1 ";
        if ( N > 1 ) cout << "2 ";
        cout << N << '\n';
    }
}
