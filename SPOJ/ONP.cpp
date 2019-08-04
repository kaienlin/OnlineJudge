#include <bits/stdc++.h>

using namespace std;

int mp[128];
void init() {
    mp['+'] = 0; mp[0] = '+';
    mp['-'] = 1; mp[1] = '-';
    mp['*'] = 2; mp[2] = '*';
    mp['/'] = 3; mp[3] = '/';
    mp['^'] = 4; mp[4] = '^';
    mp['('] = 5;
}
void trans(string s) {
    stack<int> st;
    for ( char c : s ) {
        if ( c >= 'a' && c <= 'z' ) {
            cout << c;
        } else if ( c == ')' ) {
            while ( st.top() != 5 )
                cout << (char)mp[st.top()], st.pop();
            if ( st.top() == 5 ) st.pop();
        } else if ( c == '(' ) {
            st.push(mp['(']);
        } else {
            int pri = mp[c];
            while ( !st.empty() && st.top() != 5 && st.top() >= pri )
                cout << (char)mp[st.top()], st.pop();
            st.push(pri);
        }
    }
    while ( !st.empty() )
        cout << (char)mp[st.top()], st.pop();
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    init();
    int T; cin >> T;
    while ( T-- ) {
        string s; cin >> s;
        trans(s);
        cout << '\n';
    }
}
