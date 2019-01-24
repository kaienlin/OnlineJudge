#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return **(int**)a - **(int**)b;
}

void snake(const int *ptr_array[100][100], int m)
{
    int *ptr[m*m];
    for ( int i = 0; i < m; i++)
        for ( int j = 0; j < m; j++) {
            ptr[i * m + j] = ptr_array[i][j];
        }

    qsort(ptr, m * m, sizeof(int*), cmp); // the call method of qsort is important!

    for ( int i = 0; i < m * m; i++) {
        if ( i % (m * 2) >= 0 && i % (m * 2) < m ) {
            ptr_array[i / m][i % m] = ptr[i];
        } else {
            ptr_array[i / m][m - 1 - i % m] = ptr[i];
        }
    }
}
