#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5+5;

int64_t A[MAXN], B[MAXN];

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T; cin >> T;
    for ( int cs = 1; cs <= T; cs++) {
        cout << "Case " << cs << ":\n";
        int N, q, n; cin >> N >> q;
        A[0] = -1;
        int i;
        for ( n = 1, i = 1; i <= N; i++) {
            int64_t x; cin >> x;
            if ( i != 1 && x != A[n] )
                A[++n] = x;
            else
                A[n] = x;
            B[i] = n;
        }
        while ( q-- ) {
            int L, R; cin >> L >> R;
            cout << B[R] - B[L] + 1 << '\n';
        }
    }
}
