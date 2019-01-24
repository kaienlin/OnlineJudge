#include <stdio.h>

int main()
{
    int n, d;
    scanf("%d", &n);
    int m1 = 0, m2 = 0, l1 = __INT_MAX__, l2 = __INT_MAX__;
    for ( int i = 0; i < n; i++) {
        scanf("%d", &d);
        if ( d > m1 )
            m2 = m1, m1 = d;
        else if ( d > m2 )
            m2 = d;
        if ( d < l1 )
            l2 = l1, l1 = d;
        else if ( d < l2 )
            l2 = d;
    }
    if ( l2 - l1 >= m1 - m2 )
        printf("%d\n", m1 - l2);
    else
        printf("%d\n", m2 - l1);
    return 0;
}