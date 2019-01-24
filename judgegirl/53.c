#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int n;
 
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
 
int permutation(int a[], int begin)
{
    if ( begin == n - 1 ) {
        for ( int i = 0; i < n; i++) {
            printf("%d", a[i]);
            if ( i < n - 1 )
                putchar(' ');
        }
        putchar('\n');
    } else {
        for ( int i = begin; i < n; i++) {
            int tmp[n];
            memcpy(tmp, a, sizeof(tmp));
            swap(&tmp[begin], &tmp[i]);
            qsort(&tmp[begin+1], n - begin - 1, sizeof(int), cmp);
            permutation(tmp, begin + 1);
        }
    }
}
 
int main()
{
    scanf("%d", &n);
    int array[n];
    for ( int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    qsort(array, n, sizeof(int), cmp);
    permutation(array, 0);
    return 0;
}