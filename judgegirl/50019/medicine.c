#include "medicine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    Ing *x = (Ing*)a, *y = (Ing*)b;
    if ( x->w != y->w )
        return y->w - x->w;
    return strcmp(x->name, y->name);
}

void init(Medicine *medicine) {
    medicine->act_w = 0;
    medicine->inact_w = 0;
    medicine->act_n = 0;
    medicine->inact_n = 0;
}

int addActive(Medicine *medicine, char *name, int weight) {
    for ( int i = 0; i < medicine->act_n; i++)
        if ( !strcmp(medicine->act[i].name, name) ) {
            medicine->act[i].w += weight;
            medicine->act_w += weight;
            return medicine->act[i].w;
        }
    if ( medicine->act_n == 2 )
        return -1;
    medicine->act[medicine->act_n].w = weight;
    strcpy(medicine->act[medicine->act_n].name, name);
    medicine->act_w += weight;
    medicine->act_n++;
    return weight;
}

int addInactive(Medicine *medicine, char *name, int weight) {
    for ( int i = 0; i < medicine->inact_n; i++)
        if ( !strcmp(medicine->inact[i].name, name) ) {
            medicine->inact[i].w += weight;
            medicine->inact_w += weight;
            return medicine->inact[i].w;
        }
    if ( medicine->inact_n == 5 )
        return -1;
    medicine->inact[medicine->inact_n].w = weight;
    strcpy(medicine->inact[medicine->inact_n].name, name);
    medicine->inact_w += weight;
    medicine->inact_n++;
    return weight;
}

void print(Medicine *medicine) {
    qsort(medicine->act, medicine->act_n, sizeof(Ing), cmp);
    qsort(medicine->inact, medicine->inact_n, sizeof(Ing), cmp);
    puts("----- Active Ingredient begin   -----");
    for ( int i = 0; i < medicine->act_n; i++)
        printf("%d %s\n", medicine->act[i].w, medicine->act[i].name);
    puts("----- end                       -----");
    puts("----- Inactive Ingredient begin -----");
    for ( int i = 0; i < medicine->inact_n; i++)
        printf("%d %s\n", medicine->inact[i].w, medicine->inact[i].name);
    puts("----- end                       -----");
}

int totalWeight(Medicine *medicine) {
    return medicine->act_w + medicine->inact_w;
}

char *maxIngredient(Medicine *medicine) {
    if ( medicine->act_n == 0 && medicine->inact_n == 0 )
        return NULL;
    int cnt = 0;
    Ing array[8];
    for ( int i = 0; i < medicine->act_n; i++)
        array[cnt++] = medicine->act[i];
    for ( int i = 0; i < medicine->inact_n; i++)
        array[cnt++] = medicine->inact[i];
    qsort(array, cnt, sizeof(Ing), cmp);
    char *s = (char*)malloc(128);
    strcpy(s, array[0].name);
    return s;
}