#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long x = n * 1LL * (n+1) / 2;
    cout << (x & 1) << endl;
    return 0;
}