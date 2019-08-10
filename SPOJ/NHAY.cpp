#include <bits/stdc++.h>

// ordinary string matching
// KMP demostration

using namespace std;

vector<int> get_pi(string s) {
	size_t n = s.size();
	vector<int> pi(n);
    pi[0] = 0;
	for ( int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while ( j > 0 && s[i] != s[j] )
			j = pi[j - 1];
		if ( s[i] == s[j] )
			j++;
		pi[i] = j;
	}
	return pi;
}

int match(string S, string t) {
	auto pi = get_pi(t);
	int sn = S.size(), tn = t.size(), ret = 0;
	for ( int i = 0, j = 0; i < sn; i++) {
		if ( S[i] == t[j] ) {
			++j;
			if ( j == tn ) {
                cout << i-tn+1 << '\n';
                ++ret;
            }
		} else {
			if ( j > 0 ) {
				j = pi[j - 1];
				--i;
			}
		}
	}
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    string t, p;
    int n;
    while ( cin >> n >> p >> t ) {
        int r = match(t, p);
        if ( !r ) cout << '\n';
    }
}
