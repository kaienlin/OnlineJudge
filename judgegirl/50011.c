#include <stdio.h>
#include <string.h>
#include <math.h>

char dict[100000][128];

int main()
{
    int n;
    scanf("%d", &n);
    for ( int i = 0; i < n; i++) {
        scanf("%s", dict[i]);
    }
    int q;
    scanf("%d", &q);
    char query[128];
    int list[100000];
    while (q--) {
        scanf("%s", query);
        int qlen = strlen(query);
        int t2 = 0, no = 1, done = 0;
        memset(list, 0, sizeof(list));
        for ( int i = 0; i < n; i++) {
            int len = strlen(dict[i]);
            if ( abs(qlen - len) == 0 && strcmp(query, dict[i]) == 0 ) {
                done = 1;
                printf(">%s", query); // if two strings are completely the same
                break;
            } else if ( abs(qlen - len) <= 1 ) {
                int a = 0, b = 0, times = 0;
                while ( 1 ) {
                    if ( query[a] != dict[i][b] ) {
                        if ( qlen == len ) {
                            a++;
                            b++;
                            times++;
                        } else if ( qlen < len ) {
                            b++;
                            times++;
                        } else if ( qlen > len ) {
                            a++;
                            times++;
                        }
                    } else {
                        a++;
                        b++;
                    }
                    if ( times >= 2 || a >= qlen || b >= len) {
                        break;
                    }
                }
                if ( times <= 1 ) {
                    no = 0;
                    list[i] = 1;
                }
            }
        }
        if ( !done ) {
            if ( no ) {
                printf("!%s", query);
            } else {
                putchar('?');
                for ( int k = 0; k < n; k++) {
                    if ( list[k] ) {
                        printf("%s ", dict[k]);
                    }
                }
            }
        }
        putchar('\n');
    }

    return 0;
}