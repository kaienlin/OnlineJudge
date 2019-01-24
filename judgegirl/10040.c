#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char dict[512][64];
    for ( int i = 0; i < n; i++)
        scanf("%s", dict[i]);
    int q;
    scanf("%d", &q);
    char query[64];
    while (q--) {
        scanf("%s", query);
        int count = 0, qlen = strlen(query);
        for ( int i = 0; i < n; i++) {
            for ( int j = 0; dict[i][j + qlen - 1] != '\0'; j++) {
                if ( strncmp(query, dict[i] + j, qlen) == 0 ) {
                    count++;
                    break;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}