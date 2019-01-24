#include <stdio.h>

void play1(int b[4][4], int n, int r, int sum1, int sum2);
void play2(int b[4][4], int n, int c, int sum1, int sum2);

int win1 = 0, win2 = 0, tie = 0;

void play1(int b[4][4], int n, int r, int sum1, int sum2)
{
    int flag = 0;
    for ( int i = 0; i < n; i++) {
        if ( b[r][i] ) {
            flag = 1;
            int dummy[4][4];
            for ( int x = 0; x < n; x++)
                for ( int y = 0; y < n; y++)
                    dummy[x][y] = b[x][y];
            dummy[r][i] = 0;
            play2(dummy, n, i, sum1 + b[r][i], sum2);
        }
    }
    if ( !flag ) {
        if ( sum1 > sum2 ) { win1++; }
        else if ( sum2 > sum1 ) { win2++; }
        else { tie++; }
        return;
    }
}

void play2(int b[4][4], int n, int c, int sum1, int sum2)
{
    int flag = 0;
    for ( int i = 0; i < n; i++) {
        if ( b[i][c] ) {
            flag = 1;
            int dummy[4][4];
            for ( int x = 0; x < n; x++)
                for ( int y = 0; y < n; y++)
                    dummy[x][y] = b[x][y];
            dummy[i][c] = 0;
            play1(dummy, n, i, sum1, sum2 + b[i][c]);
        }
    }
    if ( !flag ) {
        if ( sum1 > sum2 ) { win1++; }
        else if ( sum2 > sum1 ) { win2++; }
        else { tie++; }
        return;
    }
}

int main()
{
    int n;
    int board[4][4];
    while ( scanf("%d", &n) != EOF ) {
        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < n; j++) {
                scanf("%d", &board[i][j]);
            }
        }
        play1(board, n, 0, 0, 0);
        printf("%d %d %d\n", win1, win2, tie);
        win1 = win2 = tie = 0;
    }
    return 0;
}