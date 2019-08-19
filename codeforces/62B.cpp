#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;

const int MAXN = 1e5+5;
const int MAXK = 1e5+5;
const int MAXL = 2e5+5;

int n, k;
string u, v;

int d[26][MAXL];

void preprocess() {
    deque<int> dq[26];
    for ( int c = 0; c < 26; c++)
        dq[c].push_back(-1);
    for ( int i = 0; i < k; i++)
        dq[ u[i] - 'a' ].push_back(i);
    for ( int c = 0; c < 26; c++)
        dq[c].push_back(MAXL);
    for ( int i = 0; i < MAXL; i++) {
        for ( int c = 0; c < 26; c++)
            if ( dq[c][1] < i )
                dq[c].pop_front();
        for ( int c = 0; c < 26; c++) {
            int ans = INT_MAX;
            if ( dq[c][0] != -1 )
                ans = min(ans, i - dq[c][0]);
            if ( dq[c][1] != MAXL )
                ans = min(ans, dq[c][1] - i);
            d[c][i] = ans;
        }
    }
}

int main()
{
    IOS;
    cin >> n >> k;
    cin >> u;
    preprocess();
    while ( n-- ) {
        cin >> v;
        int64_t ans = 0;
        for ( int i = 0; i < v.size(); i++) {
            if ( d[v[i]-'a'][i] == INT_MAX )
                ans += v.size();
            else
                ans += d[v[i]-'a'][i];
        }
        cout << ans << '\n';
    }
    return 0;
}
