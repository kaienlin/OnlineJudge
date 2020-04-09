#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }
using namespace std;

constexpr int max_n = 1e5+5;

int A[max_n], B[max_n];

int main()
{
    IOS;
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        for ( int i = 1; i <= n; i++ ) cin >> A[i];
        for ( int i = 1; i <= n; i++ ) cin >> B[i];
        bool fail = false, pos = false, neg = false;
        for ( int i = 1; i <= n && !fail && !(pos && neg); i++ ) {
            if ( (B[i] > A[i] && !pos) || (B[i] < A[i] && !neg) )
                fail = true;
            if ( A[i] > 0 ) pos = true;
            if ( A[i] < 0 ) neg = true;
        }
        cout << (fail ? "NO\n" : "YES\n");
    }
    return EXIT_SUCCESS;
}
