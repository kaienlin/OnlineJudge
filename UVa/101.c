#include <stdio.h>
#include <string.h>
#define MAXN 24

int readCmd(int *type1, char *i1, int *type2, char *i2)
{
    char input[4][8];
    if ( scanf("%s %s %s %s", input[0], input[1], input[2], input[3]) < 4 ) {
        return EOF;
    } else {
        if ( input[0][0] == 'm' ) { *type1 = 0; }
        else { *type1 = 1; }
        *i1 = input[1][0];
        if ( input[2][0] == 'o' && input[0][1] == 'n' ) { *type2 = 0; }
        else { *type2 = 1; }
        *i2 = input[3][0];
    }
    return 1;
}

void move_onto(char stack[][MAXN], int posa[], int posb[])
{
    char tmpa = stack[posa[0]][posa[1]];
    char buffer[MAXN];
    strcpy(buffer, &stack[ posa[0] ][ posa[1] + 1 ]);
    strcpy(&stack[ posa[0] ][ posa[1] ], buffer);
    strcpy(buffer, &stack[ posb[0] ][ posb[1] + 1]);
    stack[ posb[0] ][ posb[1] + 1 ] = tmpa;
    strcpy(&stack[ posb[0] ][ posb[1] + 2], buffer);
    return;
}

int main()
{
    char stack[MAXN][MAXN] = {{0}};
    int n;
    scanf("%d", &n);
    for ( int i = 0; i < n; i++)
        stack[i][0] = i + '0';
    int type1, type2;
    char ia, ib;
    int posa[2], posb[2];
    while ( readCmd(&type1, &ia, &type2, &ib) != EOF ) {
        if ( ia == ib ) { continue; }
        else {
            for ( int i = 0; i < n; i++) {
                for ( int j = 0; stack[i][j] != '\0'; j++) {
                    if ( stack[i][j] == ia ) {
                        posa[0] = i;
                        posa[1] = j;
                    }
                    if ( stack[i][j] == ib ) {
                        posb[0] = i;
                        posb[1] = j;
                    }
                }
            }
            if ( posa[0] == posb[0] ) { continue; }
            if ( type1 == 0 && type2 == 0 ) {
                move_onto(stack, posa, posb);
            } else if ( type1 == 1 && type2 == 0 ) {
                //move_over(stack, posa, posb);
            } else if ( type1 == 0 && type2 == 1 ) {
                //pile_onto(stack, posa, posb);
            } else {
                //pile_over(stack, posa, posb);
            }
        }
    }
    for ( int i = 0; i < n; i++) {
        printf("%d: ", i);
        for ( int j = 0; stack[i][j] != '\0'; j++)
            printf("%c ", stack[i][j]);
        puts("");
    }
    return 0;
}