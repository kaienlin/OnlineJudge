#include <stdio.h>
#include <stdlib.h>
 
int lake(int r, int c, int n, int m, int map[n][m])
{
    if ( r < 0 || r > n - 1 || c < 0 || c > m - 1 || !map[r][c]) {// check if exceed edge first to prevent SIGFAULT
        return 0;
    } else {
        map[r][c] = 0;
        return 1 + lake(r + 1, c, n, m, map) + lake(r, c + 1, n, m, map) + lake(r - 1, c, n, m, map) + lake(r, c - 1, n, m, map);
    }
}

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
 
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int map[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    int ans[n * m / 2 + 1];
    int count = 0;
    //int flag = 1; no need to find non-zero cell from [0][0] every time
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ( map[i][j] ) {
                ans[count++] = lake(i, j, n, m, map);
            }
        }
    }
    qsort(ans, count, sizeof(int), cmp);
    for ( int i = 0; i < count; i++)
        printf("%d\n", ans[i]);
    return 0;
}