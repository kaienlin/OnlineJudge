#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;
using pii = pair<int, int>;

const int MAXM = 101;

void get_pi(string &s, vector<int> &pi) {
	size_t n = s.size();
	pi.resize(n);
    pi[0] = 0;
	for ( int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while ( j > 0 && s[i] != s[j] )
			j = pi[j - 1];
		if ( s[i] == s[j] )
			j++;
		pi[i] = j;
	}
}

bool match(string &S, string &t, vector<int> &pi) {
	int sn = S.size(), tn = t.size();
	for ( int i = 0, j = 0; i < sn; i++) {
		if ( S[i] == t[j] ) {
			++j;
			if ( j == tn )
				return true;
		} else {
			if ( j > 0 ) {
				j = pi[j - 1];
				--i;
			}		
		}
	}
	return false;
}

string S, pattern;
string rot[26];
vector<int> rot_pi[26];

void prepare() {
    for ( int k = 0; k < 26; k++) {
        rot[k] = S;
        for ( char &c : rot[k] )
            c = (c - 'A' + k) % 26 + 'A';
        get_pi(rot[k], rot_pi[k]);
    }
}
bool match_all() {
    for ( int k = 0; k < 26; k++) {
        if ( match(pattern, rot[k], rot_pi[k]) )
            return true;
    }
    return false;
}

int main()
{
    IOS;
    int T; cin >> T;
    while ( T-- ) {
        int N; cin >> N >> S;
        prepare();
        int M; cin >> M;
        for ( int i = 0; i < M; i++) {
            int L; cin >> L >> pattern;
            if ( match_all() )
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
    return 0;
}
