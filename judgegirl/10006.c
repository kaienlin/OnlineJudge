#include <stdio.h>

int main()
{
    int sum = 0, num;
    while ( scanf("%d", &num) != EOF) {
        sum += num;
    }
    printf("%d", sum);
    return 0;
}