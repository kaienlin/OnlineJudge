#include "elevator.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int u, d, F;
    char cmd[MAXL+1];
    while (N--) {
        scanf("%d%d%d", &u, &d, &F);
        Elevator *e = newElevator(u, d, F);
        scanf("%s", cmd);
        for ( int i = 0; cmd[i]; i++) {
            int status;
            if ( cmd[i] == 'U' ) {
                status = up(e);
                if ( status == -1 ) {
                    puts("Broken");
                    break;
                } else if ( status == 1 )
                    printf("Valid %d\n", getPosition(e));
                else if ( status == 0 )
                    puts("Invalid");
            } else if ( cmd[i] == 'D' ) {
                status = down(e);
                if ( status == -1 ) {
                    puts("Broken");
                    break;
                } else if ( status == 1 )
                    printf("Valid %d\n", getPosition(e));
                else if ( status == 0 )
                    puts("Invalid");
            }
        }
        for ( int i = 1; i <= F; i++)
            if ( visited(e, i) )
                printf("%d\n", i);
        free(e); // to prevent MLE
    }
    return 0;
}