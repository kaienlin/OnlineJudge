#include <stdio.h>
#include <stdlib.h>
#include "activity.h"

int cmp(const void *a, const void *b) {
    Activity *x = (Activity*)a, *y = (Activity*)b;
    return x->end - y->end;
}

int select(Activity activities[], int n) {
    qsort(activities, n, sizeof(Activity), cmp);
    Activity seq[n];
    int current_end = activities[0].end, cnt = 1;
    seq[0] = activities[0];
    for ( int i = 1; i < n; i++) {
        if ( activities[i].start >= current_end ) {
            current_end = activities[i].end;
            seq[cnt++] = activities[i];
        }
    }
    #ifdef PRINT
    for ( int i = 0; i < cnt; i++)
        printf("%d %d\n", seq[i].start, seq[i].end);
    #endif
    return cnt;
}