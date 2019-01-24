#include <stdio.h>
#include <stdlib.h>
#include "blockmover.h"
 
unsigned long long patternLeft = 0x0101010101010101ULL;
unsigned long long patternRight = 0x8080808080808080ULL;
unsigned long long patternUp = 0x00000000000000FFULL;
unsigned long long patternDown = 0xFF00000000000000ULL;
 
void printBlock(unsigned long long int *block)
{
    for ( int i = 0; i < 64; i++) {
        putchar( (1ULL & *block >> i) ? '1' : '0' );
        if ( (i + 1) % 8 == 0 )
            putchar('\n');
    }
}
inline void initialize(unsigned long long int *block, int row, int column, int size)
{
    *block = 0ULL;
    unsigned long long unit = ~0ULL >> (64 - size);
    for ( int i = 0; i < size; i++)
        *block |= unit << (8 * i);
    for ( int i = 0; i < row; i++)
        moveDown(block);
    for ( int i = 0; i < column; i++)
        moveRight(block);
}
inline int moveLeft(unsigned long long int *block)
{
    if ( *block & patternLeft )
        return 0;
    else {
        *block >>= 1;
        return 1;
    }
}
inline int moveRight(unsigned long long int *block)
{
    if ( *block & patternRight )
        return 0;
    else {
        *block <<= 1;
        return 1;
    }
}
inline int moveUp(unsigned long long int *block)
{
    if ( *block & patternUp )
        return 0;
    else {
        *block >>= 8;
        return 1;
    }
}
inline int moveDown(unsigned long long int *block)
{
    if ( *block & patternDown )
        return 0;
    else {
        *block <<= 8;
        return 1;
    }
}