//the mistakes I made:
//1. not notice that i may greater than j
//2. not notice though i greater than j, the order of output should
//   still be the same as input

#include <stdio.h>

int main(void)
{
    int i, j;
    int tmp_i, tmp_j;
    int counter;
    unsigned int n, x;
    int max = 1;
    int tmp;

    while( scanf("%d %d", &i, &j) != EOF ) {

        max = 1;
        tmp_i = i;
        tmp_j = j;

        if (i > j) {
            tmp = i;
            i = j;
            j = tmp;
        }

        for (counter = i; counter <= j; counter++) {
            
            x = counter;
            n = 1;

            while (x != 1) {
                if (x%2 == 0) x = x / 2;
                else x =  3 * x + 1;
                n++;
            }

            if (n > max) max = n;
        }
            
        printf("%d %d %d\n", tmp_i, tmp_j, max);
    }

    return 0;
}
