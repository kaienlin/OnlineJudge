#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, h;
    int u[2], d[2];
    scanf("%d%d", &w, &h);
    scanf("%d%d%d%d", &u[0], &d[0], &u[1], &d[1]);
    for ( ;h > 0; h--) {
        w += h;
        if ( h == d[0] )
            w -= u[0];
        else if ( h == d[1] )
            w -= u[1];
        if ( w < 0 )
            w = 0;
    }
    printf("%d\n", w);
    return 0;
}