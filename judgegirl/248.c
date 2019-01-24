#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dr[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dc[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

void print_mine(int mine[11][11])
{
    for ( int i = 1; i < 10; i++)
        for ( int j = 1; j < 10; j++)
            printf("%d%c", mine[i][j], " \n"[j == 9]);
}

int check(int field[9][9], int mine[11][11], int r, int c)
{
    int sum = 0;
    for ( int i = 0; i < 9; i++)
        sum += mine[r + dr[i]][c + dc[i]];
    return sum == field[r-1][c-1];
}

void solve(int field[9][9], int mine[11][11], int index)
{
    if ( index == -1 ) {
        print_mine(mine);
        exit(0);
    }
    int r = index / 9 + 1, c = index % 9 + 1, valid = 1;
    if ( r < 9 && c < 9 ) {
        mine[r][c] = 1;
        if ( !check(field, mine, r + 1, c + 1) ) { valid = 0; }
        if ( c == 1 && !check(field, mine, r + 1, c) ) { valid = 0; }
        if ( r == 1 && !check(field, mine, r, c + 1) ) { valid = 0; }
        if ( r == 1 && c == 1 && !check(field, mine, r, c) ) { valid = 0; }
        if ( valid )
            solve(field, mine, index - 1);
        mine[r][c] = 0;
        valid = 1;
        if ( !check(field, mine, r + 1, c + 1) ) { valid = 0; }
        if ( c == 1 && !check(field, mine, r + 1, c) ) { valid = 0; }
        if ( r == 1 && !check(field, mine, r, c + 1) ) { valid = 0; }
        if ( r == 1 && c == 1 && !check(field, mine, r, c) ) { valid = 0; }
        if ( valid )
            solve(field, mine, index - 1);
        else
            return;
    } else {
        mine[r][c] = 1;
        solve(field, mine, index - 1);
        mine[r][c] = 0;
        solve(field, mine, index - 1);
    }
}

int main()
{
    int field[9][9];
    for ( int i = 0; i < 9; i++)
        for ( int j = 0; j < 9; j++)
            scanf("%d", &field[i][j]);
    int mine[11][11] = {{0}};
    solve(field, mine, 80);
    printf("no solution\n");
    return 0;
}