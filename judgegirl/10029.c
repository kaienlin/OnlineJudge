#include <stdio.h>
#include <stdlib.h>

void row_minus(double x[], double y[], int M)
{
    for ( int i = 0; i <= M; i++)
        y[i] -= x[i];
}

int cmp(const void *a, const void *b)
{
    double *x = (double*)a;
    double *y = (double*)b;
    int cnt = 0;
    while (cnt < 101) {
        if ( *x == *y ) {
            x++;
            y++;
            cnt++;
        } else {
            return (int)(*y - *x);
        }
    }
}

void print_e(double e[][101], int N, int M)
{
    for ( int i = 0; i < N; i++) {
        for ( int j = 0; j <= M; j++) {
            printf("%.1lf ", e[i][j]);
        }
        puts("");
    }
}

int main()
{
    int N, M;
    double equation[100][101];
    int toSolve[100], x;
    while ( scanf("%d%d", &N, &M) != EOF ) {
        for ( int i = 0; i < N; i++) {
            for ( int j = 0; j <= M; j++) {
                scanf("%d", &x);
                equation[i][j] = (double)x;
            }
        }
        for ( int i = 0; i <= M; i++)
            scanf("%d", &toSolve[i]);
        qsort(equation, N, sizeof(equation[0]), cmp);
        print_e(equation, N, M);
        for ( int i = 0; i < N - 1; i++) {
            for ( int j = i + 1; j < N; j++) {
                if ( equation[j][i] != 0 ) {
                    row_minus(equation[i], equation[j], M);
                }
            }
        }
        print_e(equation, N, M);
    }
    return 0;
}