#include"max.h"

int max(int *iptr[], int n)
{
    int max = -200000000;
    for ( int i = 0; i < n; i++) {
        if ( *iptr[i] > max ) max = *iptr[i];
    }
    return max;
}