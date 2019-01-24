#include <stdio.h>

int get_days(int m, int leap)
{
    if ( m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        return 31;
    } else if ( m == 2 ) {
        return leap ? 29 : 28;
    } else {
        return 30;
    }
}

int main(void)
{
    int i, count;
    int leap = 0;
    int year, month, firstday;
    scanf("%d%d%d", &year, &month, &firstday);

    if ( year < 0 || month > 12 || month <= 0 || firstday > 6 || firstday < 0 ) {
        printf("invalid\n");
        return 0;
    }

    if ( year % 400 == 0 || year % 4 == 0 && year % 100 != 0 ) leap = 1;

    printf(" Su Mo Tu We Th Fr Sa\n");
    printf("=====================\n");

    for ( i = 0; i < firstday; i++) {
        printf("   ");
    }

    for ( i = 1 , count = firstday; i <= get_days(month, leap); i++, count++) {
        printf("%3d", i);
        if ( (count + 1) % 7 == 0 && i != get_days(month, leap)) {
            printf("\n");
        }
    }

    printf("\n=====================\n");

    return 0;
}
