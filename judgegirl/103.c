#include <stdio.h>
 
int main(void)
{
    int n;
    scanf("%d", &n);
    double A[n][n];
    double x[n];
    double y[n];
    int i, j;
    double tmp;
 
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
    for ( i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }
 
    x[n-1] = y[n-1] / A[n-1][n-1];
 
    for ( i = n - 2; i >= 0; i--) {
        tmp = y[i];
        for ( j = n - 1; j >= i; j--) {
            tmp -= A[i][j] * x[j];
        }
        x[i] = tmp / A[i][i];
    }
 
    for ( i = 0; i < n; i++) {
        printf("%f\n", x[i]);
    }
 
    return 0;
}
