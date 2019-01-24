#include <stdio.h>
#include <math.h>

// 用微分做更快更好

int main(void)
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int i, j, k;
    int tmp;
    int root[3];
    int count = 0;
    int t;

    long long int x[4];
    x[0] = c;
    x[1] = b;
    x[2] = a;
    x[3] = 1;

    for ( i = -100000; i <= 100000; i++) {
        t = 3 - count;
        for ( j = 1; j <= t; j++) {
            if ( ((i * x[3] + x[2]) * i + x[1]) * i + x[0] == 0 ) {
                root[count] = -i;

                x[0] = (i * x[3] + x[2]) * i + x[1];
                x[1] = i * x[3] + x[2];
                x[2] = x[3];
                x[3] = 0;
                
                if (count == 2) {
                    i = 100001;
                    break;
                }
                count++;
            }
        }
    }
    
    for ( i = 0; i < 2; i++) {
        for ( j = 0; j < 2; j++) {
            if ( root[j] > root[j+1] ) {
                tmp = root[j];
                root[j] = root[j+1];
                root[j+1] = tmp;
            }
        }
    }

    printf("%d %d %d", root[0], root[1], root[2]);

    return 0;
}
