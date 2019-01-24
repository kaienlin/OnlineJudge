#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;
int N;

void disjoint(ULL club[], int K, ULL s, int p[], int i)
{
    if ( K == 0 ) {
        for ( int a = 0; a < 100; a++)
            if ( p[a] )
                printf("%d\n", a);
        exit(0);
    }
    if ( i >= N || N - i < K ) // If the number of the rest clubs is less than K, then it is impossible to achieve the condition.
        return;
    if ( !(club[i] & s) ) {
        p[i] = 1;
        disjoint(club, K - 1, s | club[i], p, i + 1);
    }
    p[i] = 0;
    disjoint(club, K, s, p, i + 1);
}

int main()
{
    int K;
    scanf("%d%d", &N, &K);
    ULL club[100] = {0};
    for ( int i = 0; i < N; i++) {
        int num, id;
        scanf("%d", &num);
        while (num--) {
            scanf("%d", &id);
            club[i] |= 1ULL << id;
        }
    }
    unsigned long long selected = 0ULL;
    int choosed[100] = {0};
    disjoint(club, K, selected, choosed, 0);
    return 0;
}