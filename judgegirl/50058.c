#include <stdio.h>
#include <string.h>

int min = __INT_MAX__, N;

void subset(int cost, int exist[26], int table[20][26], int costTable[20], int index)
{
    if ( cost > min ) {return;}
    int done = 1;
    for ( int i = 0; i < 26; i++)
        if (!exist[i])
            done = 0;
    if ( done ) {
        min = cost < min ? cost : min;
        return;
    }
    if ( index >= N ) {return;} // If I place this statement before minimum check, I cannot check the last index.
    subset(cost, exist, table, costTable, index + 1);
    int tmp[26];
    memcpy(tmp, exist, sizeof(tmp));
    for ( int i = 0; i < 26; i++)
        if ( table[index][i] )
            tmp[i] = 1;
    subset(cost + costTable[index], tmp, table, costTable, index + 1);
}

int main()
{
    scanf("%d", &N);
    char str[64];
    int cost;
    int table[20][26] = {{0}};
    int costTable[20];
    for ( int i = 0; i < N; i++) {
        scanf("%s%d", str, &cost);
        char *sptr = str;
        while (*sptr != '\0') {
            table[i][*sptr - 'a'] = 1;
            sptr++;
        }
        costTable[i] = cost;
    }
    int exist[26] = {0};
    subset(0, exist, table, costTable, 0);
    printf("%d\n", min);
    return 0;
}