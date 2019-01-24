#include <stdio.h>

int cell[2048], n;
long long mtot, rm;

int balance() {
    if ( rm % mtot != 0 )
        return -1;
    return rm / mtot;
}

int main()
{
    scanf("%d", &n);
    for ( int i = 0; i < n; i++) {
        scanf("%d", &cell[i]);
        mtot += cell[i];
        rm += i * cell[i];
    }
    int m, cnt = 0;
    while ( (m = balance()) == -1 ) {
        rm -= cnt * cell[cnt] + (n-1-cnt) * cell[n-1-cnt];
        cell[cnt] ^= cell[n-1-cnt] ^= cell[cnt] ^= cell[n-1-cnt];
        rm += cnt * cell[cnt] + (n-1-cnt) * cell[n-1-cnt]; 
        cnt++;
    }
    for ( int i = 0; i < n; i++)
        if ( i != m )
            printf("%d%c", cell[i], " \n"[i == n - 1]);
        else
            printf("v%c", " \n"[i == n - 1]);
    return 0;
}