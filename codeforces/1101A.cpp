#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    int l, r, d;
    while (q--) {
        cin >> l >> r >> d;
        if ( d < l || d > r )
            cout << d << endl;
        else
            cout << d * (r / d + 1) << endl;
    }
    return 0;
}