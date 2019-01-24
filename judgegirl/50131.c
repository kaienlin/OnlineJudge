#include <stdio.h>
#define MAXLEN 10001
 
int main()
{
    char str[MAXLEN], mark_i[MAXLEN], mark_j[MAXLEN], mark_o[MAXLEN];
    int i, j;
    while ( scanf("%s%d%d", str, &i, &j) != EOF ) {
        int count = 0, k;
        for ( k = 0; str[k] != '\0'; k++) {
            mark_i[k] = count == i ? str[k] : '+';
            mark_j[k] = count == j ? str[k] : '+';
            mark_o[k] = (count != i && count != j) ? str[k] : '+';
            if ( str[k] == 'a' || str[k] == 'e' || str[k] == 'i' || str[k] == 'o' || str[k] == 'u' )
                count++;
        }
        mark_i[k] = mark_j[k] = mark_o[k] = '\0'; 
        puts(mark_i);
        puts(mark_j);
        puts(mark_o);
    }
}