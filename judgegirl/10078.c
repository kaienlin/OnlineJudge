#include <stdlib.h>
#include <stdio.h>
#include "doll.h"

Doll *newDoll(char top, char bottom)
{
    Doll *ret = (Doll *)malloc(sizeof(Doll));
    ret->top = top;
    ret->bottom = bottom;
    ret->interior = NULL;
    return ret;
}

void package(Doll *outer, Doll *inter)
{
    outer->interior = inter;
}

const char* doll_c_str(Doll *doll)
{
    char *s = (char*)malloc(sizeof(char) * 1 << 20);
    char back[1 << 20];
    Doll *start = doll;
    int count = 0;
    while ( start != NULL ) {
        s[count] = start->top;
        back[count] = start->bottom;
        start = start->interior;
        count++;
    }
    for ( int i = count - 1, c = 0; i >= 0; i--, c++)
        s[count + c] = back[i];
    return s;
}
