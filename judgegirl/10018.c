#include <stdio.h>
#define MAXN 100000

int t[MAXN + 1] = {0};

int main()
{
    int N, num;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &num);
        if ( !t[num] ) {
            t[num] = 1;
        } else {
            printf("%d\n", num);
            return 0;
        }
    }
    return 0;
}