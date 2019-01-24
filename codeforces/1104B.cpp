#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	stack<char> stk;
	int cnt = 0;
	for ( auto c : s ) {
		if ( !stk.empty() && c == stk.top() ) {
			stk.pop();
			cnt++;
		} else {
			stk.push(c);
		}
	}
	puts(cnt & 1 ? "Yes" : "No");
	return 0;
}
