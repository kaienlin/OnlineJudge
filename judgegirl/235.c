#include <stdio.h>
#include <string.h>

// Hint: In order to prevent arithmetic overflow, you should reduce the denominator and numerator of each fractional number you use.

void reduct(int *a, int *b)
{   
    // 以輾轉相除法約分
    int tmpa = *a, tmpb = *b;
    while ( tmpa != 0 && tmpb != 0 ) {
        if ( tmpa > tmpb ) {
            tmpa -= tmpb;
        } else {
            tmpb -= tmpa;
        }
    }
    if ( tmpa != 0 ) {
        *a /= tmpa;
        *b /= tmpa;
    } else {
        *a /= tmpb;
        *b /= tmpb;
    }
}

int add_fractions(int nu1, int de1, int nu2, int de2, int or) {
    // 分數相加，先約分後計算以避免arithmetic overflow
    reduct( &nu1, &de1);
    reduct( &nu2, &de2);
    int numerator, denominator;
    numerator = nu1 * de2 + nu2 * de1;
    denominator = de1 * de2;
    reduct( &numerator, &denominator);
    if ( or == 0 ) {
        return numerator;
    } else {
        return denominator;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);

    if ( N == 0 ) {
        printf("1/1");
        return 0;
    } // The if statement was writed to pass the subtask2. It might be a bad idea, so I should seek for better answer for it.

    int chance[N][2][2]; // layer-1: pins, layer-2: left & right, layer-3: numerator & denominator
    int i, j;
    int l, r;
    int tmp1[2], tmp2[2], tmp3[2];
    memset(chance, 0, sizeof chance);

    for ( i = 0; i < N; i++) {
        for ( j = 0; j <= i; j++) {
            scanf("%d%d", &l, &r);
            reduct(&l, &r);
            if ( i == 0 ) {
                chance[0][0][0] = l;
                chance[0][0][1] = l + r;
                chance[0][1][0] = r;
                chance[0][1][1] = l + r;
            } else if ( j == 0 ) {
                tmp1[0] = chance[0][0][0];
                tmp1[1] = chance[0][0][1];
                chance[0][0][0] = tmp1[0] * l;
                chance[0][0][1] = tmp1[1] * ( l + r );
                tmp2[0] = chance[0][1][0];
                tmp2[1] = chance[0][1][1];
                chance[0][1][0] = tmp1[0] * r;
                chance[0][1][1] = tmp1[1] * ( l + r );
            } else if ( j == i ) {
                tmp1[0] = tmp2[0];
                tmp1[1] = tmp2[1];
                chance[i][0][0] = tmp1[0] * l;
                chance[i][0][1] = tmp1[1] * ( l + r );
                chance[i][1][0] = tmp1[0] * r;
                chance[i][1][1] = tmp1[1] * ( l + r );
            } else {
                tmp1[0] = tmp2[0];
                tmp1[1] = tmp2[1];
                tmp3[0] = chance[j][0][0];
                tmp3[1] = chance[j][0][1];
                chance[j][0][0] = add_fractions(tmp1[0], tmp1[1], tmp3[0], tmp3[1], 0) * l;
                chance[j][0][1] = add_fractions(tmp1[0], tmp1[1], tmp3[0], tmp3[1], 1) * ( l + r );
                tmp2[0] = chance[j][1][0];
                tmp2[1] = chance[j][1][1];
                chance[j][1][0] = add_fractions(tmp1[0], tmp1[1], tmp3[0], tmp3[1], 0) * r;
                chance[j][1][1] = add_fractions(tmp1[0], tmp1[1], tmp3[0], tmp3[1], 1) * ( l + r );
            }
        }
    }

    for ( i = 0; i <= N; i++) {
        if ( i == 0 ) {
            reduct(&chance[0][0][0], &chance[0][0][1]);
            printf("%d/%d\n", chance[0][0][0], chance[0][0][1]);
        } else if ( i == N ) {
            reduct(&chance[N-1][1][0], &chance[N-1][1][1]);
            printf("%d/%d\n", chance[N-1][1][0], chance[N-1][1][1]);
        } else {
            printf("%d/%d\n", add_fractions(chance[i-1][1][0], chance[i-1][1][1], chance[i][0][0], chance[i][0][1], 0), 
                              add_fractions(chance[i-1][1][0], chance[i-1][1][1], chance[i][0][0], chance[i][0][1], 1));
        }
    }

    return 0;
}
