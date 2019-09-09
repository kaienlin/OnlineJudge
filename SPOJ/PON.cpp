#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;

// utils
using u64 = uint64_t;
using u128 = __uint128_t;
u64 fpow(u64 a, u64 n, u64 M) {
    u64 ans = 1;
    a %= M;
    for (; n; n >>= 1) {
        if ( n & 1 ) ans = (u128)ans * a % M;
        a = (u128)a * a % M;
    }
    return ans;
}

// trivial
bool is_prime(u64 x) {
    for ( u64 d = 2; d * d <= x; d++)
        if ( x % d == 0 )
            return false;
    return true;
}

// fermat primality test ( probabilistic )
bool probably_is_prime(u64 n, int T=5) {
    if ( n < 4 )
        return n == 2 || n == 3;
    while ( T-- ) {
        u64 a = 2 + rand() % (n - 3);
        if ( fpow(a, n-1, n) != 1 )
            return false;
    }
    return true;
}

// Miller-Rabin primality test
bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = fpow(a, d, n);
    if ( x == 1 || x == n - 1 )
        return false;
    for ( int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};
bool miller_rabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;
    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
int main()
{
    IOS;
    int T; cin >> T;
    while ( T-- ) {
        u64 n; cin >> n;
        cout << (miller_rabin(n) ? "YES\n" : "NO\n");
    }
    return 0;
}
