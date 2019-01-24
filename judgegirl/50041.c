#include <stdio.h>
 
int main(void)
{
    int n;
    scanf("%d", &n);
 
    int i;
    int h;
    int prev_s = 0; // 0 represents downhill, 1 represents uphill
    int prev_h;
    int cost = 0;
 
    for ( i = 0; i < n; i++) {
        scanf("%d", &h);
        if ( i == 0 ) {
            prev_h = h;
            continue;
        }
        if ( prev_s == 0 ) {
            if ( h > prev_h ) {
                cost += ( h - prev_h ) * 3;
                prev_h = h;
                prev_s = 1;
            } else {
                cost += ( prev_h - h ) * 2;
                prev_s = 0;
                prev_h = h;
            }
        } else {
            if ( h > prev_h ) {
                cost += ( h - prev_h ) * 4;
                prev_s = 1;
                prev_h = h;
            } else {
                cost += ( prev_h - h ) * 3;
                prev_s = 0;
                prev_h = h;
            }
        }
    }
 
    printf("%d", cost);
 
    return 0;
}
