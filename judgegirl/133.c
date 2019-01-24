#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string_count {
        char seen[80];
        int count;
};

int cmp(const void *a, const void *b)
{
    struct string_count x = *(struct string_count *)a;
    struct string_count y = *(struct string_count *)b;
    if ( x.count > y.count ) {
        return 1;
    } else if ( x.count == y.count ) {
        return strcmp(x.seen, y.seen);
    } else {
        return -1;
    }
}

int compare_and_add(char *string, struct string_count strings[])
{
    int i;
    for ( i = 0; strings[i].count != 0; i++) {
        if ( strcmp(string, strings[i].seen) == 0 ) {
            strings[i].count++;
            return 1;
        }
    }
    strings[i].count = 1;
    strcpy(strings[i].seen, string);
    return 0;
}
void sort(struct string_count strings[]) {
    int i;
    for ( i = 0; strings[i].count != 0; i++) {;}
    qsort(strings, i, sizeof(struct string_count), cmp);
}
void print(struct string_count strings[]) {
    for ( int i = 0; strings[i].count != 0; i++) {
        printf("%d %s\n", strings[i].count, strings[i].seen);
    }
}
