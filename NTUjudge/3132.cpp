#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;

const int MAXN = 1e6+5;
const int MAXW = 1e9+7;

int n;
vector<int> A[2];

bool test(int m) {
    for ( int r = 0; r < 2; r++) {
        int prev = -1;
        for ( int i = 0; i < A[r].size(); i++) {
            if ( A[r][i] <= m )
                continue;
            if ( prev == -1 )
                prev = A[r][i];
            else if ( prev == A[r][i] )
                prev = -1;
            else
                return false;
        }
        if ( prev != -1 )
            return false;
    }
    return true;
}

int main()
{
    IOS;
    cin >> n;
    for ( int i = 0; i < 2; i++) {
        for ( int j = 0; j < n; j++) {
            int w; cin >> w;
            A[i].push_back(w);
        }
    }
    int64_t l = -1, r = 1e9;
    while ( r - l > 1 ) {
        int m = (l + r) >> 1;
        bool result = test(m);
        if ( result )
            r = m;
        else
            l = m;
    }
    cout << r << "\n";
    return 0;
}
