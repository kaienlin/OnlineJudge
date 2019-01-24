#include <stdio.h>

int main(void)
{
    int firstp[3];
    int tmp[3];
    int specialp[3];
    int lottery;
    int sum = 0;
    int match_count;
    int prize_get;
    int i, j;

    for ( i = 0; i < 3; i++) {
        scanf("%d", &specialp[i]);
    }
    for ( i = 0; i < 3; i++) {
        scanf("%d", &firstp[i]);
    }

    while (scanf("%d", &lottery) != EOF) {
        prize_get = 0;

        for ( i = 0; i < 3; i++) {
            if ( lottery == specialp[i] ) {
                sum += 2000000;
                prize_get = 1;
            }
            tmp[i] = firstp[i];
        }

        if ( prize_get ) continue; // I use break initially and find this mistake after a while. Be careful.

        match_count = 0;
        for ( i = 0; i < 3; i++) {
            for ( j = 0; j <= 8; j++) {
                if ( lottery % 10 == tmp[i] % 10 && match_count != 8 ) {
                    match_count++;
                    lottery /= 10;
                    tmp[i] /= 10;
                } else {
                    if ( match_count == 3) {
                        sum += 200;
                        prize_get = 1;
                    } else if ( match_count == 4 ) {
                        sum += 1000;
                        prize_get = 1;
                    } else if ( match_count == 5 ) {
                        sum += 4000;
                        prize_get = 1;
                    } else if ( match_count == 6 ) {
                        sum += 10000;
                        prize_get = 1;
                    } else if ( match_count == 7 ) {
                        sum += 40000;
                        prize_get = 1;
                    } else if ( match_count == 8 ) {
                        sum += 200000;
                        prize_get = 1;
                    }
                    break;
                }
            }
            if ( prize_get ) break;
        }
    }
    printf("%d\n", sum);

    return 0;
}
