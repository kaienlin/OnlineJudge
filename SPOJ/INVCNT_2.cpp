#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> RBTree;

constexpr int MAXVAL = 1e7+5, MAXN = 2e5+5;

int N;
int A[MAXN];

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T; cin >> T;
    while ( T-- ) {
        cin >> N;
        for ( int i = 1; i <= N; i++)
            cin >> A[i];
        RBTree t;
        uint64_t ans = 0;  // be careful of overflow...
        for ( int i = N; i >= 1; i--) {
            ans += t.order_of_key(A[i]);
            t.insert(A[i]);
        }
        cout << ans << '\n';
    }
}
