#include "map.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void init(Map *map) {
    map->num = 0;
}
int map(Map *map, const int key, const char *value) {
    int n = map->num;
    for ( int i = 0; i < n; i++) {
        if ( map->pairs[i].key == key ) {
            strcpy(map->pairs[i].value, value);
            return 0;
        }
    }
    map->pairs[n].key = key;
    strcpy(map->pairs[n].value, value);
    map->num++;
    return 1;
}
int numPairs(Map *map) {
    return map->num;
}
void print(Map *map) {
    int n = map->num, swap = 0;
    for ( int i = 0; i < n - 1; i++) {
        swap = 0;
        for ( int j = 0; j < n - i - 1; j++) {
            if ( map->pairs[j].key > map->pairs[j+1].key ) {
                Pair tmp = map->pairs[j];
                map->pairs[j] = map->pairs[j+1];
                map->pairs[j+1] = tmp;
                swap++;
            }
        }
        if ( !swap ) 
            break;
    }
    puts("----- map begin -----");
    for ( int i = 0; i < n; i++) {
        printf("%d %s\n", map->pairs[i].key, map->pairs[i].value);
    }
    puts("----- end       -----");
}
const char *getValue(Map *map, const int key) {
    int n = map->num;
    for ( int i = 0; i < n; i++) {
        if ( map->pairs[i].key == key ) {
            return map->pairs[i].value;
        }
    }
    return NULL;
}
int unmap(Map *map, int key) {
    int n = map->num;
    for ( int i = 0; i < n; i++) {
        if ( map->pairs[i].key == key ) {
            memmove(&map->pairs[i], &map->pairs[i+1], sizeof(Pair) * (n - i - 1));
            map->num--;
            return 1;
        }
    }
    return 0;
}
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int reverseMap(Map *map, const char *value, int keys[]) {
    int n = map->num, cnt = 0;
    for ( int i = 0; i < n; i++)
        if ( !strcmp(value, map->pairs[i].value) )
            keys[cnt++] = map->pairs[i].key;
    qsort(keys, cnt, sizeof(int), cmp);
    return cnt;
}