#include <stdio.h>

/*
**Read the problem description careflly!!!
*/

int main(void)
{
    int c, check = 0, blank, sentence = 0;
    while ( (c = getchar_unlocked()) != EOF ) {
        if ( c == '.' ) {
            check = 1;
            blank = 0;
        } else if ( c == ' ' && check == 1 ) {
            blank++;
            if ( blank == 2 ) {
                sentence++;
                check = 0;
                blank = 0;
            }
        } else if ( c == '\n' && check == 1 && blank == 0 ) { // the '\n' should be RIGHT after '.'
            sentence++;
            check = 0;
        } else {
            check = 0;
            continue;
        }
    }
    if ( check )
        sentence++;
    printf("%d", sentence);
    return 0;
}
