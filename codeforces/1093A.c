#include <stdio.h>

int main()
{
    int t, q;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &q);
        int ans;
        if ( q % 7 == 0 )
            ans = q / 7;
        else
            ans = q / 7 + 1;
        printf("%d\n", ans);
    }
    return 0;
}