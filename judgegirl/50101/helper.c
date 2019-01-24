#include "componentPart.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int evaluate(int idx, ComponentPart list[]) {
    if ( list[idx].price != 0 )
        return list[idx].price;
    int n = list[idx].numComponent, p = 0;
    for ( int i = 0; i < n; i++)
        p += evaluate(list[idx].componentPartList[i], list);
    return (list[idx].price = p);
}
int cmp(const void *a, const void *b) {
    ComponentPart *x = *(ComponentPart**)a, *y = *(ComponentPart**)b;
    return strcmp(x->name, y->name);
}
void findPrice(int N, ComponentPart list[]) {
    ComponentPart *ptr[N];
    for ( int i = 0; i < N; i++) {
        if ( list[i].price == 0 )
            list[i].price = evaluate(i, list);
        ptr[i] = &list[i];
    }
    qsort(ptr, N, sizeof(ComponentPart*), cmp);
    for ( int i = 0; i < N; i++)
        printf("%s %d\n", ptr[i]->name, ptr[i]->price);
}