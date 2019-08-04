#include <bits/stdc++.h>

using namespace std;

constexpr int Max_n = 10000000;

int num[Max_n+1];

void preprocess()
{
    for ( int i = 1; i * i <= Max_n; i++)
        for ( int j = i; i * j <= Max_n; j++)
            num[i * j]++;
    for ( int i = 1; i <= Max_n; i++)
        num[i] += num[i-1];
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    preprocess();
    int T; cin >> T;
    while ( T-- ) {
        int n; cin >> n;
        cout << num[n] << '\n';
    }
}
