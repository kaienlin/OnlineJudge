#include "City_Grid.h"
#include <stdlib.h>
#include <string.h>
 
void traverse(City *rec[], City *c, int *N) {
    if ( c == NULL )
        return;
    if ( rec[c->label] == NULL ) {
        rec[c->label] = c;
        (*N)++;
    } else {
        return;
    }
    traverse(rec, c->east, N);
    traverse(rec, c->north, N);
}
int isGrid(City *c) {
    return !( c == NULL || c->east == NULL || c->north == NULL || c->east->north == NULL || c->north->east == NULL );
}
int City_Grid(City *capital) {
    City *record[10000] = {NULL};
    int N = 0;
    traverse(record, capital, &N);
    int ret = 0;
    for ( int i = 0; i < N; i++)
        if ( isGrid(record[i]) )
            ret++;
    return ret;
}