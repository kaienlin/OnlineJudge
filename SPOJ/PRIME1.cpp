#include <bits/stdc++.h>

using namespace std;

constexpr int MXR = 1e9+5;
const int SR = floor(sqrt(MXR))+1;

bool mark[100005];  // false: prime
vector<int> prime;

void simple_sieve(int ub) {
    for ( int p = 2; p * p <= ub; p++) {
        if ( !mark[p] ) {
            for ( int i = p+p; i <= ub; i += p)
                mark[i] = true;
        }
    }
    for ( int i = 2; i <= ub; i++)
        if ( !mark[i] )
            prime.push_back(i);
}

// R - L <= 100000
void segmented_sieve(int L, int R) {
    memset(mark, 0, sizeof(mark));
    for ( int p : prime ) {
        int lb = L / p * p;  // the first number >= L that is a multiple of p
        if ( lb < L ) lb += p;
        for ( int i = lb <= p ? 2*p : lb; i <= R; i += p)
            mark[i - L] = true;
    }
    for ( int i = max(2, L); i <= R; i++)
        if ( !mark[i-L] )
            cout << i << '\n';
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    simple_sieve(SR);
    int T; cin >> T;
    while ( T-- ) {
        int L, R; cin >> L >> R;
        segmented_sieve(L, R);
        if ( T ) cout << '\n';
    }
}
