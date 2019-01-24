#include <stdio.h>
#define MAXLEN 16384

int n, seesaw[MAXLEN], b[MAXLEN] = {0};

int balance(int l, int r) {
    long long m_tot = 0, rm = 0;
    for ( int i = l; i <= r; i++) {
        m_tot += seesaw[i];
        rm += i * seesaw[i];
    }
    if ( rm % m_tot != 0 )
        return -1;
    return rm / m_tot;
}

void chandelier(int l, int r) {
    if ( r - l < 2 )
        return;
    int middle = balance(l, r);
    if ( middle == -1 )
        return;
    b[middle] = 1;
    chandelier(l, middle - 1);
    chandelier(middle + 1, r);
}

int main()
{
    scanf("%d", &n);
    for ( int i = 0; i < n; i++)
        scanf("%d", &seesaw[i]);
    chandelier(0, n - 1);
    for ( int i = 0; i < n; i++)
        if ( b[i] )
            printf("%d\n", i);
    return 0;
}