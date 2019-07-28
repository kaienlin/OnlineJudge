#include <bits/stdc++.h>

using namespace std;
using ULL = uint64_t;

constexpr int MAXN = 1e4 + 5;
constexpr ULL Mod = 1e9 + 7, x = 10069;

int N, K, A[MAXN];
int start[MAXN];  // for every R

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    while ( cin >> N >> K ) {
        for ( int i = 0; i < N; i++)
            cin >> A[i];
        for ( int L = 0, R = 0, cnt = 0; R < N; R++) {
            cnt += (A[R] & 1);
            while ( cnt > K )
                cnt -= (A[L++] & 1);
            start[R] = L;
        }
        unordered_set<ULL> S;
        ULL ans = 0;
        for ( int R = 0; R < N; R++) {
            int L = start[R];
            ULL hv = 0;
            for ( int M = R; M >= L; M--) {
                hv = (hv * x % Mod + A[M]) % Mod;
                auto r = S.insert(hv);
                ans += (int)(r.second);
            }
        }
        cout << ans << '\n';
    }
}
