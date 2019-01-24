#include <stdio.h>

int main(void)
{
    int arrival, timeA, timeB;
    int readyA = 0, readyB = 0;

    while ( scanf("%d%d%d", &arrival, &timeA, &timeB) != EOF ) {
        if ( arrival >= readyA ) {
            readyA = arrival + timeA;
        } else {
            readyA += timeA;
        }
        if ( readyA >= readyB ) {
            readyB = readyA + timeB;
        } else {
            readyB += timeB;
        }
        printf("%d\n", readyB);
    }

    return 0;
}
