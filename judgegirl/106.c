#include <stdio.h>
#include <string.h>
#include <math.h>
 
int main(void)
{
    char num[1000];
    int i;
    while (1) {
        scanf("%s", num);
        if ( num[0] == '-' ) {
            break;
        } else {
            if ( (num[strlen(num) - 1] - '0') % 2 == 0 ) {
                printf("yes ");
            } else {
                printf("no ");
            }
 
            int sum = 0;
            for ( i = 0; num[i] != '\0'; i++) {
                sum += (num[i] - '0');
            }
            if ( sum % 3 == 0 ) {
                printf("yes ");
            } else {
                printf("no ");
            }
 
            if ( (num[strlen(num) - 1] - '0') % 5 == 0 ) {
                printf("yes ");
            } else {
                printf("no ");
            }
 
            sum = 0;
            for ( i = 0; num[i] != '\0' ; i++) {
                if ( i % 2 == 0 ) {
                    sum += num[i] - '0';
                } else {
                    sum -= num[i] - '0';
                }
            }
            if ( abs(sum) % 11 == 0 ) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }   
    return 0;
}
