#include <stdio.h>

int main(void)
{
    int n;
    int i, j, k;
    scanf("%d", &n);

    int circle[3][3];
    long long int x, y;
    int count;
    int result;
    
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < 3; j++) {
            scanf("%d%d%d", &circle[j][0], &circle[j][1], &circle[j][2]);
        }

        result = 0;

        for ( j = 0; j < 3; j++) {
            for ( y = circle[j][1] - circle[j][2]; y <= circle[j][1] + circle[j][2]; y++) {
                for ( x = circle[j][0] - circle[j][2]; x <= circle[j][0] + circle[j][2]; x++) {
                    if ( (x - circle[j][0]) * (x - circle[j][0]) + (y - circle[j][1]) * (y - circle[j][1]) <= circle[j][2] * circle[j][2] ) {
                        count = 0;
                        if ( (x - circle[0][0]) * (x - circle[0][0]) + (y - circle[0][1]) * (y - circle[0][1]) <= circle[0][2] * circle[0][2] ) count++;
                        if ( (x - circle[1][0]) * (x - circle[1][0]) + (y - circle[1][1]) * (y - circle[1][1]) <= circle[1][2] * circle[1][2] ) count++;
                        if ( (x - circle[2][0]) * (x - circle[2][0]) + (y - circle[2][1]) * (y - circle[2][1]) <= circle[2][2] * circle[2][2] ) count++;
                        if ( count == 1 ) result++;
                        else if ( count == 3 && j == 0) result++;
                    }
                }
            }
        }

        printf("%d\n", result);
    }

    return 0;
}
