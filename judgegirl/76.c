#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return strcmp((char*)a, (char*)b);
}

int main()
{
    char strings[64][33];
    int i = 0;
    while ( gets(strings[i]) != NULL ) {
        i++;
    }
    qsort(strings, i, 33, cmp);
    for ( int j = 0; j < i; j++) {
        puts(strings[j]);
    }
    return 0;
}