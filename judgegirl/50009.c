#include "snake.h"
 
int snake(int *ptr, int *row, int *column) {
    ptr++;
    (*column)++;
    while ( *ptr != 0 ) {
        if ( *ptr != *column ) {
            break; // now ptr is on the tail of the second row
        }
        ptr++;
        (*column)++;
    }
    if ( *ptr == 0 ) {
        *row = 1;
        return 1;
    } // if meet 0 after processing first line, done
    int c = *column;
    ptr += *column - 1;
    int curr_row = 1;
    while ( 1 ) {
        for (int i = 0; i < *column; i++) {
            if ( *(ptr - i) != c++ ) {
                *row = curr_row;
                *column = i;
                return 0;
            }
        }
        ptr++;
        if ( *ptr == 0 ) {
            *row = curr_row + 1;
            return 1;
        }
        curr_row++;
        for ( int i = 0; i < *column; i++) {
            if ( *(ptr + i) != c++ ) {
                *row = curr_row;
                *column = i;
                return 0;
            }
        }
        ptr += (*column) * 2 - 1;
        if ( *ptr == 0 ) {
            *row = curr_row + 1;
            return 1;
        }
        curr_row++;
    }
}
