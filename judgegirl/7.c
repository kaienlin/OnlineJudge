#include <stdio.h>

int main(void)
{
    int x;
    scanf("%d", &x);
    
    if (x % 3 == 0 && x % 5 == 0 && !(x % 7 == 0)) {
        printf("0");
    } else {
        printf("1");
    }
    return 0;
}
