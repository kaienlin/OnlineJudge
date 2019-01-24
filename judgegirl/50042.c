#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    int i, j;
    int mount;
    int max_r = 0, smax_r = 0, max;
    int max_r_index, smax_r_index, max_index[2];

    for ( i = 1; i <= n; i++) {
        for ( j = 1; j <= m; j++) {
            scanf("%d", &mount);
            if ( mount >= max_r ) {
                smax_r = max_r;
                smax_r_index = max_r_index;
                max_r = mount;
                max_r_index = j;
            } else if ( mount >= smax_r ){
                smax_r = mount;
                smax_r_index = j;
            }
            if ( mount >= max ) {
                max = mount;
                max_index[0] = i;
                max_index[1] = j;
            } 
        }
        printf("%d %d\n", max_r_index, smax_r_index);
        max_r = 0;
    }
        
    printf("%d %d", max_index[0], max_index[1]);
    return 0;
}
