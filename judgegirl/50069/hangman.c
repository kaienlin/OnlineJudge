#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hangman.h"

struct Hangman {
    char ans[MAXL + 1], now[MAXL + 1];
    int G, wrong, rest;
};

Hangman* newGame(char *answer, int G) {
    Hangman *ret = (Hangman*)malloc(sizeof(Hangman));
    ret->G = G;
    ret->wrong = 0;
    ret->rest = strlen(answer);
    strcpy(ret->ans, answer);
    for ( int i = 0; i < ret->rest; i++)
        ret->now[i] = '*';
    ret->now[ret->rest] = '\0';
    return ret;
}
int guess(Hangman* hangman, char ch) {
    int ret = 0;
    for ( int i = 0; hangman->ans[i]; i++) {
        if ( hangman->ans[i] == ch ) {
            ret = 1;
            if ( hangman->now[i] == '*' )
                hangman->rest--;
            hangman->now[i] = ch;
        }
    }
    if ( !ret ) {
        hangman->wrong++;
        if ( hangman->wrong == hangman->G )
            return -1;
    }
    return ret;
}
void printStatus(Hangman* hangman) {
    puts(hangman->now);
}
int solved(Hangman* hangman) {
    if ( !hangman->rest )
        return 1;
    return 0;
}