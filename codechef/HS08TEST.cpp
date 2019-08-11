#include <cstdio>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;

int main()
{
    int x; scanf("%d", &x);
    double y; scanf("%lf", &y);
    if ( x % 5 == 0 && y - 0.5 >= x )
        y -= (double)x + 0.5;
    printf("%.2lf\n", y);
}
