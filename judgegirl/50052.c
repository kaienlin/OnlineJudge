#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* Read description as CAREFULLY as possible! The problem requires you to sort the result! */

int dist(const char *a, const char *b, int L)
{
    int d = 0;
    for ( int i = 0; i < L; i++) {
        d += abs((int)a[i] - (int)b[i]);
    }
    return d;
}

int dist_i(const int *a, const char *b, int L)
{
    int d = 0;
    for ( int i = 0; i < L; i++) {
        d += abs(a[i] - (int)b[i]);
    }
    return d;
}

int group(int l[], int index, char pool[64][16], int L)
{
    int min = 999999999, m;
    for ( int i = 0; i < 3; i++) {
        int d = dist(pool[ l[i] ], pool[index], L);
        if ( d < min || d == min && strcmp(pool[ l[i] ], pool[l[m]]) < 0 ) {
            min = d;
            m = i;
        }
    }
    return m;
}

int cmp(const void *a, const void *b)
{
    return strcmp((char*)a, (char*)b);
}

int main()
{
    int N, L, R;
    scanf("%d%d%d", &N, &L, &R);
    int leader[3] = {0, 1, 2};
    int member[3][64];
    char pool[64][16];
    for ( int i = 0; i < N; i++) {
        scanf("%s", pool[i]);
    }
    int count[3], sum[3][L], mean[3][L];
    while (R--) {
        memset(sum, 0, sizeof(sum));
        memset(count, 0, sizeof(count));
        for ( int i = 0; i < N; i++) {
            if ( i != leader[0] || i != leader[1] || i != leader[2]) {
                int g = group(leader, i, pool, L);
                member[g][count[g]] = i;
                count[g]++;
                for ( int k = 0; k < L; k++) {
                    sum[g][k] += (int)pool[i][k];
                }
            }
        }
        for ( int i = 0; i < 3; i++) {
            for ( int j = 0; j < L; j++) {
                mean[i][j] = sum[i][j] / count[i];
            } // calculate mean value
            int min = 999999999, m = 0, d;
            for ( int j = 0; j < count[i]; j++) {
                d = dist_i(mean[i], pool[member[i][j]], L);
                if ( d < min || d == min && strcmp(pool[member[i][j]], pool[m]) < 0 ) {
                    min = d;
                    m = member[i][j];
                }
            }
            d = dist_i(mean[i], pool[leader[i]], L);
            if ( d < min || d == min && strcmp(pool[leader[i]], pool[m]) < 0 ) {
                min = d;
                m = leader[i];
            }
            leader[i] = m;
        }
    }
    char result[3][16];
    for ( int i = 0; i < 3; i++) {
        strcpy(result[i], pool[leader[i]]);
    }
    qsort(result, 3, sizeof(char)*16, cmp);
    for ( int i = 0; i < 3; i++) {
        printf("%s\n", result[i]);
    }
    return 0;
}