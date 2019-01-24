#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int n, r, w, num;
    while ( ~scanf("%d%d%d", &n, &r, &w) ) {
        int correct[50][5] = {{0}};
        char ans[8];
        for ( int i = 0; i < n; i++) {
            scanf("%s", ans);
            for ( int j = 0; ans[j]; j++)
                correct[i][ans[j]-'A'] = 1;
        }
        scanf("%d", &num);
        while (num--) {
            int grade = 0;
            for ( int i = 0; i < n; i++) {
                scanf("%s", ans);
                if ( !strcmp(ans, "N/A") ) {continue;}
                int table[5] = {0};
                for ( int j = 0; ans[j]; j++) {
                    if ( isupper(ans[j]) )
                        table[ans[j]-'A'] = 1;
                    else
                        table[ans[j]-'a'] = 1;
                }
                int ch = 1;
                for ( int j = 0; j < 5; j++)
                    if ( table[j] != correct[i][j] )
                        ch = 0;
                grade += ch ? r : -w;        
            }
            printf("%d\n", grade <= 0 ? 0 : grade);
        }
    }
    return 0;
}