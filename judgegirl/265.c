#include <stdio.h>

int main(void) 
{
    int point[100][2];
    int len, i;
    int left = 10000, right = -10000, top = -10000, bottom = 10000;

    while ( scanf("%d%d", &point[len][0], &point[len][1]) != EOF ) {
        len++;
    }

    for ( i = 0; i < len; i++) {
        if ( point[i][0] < left ) left = point[i][0];
        if ( point[i][0] > right ) right = point[i][0];
        if ( point[i][1] < bottom ) bottom = point[i][1];
        if ( point[i][1] > top ) top = point[i][1];
    }

    printf("%d", (right - left) * (top - bottom));

    return 0;
}
