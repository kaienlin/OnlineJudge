#include <stdio.h>

/*如果用沒經過優化的輾轉相除法會TLE*/
/* Change note: use recursion method */

int find_gcd(int x, int y)
{   
    if ( x % y == 0 ) {return y;}
    else {
        return find_gcd(y, x % y);
    }
}
 
int main()
{
    int a, b;
    int gcd;
    while ( scanf("%d%d", &a, &b) != EOF ) {
        if ( a == 0 || b == 0 ) {
            printf("0 / 1\n");
            continue;
        }
        gcd = find_gcd(a > b ? a : b, a < b ? a : b);
        printf("%d / %d\n", a / gcd, b / gcd);
    }
    return 0;
}