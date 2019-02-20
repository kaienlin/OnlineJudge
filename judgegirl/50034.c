#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int n, seesaw[18], w[18], used[18];
int mtot, b_point, done;
int *sorted[18];
int map[18];
int lookup[18][18];

int possible(int idx, int rm) {
	int max = rm, min = rm;
	for ( int i = 0, c = 0; i < n; i++)
		if ( !used[map[i]] )
			max += lookup[map[i]][idx + (c++)];
	for ( int i = n - 1, c = 0; i >= 0; i--)
		if ( !used[map[i]] )
			min += lookup[map[i]][idx + (c++)];
	return !( max < b_point * mtot || min > b_point * mtot );
}

void rec(int idx, int rm) {
    if ( !possible(idx, rm) ) { return; }
    if ( idx == n ) {
        if ( rm % mtot == 0 && rm / mtot == b_point )
            done = 1;
        return;
    }
    for ( int i = n - 1; i >= 0; i--) {
        if ( !used[i] ) {
            seesaw[idx] = w[i];
            used[i] = 1;
            rec(idx+1, rm + lookup[i][idx]);
            if ( done ) {return;}
            used[i] = 0;
        }
    }
}

int cmp(const void *a, const void *b) {
	return **(int**)a > **(int**)b;
}
 
int main()
{
    while ( ~scanf("%d", &n) ) {
        mtot = 0;
        for ( int i = 0; i < n; i++) {
            scanf("%d", &w[i]);
            mtot += w[i];
			sorted[i] = &w[i];
			for ( int j = 0; j < n; j++)
				lookup[i][j] = j * w[i];
        }
		qsort(sorted, n, sizeof(int*), cmp);
		for ( int i = 0; i < n; i++)
			map[i] = sorted[i] - w;
        b_point = (n - 1) / 2;
        done = 0;
        memset(used, 0, sizeof(used));
        rec(0, 0);
        if ( done ) {
            for ( int i = 0; i < n; i++) {
                if ( i == b_point )
                    printf("_^_ ");
                else
                    printf("%d%c", seesaw[i], " \n"[i == n - 1]);
            }
        } else
            puts("N");
    }
    return 0;
}
