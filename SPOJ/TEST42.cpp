#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int x;
    bool done = false;
    while ( cin >> x ) {
        if ( x == 42 )
            done = true;
        if ( !done )
            cout << x << '\n';
    }
}
