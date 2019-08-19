#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;

bool test(int b, int g) {
    return (b >= g-1 && b <= 2*(g+1));
}

int main()
{
    IOS;
    int bl, br, gl, gr;
    cin >> gl >> gr >> bl >> br;
    if ( test(bl, gr) || test(br, gl) )
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
