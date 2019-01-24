#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int k = sqrt(n);
    int r = n - k * k;
    if ( r == 0 )
        printf("%d\n", 2 * k);
    else if ( r <= k )
        printf("%d\n", 2 * k + 1);
    else
        printf("%d\n", 2 * k + 2);
    return 0;
}