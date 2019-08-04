#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using ULL = uint64_t;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T; cin >> T;
    while ( T-- ) {
        int N; cin >> N;
        priority_queue<ULL, vector<ULL>, greater<ULL>> pq;
        for ( int i = 0; i < N; i++) {
            ULL x; cin >> x;
            pq.push(x);
        }
        ULL ans = 0;
        for ( int i = 1; i <= N-1; i++) {
            ULL a = pq.top(); pq.pop();
            ULL b = pq.top(); pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        cout << ans << '\n';
    }
}
