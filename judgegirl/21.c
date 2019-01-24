#include "max.h"
#include <limits.h>

int max(int array[5][5])
{
    int i, j, max = INT_MIN;
    for ( i = 0; i < 5; i++) {
        for ( j = 0; j < 5; j++) {
            if ( array[i][j] > max ) max = array[i][j];
        }
    }

    return max;
}