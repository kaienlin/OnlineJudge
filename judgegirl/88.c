#include <stdio.h>

int main(void)
{   
    int m, n;
    int x[4], y[4];
    int flag[4] = {0}, num[10] = {0};
    int a = 0, b = 0;
    int i;

    scanf("%d%d", &m, &n);

    for ( i = 0; i < 4; i++) {
        x[i] = m % 10;
        y[i] = n % 10;
        m /= 10;
        n /= 10;
    }

    for ( i = 0; i < 4; i++) {
        if ( x[i] == y[i] ) {
            a++;
            flag[i] = 1;
        } else {
            num[x[i]] = 1;
        }
    }

    for ( i = 0; i < 4; i++) {
        if (!flag[i] && num[y[i]]) {
            b++;
        }
    }
    printf("%dA%dB", a, b);
    return 0;
}
