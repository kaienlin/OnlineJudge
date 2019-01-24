#include <stdio.h>
#include <stdlib.h>
#define MAXN 50000

int A[MAXN][2], B[MAXN][2];

int main()
{
    int N;
    scanf("%d", &N);
    int Acnt = 0, Bcnt = 0, min, d;
    while (N--) {
        scanf("%d%d", &A[Acnt][0], &A[Acnt][1]);
        if ( Acnt != 0 ) {
            min = __INT_MAX__;
            for ( int i = 0; i < Bcnt; i++) {
                d = abs(A[Acnt][0] - B[i][0]) + abs(A[Acnt][1] - B[i][1]);
                min = d < min ? d : min;
            }
            printf("%d\n", min);
        }
        Acnt++;
        scanf("%d%d", &B[Bcnt][0], &B[Bcnt][1]);
        min = __INT_MAX__;
        for ( int i = 0; i < Acnt; i++) {
            d = abs(B[Bcnt][0] - A[i][0]) + abs(B[Bcnt][1] - A[i][1]);
            min = d < min ? d : min;
        }
        printf("%d\n", min);
        Bcnt++;
    }
    return 0;
}