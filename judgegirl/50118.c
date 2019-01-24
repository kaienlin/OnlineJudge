#include <stdio.h>

int main(void)
{
    int num;
    int lsd, msd;
    int len, current_len, maxlen = 0;
    while ( scanf("%d", &num) != EOF ) {
        msd = num;
        current_len = 1;
        while ( msd >= 10 ) {
            msd /= 10;
            current_len++;
        }
        if ( lsd == msd ) {
            len += current_len;
        } else {
            len = current_len;
        }
        if ( len > maxlen ) {
            maxlen = len;
        }
        lsd = num % 10;
    }
    printf("%d", maxlen);
    return 0;   
}