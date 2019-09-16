#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

const int MAXH = 100+5, MAXW = 100+5;

template<typename T>
T max(T a, T b, T c) { return max(a, max(b, c)); }

int A[MAXH][MAXW];
LL dp[MAXH][MAXW];

int h, w;
LL solve() {
    for ( int i = 0; i < w; i++)
        dp[0][i] = A[0][i];
    for ( int i = 1; i < h; i++)
        for ( int j = 0; j < w; j++) {
            if ( j == 0 )
                dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]) + A[i][j];
            else if ( j == w-1 ) 
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + A[i][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]) + A[i][j];
        }
    return *max_element(dp[h-1], dp[h-1] + w);
}

int main()
{
    IOS;
    int T; cin >> T;
    while ( T-- ) {
        cin >> h >> w;
        for ( int i = 0; i < h; i++)
            for ( int j = 0; j < w; j++)
                cin >> A[i][j];
        cout << solve() << '\n';
    }
    return 0;
}
