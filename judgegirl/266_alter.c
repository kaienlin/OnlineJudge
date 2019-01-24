#include <stdio.h>
#include <string.h>
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int min = __INT_MAX__;

int distance(char *s1, char *s2, int d)
{
    if ( d > min ) {return d;}
    if ( s1[0] == '\0' ) {return d+strlen(s2);}
    if ( s2[0] == '\0' ) {return d+strlen(s1);}
    if ( s1[0] == s2[0] )
        return distance(s1+1, s2+1, d);
    else
        return MIN(distance(s1+1, s2, d+1), distance(s1, s2+1, d+1));
}

int main()
{
    char str[100][11];
    int cnt = 0, id1, id2;
    while ( scanf("%s", str[cnt]) != EOF )
        cnt++;
    for ( int i = 0; i < cnt; i++) {
        for ( int j = i + 1; j < cnt; j++) {
            int d = distance(str[i], str[j], 0);
            if ( d < min ) {
                id1 = i + 1;
                id2 = j + 1;
                min = d;
            } else if ( d == min ) {
                if ( 1000 * id1 + id2 > 1000 * (i+1) + (j+1) ) {
                    id1 = i + 1;
                    id2 = j + 1;
                }
            }
        }
    }
    printf("%d %d %d\n", min, id1, id2);
}