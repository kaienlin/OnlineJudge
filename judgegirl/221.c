#include <string.h>
#include <stdio.h>

// !!! zero division or mod generate "floating point exception. core dump." error message !!!

int main()
{
    char s[256][257];
    int m;
    scanf("%d", &m);
    int chnum = 0;
    int count = 0;
    int hole, more_n, less;
    while ( scanf("%s", s[count]) != EOF ) {
        chnum += strlen(s[count]) + 1;
        count++;
        if ( chnum - 1 > m ) {
            chnum -= strlen(s[count - 1]) + 2;
            hole = m - chnum;
            if ( count - 2 != 0 ) { // !!! zero division or mod generate "floating point exception. core dump." error message !!!
                less = hole / (count - 2);
                more_n = hole % (count - 2);
                for ( int i = 0; i <= count - 2; i++) {
                    printf("%s", s[i]);
                    if ( i != count - 2 ) {
                        putchar(' ');
                        if ( i < more_n ) {
                            for ( int j = 1; j <= less + 1; j++) {
                                putchar(' ');
                            }
                        } else {
                            for ( int j = 1; j <= less; j++) {
                                putchar(' ');
                            }
                        }
                    } else {
                        putchar('\n');
                    }
                }
            } else {
                printf("%s", s[0]);
                for ( int j = 0; j < hole; j++) {
                    putchar(' ');
                }
                putchar('\n');
            }
            strcpy(s[0], s[count - 1]);
            chnum = strlen(s[0]) + 1;
            count = 1;
        } else if ( chnum - 1 == m ) {
            for ( int i = 0; i < count; i++) {
                printf("%s", s[i]);
                putchar( i == count - 1 ? '\n' : ' ');
            }
            count = 0;
            chnum = 0;
        }
    }

    hole = m - (chnum - 1);
    if ( count - 1 == 0 ) { // !!! zero division or mod cause "floating point exception. core dump." error message !!!
        printf("%s", s[0]);
        for ( int i = 0; i < hole; i++) {
            putchar(' ');
        }
        putchar('\n');
    } else {
        less = hole / (count - 1);
        more_n = hole % (count - 1);
        for ( int i = 0; i < count; i++) {
            printf("%s", s[i]);
            if ( i != count - 1 ) {
                putchar(' ');
                if ( i < more_n ) {
                    for ( int j = 1; j <= less + 1; j++) {
                        putchar(' ');
                    }
                } else {
                    for ( int j = 1; j <= less; j++) {
                        putchar(' ');
                    }
                }
            } else {
                putchar('\n');
            }
        }
    }
    

    return 0;
}