#include "evaluate_f.h"

int evaluate_f(int *iptr[], int n, int *index)
{
    int i, max = -2000000000;
    for ( i = 0; i < n; i++) {
        int f = 4 * iptr[i][0] - 6 * iptr[i][1];
        if ( f > max ) {
            max = f;
            *index = i;
        }
    }
    return max;
}