#include <stdio.h>
#include <string.h>
#define MAXN 1024
#define MAXM 512
#define T 0.8

typedef struct bitset {
    unsigned long long bits[8];
} Bitset;

int main()
{
    int N, M;
    Bitset set[MAXN];
    char line[MAXM + 1];
    while ( scanf("%d%d", &N, &M) != EOF ) {
        memset(set, 0, sizeof(set));
        for ( int i = 0; i < N; i++) {
            scanf("%s", line);
            for ( int j = 0; j < M; j++) {
                if ( line[j] - '0' )
                    set[i].bits[j / 64] |= 1ULL << (j % 64); // mistake for set[i].bits[j / M] |= 1ULL << (j % M);
            }
        }
        int S = 0, uni, same;
        int q = (M-1) / 64;
        for ( int i = 0; i < N; i++) {
            for ( int j = i + 1; j < N; j++) {
                uni = same = 0;
                for ( int a = 0; a <= q; a++) {
                    uni += __builtin_popcountll(set[i].bits[a] | set[j].bits[a]);
                    same += __builtin_popcountll(set[i].bits[a] & set[j].bits[a]);
                }
                if ( (double)same / (double)uni >= T ) {
                    S++;
                }
            }
        }
        int d = N * (N - 1)/2;
        printf("%.2lf\n", S / (double)d * 100.0);
    }
    return 0;
}