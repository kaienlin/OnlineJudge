#include "book.h"
#include "date.h"
 
int leap(unsigned int y)
{
    if ( y % 400 == 0 || y % 4 == 0 && y % 100 != 0 ) {return 1;}
    else {return 0;}
}
 
unsigned int month_days(unsigned int m, unsigned int y)
{
    unsigned int d[12] = {31, leap(y) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return d[m-1]; // be careful about index
}
 
int calculate_days(struct Date start, struct Date end)
{
    int days = 0;
    unsigned int i;
    if ( start.year < end.year) {
        for ( i = start.year + 1; i < end.year; i++) {days += leap(i) ? 366 : 365;}
        for ( i = start.month + 1; i <= 12; i++) {days += month_days(i, start.year);}
        days += month_days(start.month, start.year) - start.day + 1;
        for ( i = 1; i < end.month; i++) {days += month_days(i, end.year);}
        days += end.day;
        return days;
    } else if ( start.month < end.month ){
        for ( i = start.month + 1; i < end.month; i++) {days += month_days(i, start.year);}
        days += month_days(start.month, start.year) - start.day + 1;
        days += end.day;
        return days;
    } else {
        return end.day - start.day + 1;
    }
}
 
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned)
{
    int days = calculate_days(date_borrowed, date_returned);
    int limits[4] = {90, 10, 100, 5};
    if ( days <= limits[book.type] ) {return 0;}
    else {
        unsigned int pos1[2];
        int count = 0;
        unsigned int mask = 1;
        for ( int i = 0; i < 32; i++) {
            if ((book.importance >> i) & mask ) {
                pos1[count++] = i;
            }
        }
        return (pos1[1] - pos1[0] - 1) * (days - limits[book.type]); // cast (unsigned int) here appears to cause unexpected behavior 
    }
}