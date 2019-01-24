#include <stdio.h>

int month_days(int m, int l);

int main(void)
{
    int year, first_day;
    int n;
    int month, day;
    int i, j;
    int total;
    int leap = 0;

    scanf("%d%d", &year, &first_day);
    scanf("%d", &n);

    if ( year % 100 != 0 && year % 4 == 0 || year % 400 == 0 ) {
        leap = 1;
    }

    for ( i = 1; i <= n; i++) {
        total = 0;
        scanf("%d%d", &month, &day);

        if ( month > 12 || month < 1) {
            printf("-1\n");
            continue;
        } else if ( day > month_days(month, leap) || day < 1 ) {
            printf("-2\n");
            continue;
        }

        for ( j = 1; j < month; j++) {
            total += month_days(j, leap);
        }
        total += day;
        printf("%d\n", (total % 7 + 6 + first_day) % 7);
    }
    return 0;
}

int month_days(int m, int l)
{
    if ( m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        return 31;
    } else if ( m == 2 ) {
        return l ? 29 : 28;
    } else {
        return 30;
    }
}
