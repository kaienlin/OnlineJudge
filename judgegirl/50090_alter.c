#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    if ( x[1] > y[1] ) {
        return 1;
    } else if ( x[1] < y[1] ) {
        return -1;
    } else if ( x[0] > y[0] ) {
        return 1;
    } else if ( x[0] < y[0] ) {
        return -1;
    } else {
        return 0;
    }
}

void count(int **p[])
{
    int num_table[512][2] = {{0}}; // number and count
    int count_of_num_table = 0;
    int *ptr_table[512]; // index of second level pointers which have been seen
    int count_of_ptr_table = 0;
    for ( int i = 0; i < 512; i++) { ptr_table[i] = NULL; }
    int ptr_to_num[512]; // index coorespend to ptr_table
    for ( int i = 0; p[i] != NULL; i++) {
        int where = -1;
        for ( int j = 0; ptr_table[j] != NULL; j++) {
            if ( *p[i] == ptr_table[j] ) {
                where = j;
            }
        }
        if ( where >= 0 ) {
            num_table[ptr_to_num[where]][1]++;
        } else {
            num_table[count_of_num_table][0] = **p[i];
            num_table[count_of_num_table][1] = 1;
            ptr_table[count_of_ptr_table] = *p[i];
            ptr_to_num[count_of_ptr_table] = count_of_num_table;
            count_of_num_table++;
            count_of_ptr_table++;
        }
    }
    qsort(num_table, count_of_num_table, sizeof(int) * 2, cmp);
    for ( int i = 0; i < count_of_num_table; i++) {
        printf("%d %d\n", num_table[i][0], num_table[i][1]);
    }
}
