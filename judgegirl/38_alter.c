#include <stdio.h>

int lotion(int D, int a, int b, int c, int A, int B, int C, int o)
{
    if ( D == 0 ) {return 1;}
    if ( D < 0 ) {return 0;}
    if ( o == 0 ) {
        if ( A != 0 && D % A == 0 && D / A <= a ) {
            return 1;
        } else {
            int flag = 0;
            while ( D >= 0 && a >= 0 ) {
                flag += lotion(D, a, b, c, A, B, C, 1);
                a--;
                D -= A;
            }
            if ( flag ) { return 1;}
            return 0;
        }
    } else if ( o == 1 ) {
        if ( B != 0 && D % B == 0 && D / B <= b ) {
            return 1;
        } else {
            int flag = 0;
            while ( D >= 0 && b >= 0 ) {
                flag += lotion(D, a, b, c, A, B, C, 2);
                b--;
                D -= B;
            }
            if ( flag ) { return 1;}
            return 0;
        }
    } else if ( o == 2 ) {
        if ( C != 0 && D % C == 0 && D / C <= c ) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    while (N--) {
        int D, a, b, c, A, B, C;
        scanf("%d%d%d%d%d%d%d", &D, &a, &b, &c, &A, &B, &C);
        if ( lotion(D, a, b, c, A, B, C, 0) ) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}