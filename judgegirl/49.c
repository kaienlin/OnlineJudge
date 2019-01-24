#include <stdio.h>

/*  This problem can be solve with one-dimensional array but I stick to two-dimensional one so that 
    I use a ugly method to solve the extremely huge array. 
    The following code is improved.
*/

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    int num[n];
    int tmp, index;
    int i, j;
    int min, max, sum;

    for ( i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    for ( i = 0; i < m; i++) {
        sum = 0;
        max = -1;
        min = 10001;
        for ( j = 0; j < n; j++) {
            if ( num[j] % m == i ) {
                if ( num[j] > max ) max = num[j];
                if ( num[j] < min ) min = num[j];
                sum += num[j];
            }
        }
        printf("%d %d %d\n", sum, max, min);
    }

    return 0;
}
