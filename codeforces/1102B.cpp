#include <bits/stdc++.h>
#define MAXN 5000
#define MAXINT 5000

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int num[MAXN], cnt[MAXINT+1] = {0};
    if ( n <= k ) {
        puts("YES");
        for ( int i = 1; i <= n; i++)
            printf("%d%c", i, " \n"[i == n]);
        return 0;
    }
    int color[MAXN];
    vector<int*> ptr_list[MAXN+1];
    for ( int i = 0; i < n; i++) {
        cin >> num[i];
        cnt[num[i]]++;
        if ( cnt[num[i]] > k ) {
            puts("NO");
            return 0;
        }
        ptr_list[num[i]].push_back(&color[i]);
    }
    puts("YES");
    for ( int i = 1, x = 0; i <= MAXINT; i++)
        if ( ptr_list[i].size() != 0 )
            for ( int *ptr : ptr_list[i] )
                *ptr = x++ % k + 1;
    for ( int i = 0; i < n; i++)
        printf("%d%c", color[i], " \n"[i == n-1]);
    return 0;
}