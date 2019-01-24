#include <stdio.h>

int main()
{
    char table[3];
    char hand[5][3];
    scanf("%s", table);
    for ( int i = 0; i < 5; i++) {
        scanf("%s", hand[i]);
        if ( hand[i][0] == table[0] || hand[i][1] == table[1] ) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}