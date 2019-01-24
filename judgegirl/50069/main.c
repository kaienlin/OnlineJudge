#include "hangman.h"
#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    char ans[MAXL + 1], query[MAXGL + 1];
    int G;
    while (N--) {
        scanf("%s%d%s", ans, &G, query);
        Hangman *game = newGame(ans, G);
        char *g = query;
        while (*g) {
            int status = guess(game, *g);
            printf("%d ", status);
            printStatus(game);
            if ( status == -1 ) {
                puts("You Lose");
                break;
            } else if ( status == 1 && solved(game) ) {
                puts("You Win");
                break;
            }
            g++;
        }
        if ( *g == '\0' )
            puts("You Quit");
    }
    return 0;
}