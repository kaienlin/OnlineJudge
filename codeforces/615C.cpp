#include <bits/stdc++.h>
#define MAXL 2500

using namespace std;

string s, t;
int slen, tlen;
int lcs[MAXL][MAXL], rev_lcs[MAXL][MAXL];

void build_lcs() {
    for ( int i = tlen; i >= 1; i--) {
        for ( int j = slen; j >= 1; j--)
            if ( t[i] == s[j] )
                lcs[i][j] = lcs[i+1][j+1] + 1;
        for ( int j = 1; j <= slen; j++)
            if ( t[i] == s[j] )
                rev_lcs[i][j] = rev_lcs[i+1][j-1] + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s >> t;
    slen = s.size(), tlen = t.size();
    s = "^" + s + "$";  // By adding these characters, we can avoid considering boundary cases when filling the table.
    t = "*" + t + "#";
    build_lcs();
    vector< pair<int, int> > ans;
    for ( int i = 1; i <= tlen;) {
        int p = max_element(lcs[i] + 1, lcs[i] + slen + 1) - lcs[i];
        int rp = max_element(rev_lcs[i] + 1, rev_lcs[i] + slen + 1) - rev_lcs[i];
        int len = max(lcs[i][p], rev_lcs[i][rp]);
        if ( len == 0 ) {
            cout << "-1" << '\n';
            return 0;
        }
        if ( len == lcs[i][p] )
            ans.push_back( {p, p + len - 1} );
        else
            ans.push_back( {rp, rp - len + 1} );
        i += len;
    }
    cout << ans.size() << '\n';
    for ( auto e : ans )
        cout << e.first << ' ' << e.second << '\n';
}
