#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXBUCK 10000
#define MAXSTR 101
#define MAXN 1000

char *Table[MAXN][MAXBUCK];

int hash(const char *s, int S)
{
    int ret = 0;
    while (*s != '\0' ) {
        if ( isdigit(*s) )
            ret += *s - '0';
        else
            ret += *s;
        s++;
    }
    return ret % S;
}
 
int main()
{
    int S, N, Q;
    scanf("%d%d%d", &S, &N, &Q);
    char str[MAXSTR], elements[MAXBUCK][MAXSTR];
    int tail[1000] = {0};
    for ( int i = 0; i < N; i++) {
        scanf("%s", elements[i]);
        int idx = hash(elements[i], S);
        Table[idx][tail[idx]++] = elements[i];
    }
    while (Q--) {
        scanf("%s", str);
        int idx = hash(str, S), flag = 1;
        for ( int i = 0; i < tail[idx]; i++) {
            if ( strcmp(str, Table[idx][i]) == 0 ) {
                printf("%d\n", idx);
                flag = 0;
                break;
            }
        }
        if (flag)
            puts("-1");
    }
    return 0;
}