#include <stdio.h>

int main()
{
    int t, n, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        int m = n / k, s = n % k;
        char c = 'a';
        for ( int i = 0; i < k; i++)
            for ( int j = 0; j < m; j++)
                putchar(c+i);
        for ( int i = 0; i < s; i++)
            putchar(c+k-1);
        putchar('\n');
    }
    return 0;
}