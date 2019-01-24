#include <stdio.h>
#include <string.h>

int main(void)
{
    int na, nb;
    scanf("%d", &na);
    int polya[na];
    int i, j;
    for ( i = 0; i < na; i++) {
        scanf("%d", &polya[i]);
    }

    scanf("%d", &nb);
    int polyb[nb];
    for ( i = 0; i < nb; i++) {
        scanf("%d", &polyb[i]);
    }

    int answer[na + nb -1];
    memset(answer, 0, sizeof answer);
    for ( i = 0; i < na; i++) {
        for ( j = 0; j < nb; j++) {
            answer[(na - i - 1) + (nb - j - 1)] += polya[i] * polyb[j];
        }
    }

    for ( i = na + nb - 2; i >= 0; i--) {
        printf("%d", answer[i]);
        if ( i != 0 ) {
            printf(" ");
        }
    }
    
    return 0;
}