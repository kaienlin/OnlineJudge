#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int a[3];
    int x[3], y[3];
    int i, j;
    int max, max_index;
    int other1, other2;

    for ( i = 1; i <= n; i++) {
        for ( j = 0; j < 3; j++) {
            scanf("%d%d", &x[j], &y[j]);
        }
        a[0] = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);
        a[1] = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
        a[2] = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);

        max = 0;
        for ( j = 0; j < 3; j++) {
            if (a[j] > max) {
                max = a[j];
                max_index = j;
            }
        }

        switch (max_index) {
            case 0:
                other1 = a[1];
                other2 = a[2];
                break;
            case 1:
                other1 = a[0];
                other2 = a[2];
                break;
            case 2:
                other1 = a[0];
                other2 = a[1];
                break;
        }

        if ( a[0] == a[1] || a[0] == a[2] || a[1] == a[2]) {
            printf("isosceles\n");
        } else if ( other1 + other2 == max ) {
            printf("right\n");
        } else if ( other1 + other2 > max) {
            printf("acute\n");
        } else {
            printf("obtuse\n");
        }
    }
}