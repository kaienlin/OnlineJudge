#include <stdio.h>
#include <string.h>

int check(char prev, char cur, char rule[][3], int n, int index[26][26])
{
    if ( n == 0 )
        return 1;
    if ( index[prev - 'a'][cur - 'a'] )
        return 0;
    else
        return 1;
}

void words(int table[], char *print, int idx, char rule[][3], int n, int index[26][26])
{
    int flag = 1;
    for ( int i = 0; i < 26; i++)
        if ( table[i] ) {
            flag = 0;
            break;
        }
    if ( flag ) {
        print[idx] = '\0';
        printf("%s\n", print);
        return;
    }
    for ( int i = 0; i < 26; i++) {
        if ( table[i] > 0 ) {
            print[idx] = 'a' + i;
            if ( idx > 0 ) {
                if ( check(print[idx-1], print[idx], rule, n, index) ) {
                    int duplicate[26];
                    memcpy(duplicate, table, sizeof(int)*26);
                    duplicate[i]--;
                    words(duplicate, print, idx + 1, rule, n, index);
                }
            } else {
                int duplicate[26];
                memcpy(duplicate, table, sizeof(int)*26);
                duplicate[i]--;
                words(duplicate, print, idx + 1, rule, n, index);
            }
        }
    }
}

int main()
{
    char str[10000];
    scanf("%s", str);
    int table[26] = {0};
    for ( int i = 0; str[i] != '\0'; i++)
        table[str[i] - 'a']++;
    int n;
    scanf("%d", &n);
    char rule[1000][3];
    int index[26][26] = {{0}};
    for ( int i = 0; i < n; i++) {
        scanf("%s", rule[i]);
        index[rule[i][0] - 'a'][rule[i][1] - 'a'] = 1;
    }
    char print[10000];
    words(table, print, 0, rule, n, index);
    return 0;
}