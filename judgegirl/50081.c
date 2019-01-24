#include <stdio.h>

int main(void)
{
    int instr;
    int n, m;
    int x = 0, y = 0;
    scanf("%d%d", &n, &m);
    printf("0\n0\n");

    while ( scanf("%d", &instr) != EOF ) {
        switch ( instr % 5 ) {
            case 1:
                if ( x + instr < n ) {
                    x += instr;
                    printf("%d\n%d\n", x, y);
                }
                break;
            case 2:
                if ( x - instr >= 0 ) {
                    x -= instr;
                    printf("%d\n%d\n", x, y);
                }
                break;
            case 3:
                if ( y + instr < m ) {
                    y += instr;
                    printf("%d\n%d\n", x, y);
                }
                break;
            case 4:
                if ( y - instr >= 0 ) {
                    y -= instr;
                    printf("%d\n%d\n", x, y);
                }
                break;
        }
    }

    return 0;
}
