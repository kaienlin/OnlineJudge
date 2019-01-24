#include "count_day.h"

void count_day(int year, int day, int month, int results[7])
{
    short leap = 0;
    if ( year % 400 == 0 || year % 4 == 0 && year % 100 != 0 ) { leap = 1; }
    const int days[12] = {31, (leap ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int count = 0;
    for ( int i = 1; i < month; i++) {
        count += days[i-1];
    }
    day = (count % 7 + day) % 7; // important line
    for ( int i = 1; i <= days[month-1]; i++) {
        results[day++]++;
        if ( day == 7 ) {
            day = 0;
        }
    }
}
