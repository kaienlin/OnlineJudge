#include <stdio.h>

int main()
{
    int table[26][26] = {{0}};
    int T;
    scanf("%d", &T);
    char word[128];
    while ( scanf("%s", word) != EOF ) {
        for ( int i = 0; word[i+1] != '\0'; i++) {
            table[word[i] - 'a'][word[i+1] - 'a'] += 1;
        }
    }
    int max_index[2], max = 0;
    for ( int i = 0; i < 26; i++)
        for ( int j = 0; j < 26; j++) {
            printf("%d%c", table[i][j], j == 25 ? '\n' : ' ');
            if ( table[i][j] > max ) {
                max = table[i][j];
                max_index[0] = i;
                max_index[1] = j;
            }
        }
    
    int appear[26] = {0};
    printf("%c%c", 'a' + max_index[0], 'a' + max_index[1]);
    appear[max_index[0]] = 1;
    appear[max_index[1]] = 1;

    int prev = max_index[1];
    int flag = 1;
    while ( 1 ) {
        flag = max = 0;
        for ( int i = 0; i < 26; i++) {
            if ( table[prev][i] > T && table[prev][i] > max && !appear[i]) {
                max_index[0] = i;
                flag = 1;
                max = table[prev][i];
            }
        }
        if ( !flag ) {break;}
        prev = max_index[0];
        putchar(prev + 'a');
        appear[prev] = 1;
    }

    return 0;
}