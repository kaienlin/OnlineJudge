#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

string dp[2][101][10000];
string empty = "";

string solve(string s, int m, bool turn) {
    if ( m == 0 ) return s;
    int num = stoi(s);
    if ( dp[turn][m][num] != empty ) return dp[turn][m][num];
    string ret = turn ? "0000" : "9999";
    for ( int i = 0; i < 4; i++) {
        string t = s;
        t[i]++;
        if ( t[i] > '9' )
            t[i] = '0';
        t = solve(t, m-1, !turn);
        if ( turn ) {
            if ( t > ret )
                ret = t;
        } else {
            if ( t < ret )
                ret = t;
        }
    }
    return dp[turn][m][num] = ret;
}

int main()
{
    IOS;
    int T; cin >> T;
    while ( T-- ) {
        string S;
        int M;
        cin >> S >> M;
        string r = solve(S, M, 1);
        if ( r > S )
            cout << "Ada\n";
        else
            cout << "Vinit\n";
    }
    return 0;
}
