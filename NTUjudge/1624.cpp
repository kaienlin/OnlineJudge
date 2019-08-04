#include <bits/stdc++.h>

using namespace std;
using ULL = uint64_t;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int T; cin >> T;
    while ( T-- ) {
        ULL N, A, B, C, D;
        cin >> N >> A >> B >> C >> D;
        if ( (double)A / B > (double)C / D ) {
            swap(A, C);
            swap(B, D);
        }
        if ( N % B == 0 ) {
            cout << A * (N / B) << '\n';
            continue;
        }
        ULL x = N / B + 1;
        ULL min_c = A * x;
        for ( ULL y = 1; ; y++) {
            ULL n = N - D * y;
            x = n / B + (n % B ? 1 : 0);
            ULL c = C * y + A * x;
            if ( c < min_c )
                min_c = c;
            else
                break;
        }
        cout << min_c << '\n';
    }
}
