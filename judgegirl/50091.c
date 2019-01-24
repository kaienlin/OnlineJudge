#include <stdlib.h>

int ***constructTable(int A[], int B[])
{
    int n = 0;
    while ( A[n] != 0 ) {
        n++;
    }
    n++;
    int ***first = (int ***)malloc( sizeof(int ***) * n );
    int *bptr = B;
    for ( int i = 0; i < n - 1; i++) {
        first[i] = (int **)malloc( sizeof(int **) * (A[i] + 1) );
        int j;
        for ( j = 0; j < A[i]; j++) {
            first[i][j] = bptr;
            while ( *bptr != 0 ) {
                bptr++;
            }
            bptr++;
        }
        first[i][j] = NULL;
    }
    first[n-1] = NULL;

    return first;
}
