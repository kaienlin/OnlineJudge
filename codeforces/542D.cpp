#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;
using pii = pair<int, int>;

const LL MAXA = 1e12, MAXP = 1e6;

vector<LL> prime;  // primes <= MAXP(1e6)
bool mark[MAXP+55];
void sieve(int ub) {
    for ( LL p = 2; p * p <= ub; p++) {
        if ( !mark[p] ) {
            for ( LL i = p+p; i <= ub; i += p)
                mark[i] = true;
        }
    }
    for ( int i = 2; i <= ub; i++)
        if ( !mark[i] )
            prime.push_back(i);
}
bool is_prime(LL x) {
    for ( LL v : prime ) {
        if ( v * v > x ) break;
        if ( x % v == 0 ) return false;
    }
    return true;
}
unordered_map<LL, LL> ppow_plus_1;
void preprocess() {
    sieve(MAXP);
    for ( LL p : prime )
        for ( LL ppow = p; ppow <= MAXA; ppow *= p)
            ppow_plus_1[ppow+1] = p;
}
vector<LL> fac;
void find_factors(LL n) {
    for ( LL i = 1; i * i <= n; i++) {
        if ( n % i == 0 ) {
            fac.push_back(i);
            if ( n / i != i )
                fac.push_back(n / i);
        }
    }
    sort(fac.rbegin(), fac.rend());
}
LL test(LL x) {
    auto it = ppow_plus_1.find(x);
    if ( it != ppow_plus_1.end() )
        return it->second;
    return (x >= MAXP && is_prime(x-1)) ? x-1 : 0;
}

map<LL, vector<LL> > mp;
unordered_map<LL, LL> dp;

int main()
{
    IOS;
	preprocess();

	LL A; cin >> A;
    find_factors(A);
    for ( LL x : fac ) {
        LL p = test(x);  // test if x = p ^ k + 1
        if ( p )
            mp[p].push_back(x);
    }
    
    dp[1] = 1;
    for ( auto it : mp ) {
        for ( LL f : fac ) {
            for ( LL x : it.second ) {
                if ( f % x == 0 )
                    dp[f] += dp[f / x];
            }
        }
    }
    cout << dp[A] << '\n';
	return 0;
}
