#include <stdio.h>
#include <string.h>
 
int main()
{
    char digits[11];
    int w, h;
    int dict[7][10] = {{1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
                       {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
                       {0, 0, 1, 1, 1, 1, 1, 0, 1, 1},
                       {1, 0, 1, 0, 0, 0, 1, 0, 1, 0},
                       {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
                       {1, 0, 1, 1, 0, 1, 1, 0, 1, 0}};
    while ( scanf("%s%d%d", digits, &w, &h) != EOF ) {
        for ( int i = 0; i < strlen(digits); i++) {
            if ( dict[0][digits[i] - '0'] ) {
                putchar(' ');
                for ( int j = 2; j <= w - 2; j++)
                    putchar(digits[i]);
                printf("  ");
            } else {
                for ( int j = 1; j <= w; j++)
                    putchar(' ');
            }
        }
        putchar('\n');
        for ( int j = 1; j <= (h - 3) / 2; j++) {
            for ( int i = 0; i < strlen(digits); i++) {
                if ( dict[1][digits[i] - '0'] ) {
                    putchar(digits[i]);
                    for ( int k = 2; k <= w - 2; k++)
                        putchar(' ');
                } else {
                    for ( int k = 1; k <= w - 2; k++)
                        putchar(' ');
                }
                if ( dict[2][digits[i] - '0'] ) {
                    printf("%c ", digits[i]);
                } else {
                    printf("  ");
                }
            }
            putchar('\n');
        }
        for ( int i = 0; i < strlen(digits); i++) {
            if ( dict[3][digits[i] - '0'] ) {
                putchar(' ');
                for ( int j = 2; j <= w - 2; j++)
                    putchar(digits[i]);
                printf("  ");
            } else {
                for ( int j = 1; j <= w; j++)
                    putchar(' ');
            }
        }
        putchar('\n');
        for ( int j = 1; j <= (h - 3) / 2; j++) {
            for ( int i = 0; i < strlen(digits); i++) {
                if ( dict[4][digits[i] - '0'] ) {
                    putchar(digits[i]);
                    for ( int k = 2; k <= w - 2; k++)
                        putchar(' ');
                } else {
                    for ( int k = 1; k <= w - 2; k++)
                        putchar(' ');
                }
                if ( dict[5][digits[i] - '0'] ) {
                    printf("%c ", digits[i]);
                } else {
                    printf("  ");
                }
            }
            putchar('\n');
        }
        for ( int i = 0; i < strlen(digits); i++) {
            if ( dict[6][digits[i] - '0'] ) {
                putchar(' ');
                for ( int j = 2; j <= w - 2; j++)
                    putchar(digits[i]);
                printf("  ");
            } else {
                for ( int j = 1; j <= w; j++)
                    putchar(' ');
            }
        }
        putchar('\n');
    }
 
    return 0;
}