#include <stdio.h>

/* I have a difficultity solving this problem mainly because : 1. arithmetic overflow
                                                               2. unexpected behavior on "(long long)a * A + b * B + c * C >= D"
                                                               3. not consider the situation which A or B or C may equal to zero
   I should put more effort on recursion.
*/

int a, b, c;

int lotion(int D, int m, int n, int o, int A, int B, int C)
{   
    if ( m < 0 || n < 0 || o < 0 || ( A > D && B > D && C > D && D != 0 )) {
        return 0;
    } else if ( A == 0 && B == 0 && C == 0 ) {
        if ( D == 0 ) {
            return 1; 
        } else {
            return 0;
        }
    } else if ( C == 0 && B == 0 ) {
        if ( D % A == 0 && D / A <= a && D / A >= 0 ) {
            return 1;
        } else if ( (long long)m * A < (long long)D ) {
            return 0;
        } else {
            return lotion(D, m - 1, n, o, A, B, C);
        }
    } else if ( C == 0 ) {
        if ((D - (long long)m * A) % B == 0 && (D - (long long)m * A) / B <= b && (D - (long long)m * A) / B >= 0 ) {
            return 1;
        } else if ( m < 0 || (long long)m * A + (long long)n * B < (long long)D ) {
            return 0;
        } else {
            return lotion(D, m - 1, n, o, A, B, C);
        }
    } else {
        if ( ((long long)D - (long long)m * A - (long long)n * B) % (long long)C == 0LL && ((long long)D - (long long)m * A - (long long)n * B) / (long long)C <= (long long)c && ((long long)D - (long long)m * A - (long long)n * B) / (long long)C >= 0LL ) {
            return 1;
        } else if ( (long long)m * A + (long long)n * B + (long long)o * C < (long long)D ) {
            return 0;
        } else {
            return lotion(D, m - 1, n, o, A, B, C) || lotion(D, m, n - 1, o, A, B, C);
        }
    }
}

int main()
{
    int N;
    int A, B, C, D;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d%d%d%d%d%d%d", &D, &a, &b, &c, &A, &B, &C);
        if ( lotion(D, a, b, c, A, B, C) ) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}