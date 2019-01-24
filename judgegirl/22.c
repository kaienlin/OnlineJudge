#include "posneg.h"

void posneg(int array[5][5], int result[2])
{
    int i, j;
    result[0] = 0;
    result[1] = 0;
    for ( i = 0; i < 5; i++)
        for ( j = 0; j < 5; j++)
            if ( array[i][j] > 0 ) result[1]++;
            else if ( array[i][j] ) result[0]++;
}
