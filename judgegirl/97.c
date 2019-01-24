#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, m;
    int i, j; //counter
    int x, y;
    int min_index, min_dis, min_x_dis, min_y_dis;
    int x_dis, y_dis;

    scanf("%d", &n);
    int parkinglots[n][4];

    for ( i = 0; i < n; i++) {
        scanf("%d%d%d", &parkinglots[i][0], &parkinglots[i][1], &parkinglots[i][2]);
        parkinglots[i][3] = 0;
    }

    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        min_dis = 40000;
        min_x_dis = 20000;
        min_y_dis = 20000;

        for (j = 0; j < n; j++) {
            x_dis = abs(x - parkinglots[j][0]);
            y_dis = abs(y - parkinglots[j][1]);

            if ( parkinglots[j][2] == 0 ) {
                continue;
            }

            if ( x_dis + y_dis < min_dis) {
                min_index = j;
                min_dis = x_dis + y_dis;
                min_x_dis = x_dis;
                min_y_dis = y_dis;
            } else if ( x_dis + y_dis == min_dis ) {
                if ( parkinglots[j][0] < parkinglots[min_index][0] ) {
                    min_index = j;
                    min_dis = x_dis + y_dis;
                    min_x_dis = x_dis;
                    min_y_dis = y_dis;
                } else if ( parkinglots[j][0] == parkinglots[min_index][0] ) {
                    if ( parkinglots[j][1] < parkinglots[min_index][1] ) {
                        min_index = j;
                        min_dis = x_dis + y_dis;
                        min_x_dis = x_dis;
                        min_y_dis = y_dis;
                    }
                }
            }
        }
        parkinglots[min_index][3]++;
        parkinglots[min_index][2]--;
    }

    for ( i = 0; i < n; i++) {
        printf("%d\n", parkinglots[i][3]);
    }

    return 0;
}
