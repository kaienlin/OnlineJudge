#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;

void rev(string &s) {
    int n = s.size();
    for ( int i = 0; i < n / 2; i++)
        swap(s[i], s[n-1-i]);
}

int main()
{
    IOS;
    int N; cin >> N;
    while ( N-- ) {
        string a, b; cin >> a >> b;
        rev(a); rev(b);
        int sum = stoi(a) + stoi(b);
        string ans = to_string(sum);
        rev(ans);
        cout << stoi(ans) << '\n';
    }
}
