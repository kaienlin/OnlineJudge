#include <stdio.h>
#include <stdlib.h>

/* There are two condition when we look on a number in the set:
    1. we choose it.
    2. we don't.
*/

int subset_sum(int set[], int k, int n)
{
    if ( k == 0 ) {
        return 1;
    } else if ( k < 0 || n < 0 ) {
        return 0;
    } else {
        return subset_sum(set, k - set[n], n - 1) + subset_sum(set, k, n - 1);
    }
}

int main()
{
    int n, k;
    int set[15];
    scanf("%d", &n);
    for ( int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    while ( scanf("%d", &k) != EOF ) {
        printf("%d\n", subset_sum(set, k, n - 1));
    }
    return 0;
}