#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1000
#define MAXSTR 101
#define MAXBUCK 10000

/* There are 2 factor may be the cause of issue: 1. memset(Table, 0, sizeof(Table)); >> MLE when MAXBUCK is too big
                                                 2. Not enough MAXBUCK >> WA
    But why initial program works?
    UPDATE: 對於第一次AC，雖然MAXBUCK不夠大卻仍然能夠work的原因是因為二維陣列實際上是連續的，加上我的插入是第一個不為NULL的元素，才奇蹟似的AC
*/
 
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
    char str[MAXSTR], elements[10000][MAXSTR];
    int tail[MAXN] = {0};
    // memset(Table, 0, sizeof(Table));
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