#include <stdio.h>
#define MAXN 1024

int counter[MAXN] = {0};

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    int t, s, wait_time = 0;
    for ( int i = 0; i < M; i++) {
        scanf("%d%d", &t, &s);
        int wait = 1, min = 1 << 20, min_i;
        for ( int j = 0; j < N; j++) {
            if ( counter[j] < min ) {
                min = counter[j];
                min_i = j;
            }
            if ( counter[j] <= t ) {
                counter[j] = t + s;
                wait = 0;
                break;
            }
        }
        if ( wait ) {
            wait_time += counter[min_i] - t;
            counter[min_i] += s;
        }
    }
    printf("%d", wait_time);
    return 0;
}