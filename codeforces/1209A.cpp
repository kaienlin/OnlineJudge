#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

const int MAXN = 101;
const int MAXA = 101;

int main()
{
    IOS;
    int n; cin >> n;
    int A[MAXN];
    bool R[MAXA] = {0}, used[MAXA] = {0};
    for ( int i = 0; i < n; i++) {
        cin >> A[i];
        R[ A[i] ] = true;
    }
    int ans = 0, rest = 0;
    for ( int i = 1; i <= 100; i++)
        rest += R[i];
    for ( int i = 1; i <= 100 && rest > 0; i++) {
        if ( R[i] && !used[i] ) {
            for ( int j = i; j <= 100; j += i) {
                if ( R[j] && !used[j] ) {
                    used[j] = true;
                    rest--;
                }
            }
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}
