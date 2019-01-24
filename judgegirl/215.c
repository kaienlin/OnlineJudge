#include <stdio.h>

int main(void)
{
    int s, f, t;
    scanf("%d%d%d", &s, &f, &t);

    int check = 1;;
    int chicken = 4 * s - f / 2 - 2 * t;
    int rabbit = f / 2 - 4 * s + 3 * t;
    int crab = s - t;

    if (f % 2 != 0) {
        check = 0;
    }

    if (chicken < 0 || rabbit < 0 || crab < 0) {
        check = 0;
    }
    
    if (check) {
        printf("%d\n%d\n%d", chicken, rabbit, crab);
    } else {
        printf("0");
    }
    return 0;
}
