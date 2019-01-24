#include "value.h"

int value(int type, int width, int height, int length)
{
    int unit;
    int max = 0;
    int min_dime = 200000000;
    int i;
    int max_block;
    int tmp;

    switch( type ) {
        case 79:
            unit = 30;
            break;
        case 47:
            unit = 10;
            break;
        case 29:
            unit = 4;
            break;
        case 82:
            unit = 5;
            break;
        case 26:
            unit = 3;
            break;
        case 22:
            unit = 9;
            break;
        default:
            return -1;
    }

    if ( width <= 0 || height <= 0 || length <= 0 ) {
        return -2;
    }

    if ( length < min_dime )
        min_dime = length;
    if ( width < min_dime )
        min_dime = width;
    if ( height < min_dime )
        min_dime = height;

    for ( i = 1; i <= min_dime; i++ ) {
        if ( length % i == 0 && width % i == 0 && height % i == 0 ) {
            max_block = i;
        }
    }

    return  max_block * max_block * max_block * unit * length * height * width;
}
