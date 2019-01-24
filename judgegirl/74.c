#include <stdio.h>

int main(void)
{
    int n;
    int m;
    int i, j;

    scanf("%d", &n);
    int num[n];

    for ( i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    scanf("%d", &m);
    int output[m];
    
    for ( i = 0; i < m; i++) {
        output[i] = 0;
    }

    for ( i = 0; i < n; i++) {
        output[num[i] % m]++; 
    }

    for ( i = 0; i < m; i++) {
        printf("%d\n", output[i]);
    }

    return 0;
}
