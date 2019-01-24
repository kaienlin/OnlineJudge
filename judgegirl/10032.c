#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
char s[512];
 
int cmp(const void *a, const void *b)
{
    return s[*(int*)a] - s[*(int*)b];
}

int cmp2(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

char memory[65536][512];
 
int main()
{
    scanf("%s", s);
    int i;
    int order[512];
    for ( i = 0; s[i] != '\0'; i++) {
        order[i] = i;
    }
    qsort(order, i, sizeof(int), cmp);
    memset(memory, 0, sizeof(memory));
    int count = 0;
    for ( int j = 0; j < i; j++ ) {
        if ( j != 0 && s[order[j]] != s[order[j-1]] ) {
            qsort(memory, count, sizeof(char) * 512, cmp2);
            for ( int p = 0; p < count; p++) {
                printf("%s\n", memory[p]);
            }
            count = 0;
            memset(memory, 0, sizeof(memory));
        }
        for ( int k = 0; s[order[j] + k] != '\0'; k++) {
            int flag = 1;
            for ( int x = 0; x < count; x++) {
                if ( strncmp(&s[order[j]], memory[x], k + 1) == 0 ) {
                    flag = 0;
                    break;
                }
            }
            if ( !flag ) {continue;}
            strncpy(memory[count], &s[order[j]], k + 1);
            memory[count][k + 1] = '\0';
            count++;
            assert(count < 65536);
        }
    }
    qsort(memory, count, sizeof(char) * 512, cmp2);
    for ( int p = 0; p < count; p++) {
        printf("%s\n", memory[p]);
    }
    return 0;
}