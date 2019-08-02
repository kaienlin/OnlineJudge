#include <bits/stdc++.h>
#define MAXN 20000000
#define ULL uint64_t 
using namespace std;

ULL A[MAXN];
ULL mass, moment;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for ( int i = 0; i < N; i++) {
        cin >> A[i];
        mass += A[i];
        moment += i * A[i];
    }
    int x, xMax = max(1, N/2);
    for ( x = 1; moment % mass; ++x) {
        int pos = x-1;
        moment -= A[pos] * pos + A[N - 1 - pos] * (N - 1 - pos); // if using int, overflow can happen in this part of multiplicatoin!
        moment += A[pos] * (N - 1 - pos) + A[N - 1 - pos] * pos;
    }
    cout << x-1 << ' ' << moment / mass << '\n';
    return 0;
}
