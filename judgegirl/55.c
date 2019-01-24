#include <stdio.h>

// I spend too much time!!!
// What I don't note: 1. integer overflow
//                    2. t % (e1 + n1) may == 0
//                    3. the rule of magic move is moving to the other side as soon as robots bump the wall

int main(void)
{
    int m, n;
    long long int x1, y1, e1, n1, f1;
    long long int x2, y2, e2, n2, f2;
    int explode = 0;
    scanf("%d%d%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld", &m, &n, &x1, &y1, &e1, &n1, &f1, &x2, &y2, &e2, &n2, &f2);

    int t;
    for ( t = 1; f1 > 0 || f2 > 0; f1--, f2--, t++) {
        // walk 1 step
        if ( f1 > 0 ) {
            if ( t % (e1 + n1) <= n1 && t % (e1 + n1) != 0) {
                y1++;
            } else {
                x1++;
            }
        }
        if ( f2 > 0 ) {
            if ( t % (e2 + n2) <= e2 && t % (e2 + n2) != 0) {
                x2++;
            } else {
                y2++;
            }
        }

        // deal with magic move when "out of bound"
        if ( x1 == m ) x1 = 0;
        if ( y1 == n ) y1 = 0;

        if ( x2 == m ) x2 = 0;
        if ( y2 == n ) y2 = 0; 

        // when robots meet and explode
        if ( x1 == x2 && y1 == y2 ) {
            explode = 1;
            break;
        }  
    }

    if ( !explode ) {
        printf("robots will not explode\n");
    } else {
        printf("robots explode at time %d\n", t);
    }

    return 0;
}
