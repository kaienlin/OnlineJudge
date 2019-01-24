#include <stdio.h>
#define MAXN 100005

int A[MAXN];

int main() {
    int n, i;
    while (scanf("%d", &n) == 1) {
        for (i = 0; i < n; i++)
            scanf("%d", &A[i]);
        int count = 0;
        for ( int i = 0; i < n; i++) {
            if ( A[i] != 0 ) {
                A[count++] = A[i];
            }
        }
        for ( int i = count; i < n; i++) {
            A[i] = 0;
        }
        for (i = 0; i < n; i++)
            printf("%d%c", A[i], " \n"[i==n-1]);
    }
    return 0;
}