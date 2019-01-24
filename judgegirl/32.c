#include <stdio.h>
#include <math.h>

// 測資1 ~ 5的尾端是1個空格+'\n', 但其他都是直接加'\n'。不知道這是不是正常現象。

int main(void)
{
    char input[11];
    int seq[100] = {0};
    int checker, counter;
    int maxlen = 0, max_l, max_r;
    int ch = ' ';
    int len = 0;
    int palin_left, palin_right;
    int la, ra, lb, rb;
    int i = 0, j = 0;

    while ( scanf("%d", &seq[len]) != EOF ) {
        len++;
    }

    /*while (1) {
        ch = getchar();
        i = 0;
        while ( ch <= 57 && ch >= 48 ) {
            input[i] = ch;
            i++;
            ch = getchar();
        }
        if ( i > 0 ) {
            for ( j = 0; i - 1 >= 0; i--, j++) {
                seq[len] += (input[i-1] - 48) * (int)pow(10, j);
            }
            len++;
        }

        if ( ch == '\n') {
            break;
        }
    }*/

    // judgegirl's testdata messed up. some of them has space tailed, some don't.
    // but, well, the one who messed it up appeared to be myself.
    
    for ( la = 0; la <= len - 2; la++) {
        for ( ra = la; ra < len; ra++) {
            checker = 1;
            for ( i = la; i <= ra; i++) {
                if ( seq[i] != seq[ra-i+la] ) {
                    checker = 0;
                    break;
                }
            }
            if (checker) {
                lb = ra + 1;
                for ( rb = lb; rb < len; rb++) {
                    checker = 1;
                    for ( i = lb; i <= rb; i++) {
                        if ( seq[i] != seq[rb-i+lb] ) {
                            checker = 0;
                            break;
                        }
                    }
                    if ( checker && rb - la + 1 >= maxlen ) {
                        maxlen = rb - la + 1;
                        max_l = la;
                        max_r = rb;
                    }
                }
            }
        }
    }

    for ( i = max_l; i <= max_r; i++) {
        printf("%d", seq[i]);
        if ( i != max_r ) {
            printf(" ");
        } 
    }

    return 0;
}
