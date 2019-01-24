#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    int time;
    char category[32];
    int amount;
} item;

int cmp(const void *a, const void *b)
{
    item x = *(item *)a;
    item y = *(item *)b;
    if ( x.time != y.time ) {
        return x.time - y.time;
    } else {
        return strcmp(x.category, y.category);
    }
}

int main()
{
    item items[10000];
    int count = 0;
    int year, month, day;
    while ( scanf("%d%d%d%s%d", &year, &month, &day, items[count].category, &items[count].amount) != EOF ) {
        items[count].time = day + month * 100 + year * 1000000;
        count++;
    }
    qsort(items, count, sizeof(item), cmp);
    int i, j;
    for ( i = 0; i < count; i++) {
        for ( j = i + 1; j < count; j++) {
            if ( items[j].time == items[i].time && strcmp(items[j].category, items[i].category) == 0 ) {
                items[i].amount += items[j].amount;
            } else {
                break;
            }
        }
        printf("%d %d %d %s %d\n", items[i].time / 1000000, items[i].time % 1000000 / 100, items[i].time % 100, items[i].category, items[i].amount);
        i = j - 1;
    }
    return 0;
}