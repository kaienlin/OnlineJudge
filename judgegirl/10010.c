#include <stdio.h>
#include <stdlib.h>

int field[1024][1024] = {{0}};
int ans[1 << 20];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int q;
    scanf("%d", &q);
    int lx, ly, rx, ry;
    while (q--) {
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        int count = 0;
        for ( int i = lx; i <= rx; i++) {
            for ( int j = ly; j <= ry; j++) {
                if ( !field[i][j] ) {
                    ans[count++] = i * 10000 + j;
                    field[i][j] = 1;
                }
            }
        }
        qsort(ans, count, sizeof(int), cmp);
        printf("%d%c", count, count == 0 ? '\n' : ' ');
        for ( int i = 0; i < count; i++) {
            printf("(%d, %d)%c", ans[i] / 10000, ans[i] % 10000, i == count - 1 ? '\n' : ' ');
        }
    }

    return 0;
}