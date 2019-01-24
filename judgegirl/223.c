#include <stdio.h>
 
const int t[4][3] = {{3, 0, 1}, {2, 1, 0}, {1, 2, 3}, {0, 3, 2}};
const int dx[4][3] = {{-1, -1, 1}, {1, 1, -1}, {1, 1, -1}, {-1, -1, 1}};
const int dy[4][3] = {{1, -1, -1}, {1, -1, -1}, {-1, 1, 1}, {-1, 1, 1}};
 
void tile(int center_x, int center_y, int size, int type)
{
    if ( size == 2 ) {
        printf("%d %d %d\n", type + 1, center_x, center_y);
        return;
    } else {
        for ( int i = 0; i < 3; i++) {
            tile(center_x + (size / 4 * dx[type][i]), center_y + (size / 4 * dy[type][i]), size / 2, t[type][i]);
        }
        tile(center_x, center_y, size / 2, type);
    }
}
 
void partition(int len, int l, int m)
{
    if ( len == m ) {
        return;
    } else {
        tile(l - len / 2, l - len / 2, len, 0);
        partition(len / 2, l, m);
    }
}
 
int main()
{
    int l, m;
    scanf("%d%d", &l, &m);
    partition(l, l, m);
    return 0;
}