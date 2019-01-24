#include <stdio.h>

/* two factor to consider: 1. ia/b out of sizea/b
                           2. ptra/b out of sizea/b
*/
 
void merge(int A[], int B[], int* a[], int* b[])
{
    int ia = 0, ib = 0;
    int ptra = 0, ptrb = 0;
    int sizea = 0, sizeb = 0;
 
    for ( int i = 0; a[i] != NULL; i++) {
        sizea++;
    }
    for ( int i = 0; b[i] != NULL; i++) {
        sizeb++;
    }
    if ( A[0] <= B[0] ) {
        ia++;
    } else {
        ib++;
    }
    while (1) {
        // Should check if ia or ib > sizea or sizeb FIRST
        if ( ia > sizea ) {
            for ( int k = ib; k <= sizeb; k++) {
                if ( ptra <= sizea && A[ptra] <= B[ptrb] ) { // if ptra/b out of sizea/b then it should not be checked
                    a[ptra] = &B[k];
                    ptra++;
                } else {
                    b[ptrb] = &B[k];
                    ptrb++;
                }
            }
            break;
        }
        if ( ib > sizeb ) {
            for ( int k = ia; k <= sizea; k++) {
                if ( ptra <= sizea && A[ptra] <= B[ptrb] ) { // if ptra/b out of sizea/b then it should not be checked
                    a[ptra] = &A[k];
                    ptra++;
                } else {
                    b[ptrb] = &A[k];
                    ptrb++;
                }
            }
            break;
        }
        if ( A[ia] <= B[ib] ) {
            if ( A[ptra] <= B[ptrb] ) {
                a[ptra] = &A[ia];
                ptra++;
            } else {
                b[ptrb] = &A[ia];
                ptrb++;
            }
            ia++;
        } else {
            if ( A[ptra] <= B[ptrb] ) {
                a[ptra] = &B[ib];
                ptra++;
            } else {
                b[ptrb] = &B[ib];
                ptrb++;
            }
            ib++;
        }
    }
}