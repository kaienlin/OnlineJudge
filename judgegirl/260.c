#include <stdio.h>
#include <string.h>
 
int main(void)
{
    char result[128] = "";
    char input[128] = "";
    char *mark = NULL;
 
    while ( scanf("%s", input) != EOF ) {
        if ( strlen(result) == 0 ) {
            strcat(result, input);
        } else {
            int i;
            int shorter;
            if ( strlen(result) >= strlen(input) ) {
                mark = &result[strlen(result) - strlen(input)];
                shorter = strlen(input);
            } else {
                mark = result;
                shorter = strlen(result);
            }
            for ( i = 0; i < shorter; i++) {
                if ( strncmp(mark, input, shorter - i) == 0 ) {
                    strcat(result, input + (shorter - i));
                    break;
                }
                mark++;
            }
            if ( i == shorter ) {
                strcat(result, input);
            }
        }
    }
 
    printf("%s", result);
    return 0;
}