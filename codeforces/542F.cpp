#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;
using pii = pair<int, int>;

const int MAXN = 105;
vector<int> arr[MAXN];

int main()
{
    IOS;
    int n, T; cin >> n >> T;
    for ( int i = 0; i < n; i++) {
        int t, q; cin >> t >> q;
        arr[t].push_back(q);
    }
    for ( int t = 1; t < T; t++) {
        if ( arr[t].size() ) {
            sort(arr[t].begin(), arr[t].end(), greater<int>());
            for ( int j = 0; j < arr[t].size(); j+=2) {
                if ( j == arr[t].size()-1 )
                    arr[t+1].push_back(arr[t][j]);
                else
                    arr[t+1].push_back(arr[t][j] + arr[t][j+1]);
            }
        }
    }
    cout << *max_element(arr[T].begin(), arr[T].end()) << '\n';
    return 0;
}
