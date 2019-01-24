#include <stdlib.h>
 
void split(int A[], int *a[], int *head[], int k)
{
    int **tail[k];
    int i, r;
    for ( i = 0; i < k; i++)
        tail[i] = &head[i];
    for ( i = 0; a[i] != NULL; i++) {
        r = A[i] % k;
        *tail[r] = &A[i];
        tail[r] = &a[i];
        a[i] = NULL;
    }
    r = A[i] % k;
    if ( head[r] == NULL ) {
        head[r] = &A[i];
    } else {
        *tail[r] = &A[i];
    }
}