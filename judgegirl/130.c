#include <stdio.h>
#include <string.h>
#include <math.h>

/* Don't put strlen() in loop condition, because it will be evaluated every loop. */ 

int main(void)
{
    int n;
    char str1[81], str2[81];
    scanf("%d", &n);
    for ( int i = 0; i < n; i++) {
        scanf("%s%s", str1, str2);
        int len1 = strlen(str1), len2 = strlen(str2);
        if ( len1 == len2 ) {
            if ( strcmp(str1, str2) == 0 ) {
                printf("yes\n");
                continue;
            }
            int check = 0;
            for ( int j = 0; j < len1 - 1 && check < 2; j++) {
                if ( str1[j] != str2[j] ) {
                    if ( str1[j+1] == str2[j] && str1[j] == str2[j+1] ) {
                        check++;
                        j++;
                    } else {
                        printf("no\n");
                        check = -1;
                        break;
                    }
                }
            }
            if ( check == 1 ) {
                printf("yes\n");
            } else if ( check != -1 ) {
                printf("no\n");
            }
        } else if ( abs(len1 - len2) == 1 ) {
            int check = 0, j, k; // j for str1, k for str2
            for ( j = 0, k = 0; str1[j] != '\0' && str2[k] != '\0' && check < 2; j++, k++) {
                if ( str1[j] != str2[k] ) {
                    len1 > len2 ? k-- : j--;
                    check++;
                }
            } // if check >= 2, then it is "no"
            if ( check == 0 && (str1[j] == '\0' || str2[k] == '\0')) {
                printf("yes\n");
                continue;
            }
            if ( check > 1 ) {
                printf("no\n");
            } else {
                printf("yes\n");
            }
        } else {
            printf("no\n");
        }
    }
    return 0;
}
