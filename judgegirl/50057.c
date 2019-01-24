#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int num, current_c, current_len = 0, pos = 0, space = 0;
    while (N--) {
        scanf("%d", &num);
        for ( int pos = 0; pos < 32; pos++) {
            if ( current_len == 0 ) {
                current_c = !!((num << pos) & 0x80000000);
                current_len++;
            } else if ( !!((num << pos) & 0x80000000) == current_c ) {
                current_len++;
            } else {
                int s = space % 40;
                for ( int i = 0; i < s; i++)
                    putchar(' ');
                space += current_len;
                while (current_len--)
                    putchar(current_c + '0');
                putchar('\n');
                current_len = 1;
                current_c = !current_c;
            }
        }
    }
    int s = space % 40;
    for ( int i = 0; i < s; i++)
        putchar(' ');
    while (current_len--)
    putchar(current_c + '0');
    putchar('\n');
    return 0;
}