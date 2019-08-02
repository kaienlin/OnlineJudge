#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define MAXN 1000000

using namespace std;
using LL = long long;

LL A[MAXN], B[MAXN], C[MAXN];

inline LL MAX(LL a, LL b) { return a > b ? a : b; }
inline LL MAX(LL a, LL b, LL c) { return MAX(a, MAX(b, c)); }

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N;
    cin >> N;
    for ( int i = 0; i < N; i++)
        cin >> A[i];
    B[0] = A[0];
    for ( int i = 1; i < N; i++)
        B[i] = MAX(A[i], B[i-1], B[i-1] + A[i]);
    C[2] = A[0] + A[2];
    for ( int i = 3; i < N; i++)
        C[i] = MAX(C[i-1], B[i-2]) + A[i];
    cout << *max_element(C+2, C+N) << '\n';
}
