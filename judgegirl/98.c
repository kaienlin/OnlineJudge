#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* things to remember: 1. how to qsort a 2-D array of char ( see cmp function )
                       2. the to-compare objects may be the same ( line 46 )
*/

struct food {
    int i;
    char name[65];
    char ingredients[10][65];
};

typedef struct food Food;

int cmp(const void *a, const void *b)
{
    char *str1 = (char *)a;
    char *str2 = (char *)b;
    return strcmp(str1, str2);
}

int main()
{
    int n;
    Food foods[100];
    scanf("%d", &n);
    for ( int i = 0; i < n; i++) {
        scanf("%s", foods[i].name);
        scanf("%d", &foods[i].i);
        for ( int j = 0; j < foods[i].i; j++) {
            scanf("%s", foods[i].ingredients[j]);
        }
    }
    int m;
    scanf("%d", &m);
    char obj1[65], obj2[65];
    int index1, index2; // store the position of obj1 and obj2
    char match[10][65];
    for ( int i = 0; i < m; i++) {
        scanf("%s%s", obj1, obj2);
        for ( int j = 0; j < n; j++) {
            //find obj1 and obj2
            if ( strcmp(obj1, foods[j].name) == 0 ) {
                index1 = j;
            }
            if ( strcmp(obj2, foods[j].name) == 0 ) {
                index2 = j;
            }
        }
        int count = 0;
        for ( int j = 0; j < foods[index1].i; j++) {
            for ( int k = 0; k < foods[index2].i; k++) {
                if ( strcmp(foods[index1].ingredients[j], foods[index2].ingredients[k]) == 0 ) {
                    strcpy(match[count], foods[index1].ingredients[j]);
                    count++;
                }
            }
        }
        if ( count == 0 ) {
            printf("nothing\n");
        } else {
            qsort(match, count, sizeof(char) * 65, cmp);
            for ( int j = 0; j < count; j++) {
                printf("%s", match[j]);
                putchar( j == count - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}