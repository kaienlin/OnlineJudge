#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y, a;
    scanf("%d %d %d", &n, &x, &y);
    if ( x > y ) {
        printf("%d\n", n);
        return 0;
    }
    int cnt = 0;
    while (n--) {
        scanf("%d", &a);
        if ( a <= x )
            cnt++;
    }
    printf("%d\n", cnt / 2 + cnt % 2 );
    return 0;
}