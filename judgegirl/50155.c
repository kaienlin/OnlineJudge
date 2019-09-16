#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main()
{
    int a, b, c, d, e, f, g, ans;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    int V = a * b * d, A1 = (a * b - e * f), A2 = a * b;
    if ( V == 0 )
        ans = 0;
    else if ( A1 == 0 ) {
        if ( g >= c )
            ans = 0;
        else
            ans = min(c, g + V / A2);
    } else {
        int dep1 = V / A1;
        if ( dep1 <= g )
            ans = min(c, dep1);
        else {
            if ( g >= c )
                ans = c;
            else
                ans = min(c, g + (V - g * A1) / A2);
        }
    }
    printf("%d\n", ans);
}
