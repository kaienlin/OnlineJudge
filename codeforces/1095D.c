#include <stdio.h>
#include <string.h>
#define SWAP(x, y) (x ^= y ^= x ^= y)
#define MAXN 200000

int order[MAXN + 1] = {0, 1};
int rule[MAXN + 1][2];

int main()
{
    int N;
    scanf("%d", &N);
    for ( int i = 1; i <= N; i++)
        scanf("%d%d", &rule[i][0], &rule[i][1]);
    memset(order, 0, sizeof(order));
    order[1] = 1;
    for ( int i = 1; i <= N - 2; i += 2) {
        order[i+1] = rule[order[i]][0];
        order[i+2] = rule[order[i]][1];
        if ( rule[order[i+1]][0] != order[i+2] && rule[order[i+1]][1] != order[i+2] )
            SWAP(order[i+1], order[i+2]);
    }
    if ( order[N] == 0 ) {
        order[N] = rule[order[N-1]][ rule[order[N-1]][0] == 1 ? 1 : 0 ];
    }
    for ( int i = 1; i <= N; i++)
        printf("%d%c", order[i], " \n"[i == N]);
}