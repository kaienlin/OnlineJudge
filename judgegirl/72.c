#include "fill_array.h"

void fill_array(int *ptr[], int n)
{
    int i;
    int *j;
    for ( i = 0; i < n; i++) {
        *ptr[i] = i;
    }
    for ( i = 0; i < n; i++) {
        for (int j = 0; j < n -1; j++) {
            if ( ptr[j] > ptr[j+1] ) {
                int *tmp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = tmp;
            }
        }
    } // sort ptr array such that we can process it conviently
    for ( i = 0; i < n - 1; i++) {
        for ( j = ptr[i] + 1; j < ptr[i + 1]; j++) {
            int x = *ptr[i] + *ptr[i + 1];
            *j = x;
        }
    }
}
