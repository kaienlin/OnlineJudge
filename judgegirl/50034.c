#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int n, seesaw[18], w[18], used[18];
int mtot, b_point, done;

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
 
void rec(int idx, int rm, int mt) {
    if ( done || rm > b_point * mt ) {return;}
    if ( idx == n ) {
        if ( rm % mtot == 0 && rm / mtot == b_point )
            done = 1;
        return;
    }
    for ( int i = 0; i < n; i++) {
        if ( !used[i] ) {
            seesaw[idx] = w[i];
            used[i] = 1;
            rec(idx+1, rm + idx * w[i], mt + w[i]);
            if ( done ) {return;}
            used[i] = 0;
        }
    }
}
 
int main()
{
    while ( ~scanf("%d", &n) ) {
        mtot = 0;
        for ( int i = 0; i < n; i++) {
            scanf("%d", &w[i]);
            mtot += w[i];
        }
        b_point = (n - 1) / 2;
        done = 0;
        memset(used, 0, sizeof(used));
        rec(0, 0, 0);
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