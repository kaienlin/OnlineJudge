#include <stdio.h>

int main(void)
{
    int r, c;
    scanf("%d%d", &r, &c);
    int table[r][c];
    int average[c];
    int sum;

    int i, j;
    for ( i = 0; i < r; i++) {
        for ( j = 0; j < c; j++) {
            scanf("%d", &table[i][j]);
        }
    }

    for ( i = 0; i < c; i++) {
        sum = 0;
        for ( j = 0; j < r; j++) {
            sum += table[j][i];
        }
        average[i] = sum / r;
    }

    for ( i = 0; i < c; i++) {
        printf("%d\n", average[i]);
    }
    return 0;
}
