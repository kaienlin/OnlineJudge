#include <stdio.h>
#include <stdlib.h>

struct cell {
    int num;
    int *ptr;
};

typedef struct cell Cell;

int cmp(const void *a, const void *b)
{
    Cell x = *(Cell *)a;
    Cell y = *(Cell *)b;
    if ( x.num == y.num ) {
        return *(x.ptr) - *(y.ptr);
    } else {
        return x.num - y.num;
    }
}

void count(int **p[])
{
    Cell table[512];
    for ( int i = 0; i < 512; i++) {
        table[i].num = 0;
        table[i].ptr = NULL;
    }
    int ***ptr = p;
    int right = 0;
    while ( *ptr != NULL ) {
        int i;
        for ( i = 0; i < 512; i++) {
            if ( table[i].ptr == **ptr ) {
                table[i].num++;
                break;
            }
        }
        if ( i == 512 ) {
            table[right].num = 1;
            table[right].ptr = **ptr;
            right++;
        }
        ptr++;
    }
    qsort(table, right, sizeof(struct cell), cmp);
    for ( int i = 0; i < right; i++) {
        printf("%d %d\n", *(table[i].ptr), table[i].num );
    }
}