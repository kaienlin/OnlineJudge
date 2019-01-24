#include <stdio.h>
#include <string.h>

int friend[32768][256];

int main()
{
    int N, E;
    scanf("%d%d", &N, &E);

    int friend_count[N];
    memset(friend_count, 0, sizeof(friend_count));
    int man1, man2;
    for ( int i = 1; i <= E; i++) {
        scanf("%d%d", &man1, &man2);
        friend[man1][friend_count[man1]++] = man2;
        friend[man2][friend_count[man2]++] = man1;
    }

    int party[N];
    memset(party, 0, sizeof(party));
    int invite;
    while ( scanf("%d", &invite) != EOF ) {
        party[invite] = 1;
        for ( int i = 0; i < friend_count[invite]; i++) {
            party[friend[invite][i]] = 1;
        }
    }

    for ( int i = 0; i < N; i++) {
        if ( !party[i] ) {
            printf("%d\n", i);
        }
    }

    return 0;
}