#include <stdio.h>
#include <string.h>
 
int main() {
    char s[1024];
    while (scanf("%s", s) == 1) {
        int n = (int) strlen(s);
        int count = 0, z = 0;
        for (int i = 0; i < n; i++) {
            if ( s[i] >= '0' && s[i] <= '9' ) {
                z++;
                if ( s[i] != '0' ) {
                    printf("%c", s[i]);
                    count++;
                } else if ( count > 0 ) {
                    printf("0");
                }
            } else if ( z > 0 && count == 0 ) {
                printf("0\n");
                z = 0;
            } else if ( count > 0 ) {
                printf("\n");
                count = 0;
                z = 0;
            }
        }
        if ( count > 0 ) {
            printf("\n");
        }
    }
    return 0;
}