#include <bits/stdc++.h>

using namespace std;

void bye() {
    puts("-1");
    exit(0);
}

int main()
{
    string s;
    cin >> s;
    char begin[2] = {'[', ':'};
    char end[2] = {']', ':'};
    auto len = s.size();
    int l = -1, r = -1;
    for ( int i = 0, x = 0; i < len; i++) {
        if ( s[i] == begin[x] ) {
            x++;
            if ( x == 2 )
                l = i;
        }
    }
    if ( l == -1 ) bye();
    for ( int i = len - 1, x = 0; i >= 0; i--) {
        if ( s[i] == end[x] ) {
            x++;
            if ( x == 2 )
                r = i;
        }
    }
    if ( r == -1 || l >= r ) bye();
    int cnt = 4;
    for ( int i = l + 1; i < r; i++)
        if ( s[i] == '|' )
            cnt++;
    cout << cnt << endl;
    return 0;
}