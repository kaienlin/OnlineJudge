#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int road[102][102] = {{0}}; // mistake I made: forget to include the 102 "edge" (I wrote road[101][101] then)
    int i, j;
    int count;
    int inter = 0, Tjun = 0, turn = 0, dead = 0; 

    for ( i = 1; i <= n; i++) {
        for ( j = 1; j <= n; j++) {
            scanf("%d", &road[i][j]);
        }
    }

    for ( i = 1; i <= n; i++) {
        for ( j = 1; j <= n; j++) {
            count = 0;
            if ( road[i][j] == 1) {
                if ( road[i+1][j] == 1 )
                    count++;
                if ( road[i-1][j] == 1 ) 
                    count++;
                if ( road[i][j+1] == 1 )
                    count++;
                if ( road[i][j-1] == 1 )
                    count++;

                if ( count == 4 ) {
                    inter++;
                } else if ( count == 3 ) {
                    Tjun++;
                } else if ( count == 1 ) {
                    dead++;
                } else if ( count == 2 ) {
                    if ( road[i+1][j] != road[i-1][j] ) {
                        turn++;
                    }
                }
            }
        }
    }

    printf("%d\n%d\n%d\n%d\n", inter, Tjun, turn, dead);

    return 0;
}
