#include <stdio.h>
#include <string.h>
int N, M, seat[16], min_seat[16], min = __INT_MAX__;
int friend[16][16];

void dist(int idx, int max_d) {
    if ( max_d >= min )
        return;
    if ( idx == N ) {
        memcpy(min_seat, seat, sizeof(min_seat));
        min = max_d;
        return;
    }
    for ( int i = 0; i < N; i++) {
        if ( seat[i] < 0 ) {
            seat[i] = idx;
            for ( int j = 0; j < N; j++)
                if ( friend[i][j] && seat[j] >= 0 && idx - seat[j] > max_d )
                    max_d = idx - seat[j];
            dist(idx+1, max_d);
            seat[i] = -1;
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    char str0[2], str1[2];
    for ( int i = 0; i < M; i++) {
        scanf("%s%s", str0, str1);
        friend[str0[0] - 'A'][str1[0] - 'A'] = 1;
        friend[str1[0] - 'A'][str0[0] - 'A'] = 1;
    }
    for ( int i = 0; i < N; i++)
        seat[i] = -1;
    dist(0, 0);
    printf("%d\n", min);
    for ( int i = 0; i < N; i++)
        for ( int j = 0; j < N; j++)
            if ( min_seat[j] == i )
                printf("%c%c", j + 'A', " \n"[i == N-1]);
    return 0;
}