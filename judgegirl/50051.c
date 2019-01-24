#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* When debugging, always read ALL the code carefully, because you never know where you will make stupid mistake, like this. */

int check(char *s, int type)
{
    int ignore = type ? 3 : 2;
    int sum = 0, count = 0, i = 0;
    while (s[i]) {
        if ( i != ignore && !isalnum(s[i]) ) { return 0; }
        if ( isdigit(s[i]) ) {
            sum += s[i] - '0';
            count++;
        }
        i++;
    }
    if ( count == 0 || sum % 7 == 0 ) {
        return 0;
    }
    if ( type ) {
        if ( s[0] == '4' && s[1] == '4' || s[1] == '4' && s[2] == '4' || s[4] == '4' && s[5] == '4' || s[5] == '4' && s[6] == '4') {
            return 0;
        }
    } else {
        if ( s[0] == '4' && s[1] == '4' || s[3] == '4' && s[4] == '4' || s[4] == '4' && s[5] == '4' || s[5] == '4' && s[6] == '4') {
            return 0;
        }
    }
    for ( int j = 0; s[j] != '\0'; j++) {
        int times = 1;
        for ( int k = j + 1; s[k] != '\0'; k++) {
            if ( s[j] == s[k] ) {
                times++;
                if ( times >= 3 ) {return 0;}
            }
        }
    }
    return 1;
}

int cmp(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b); // Well, I might be kind of too tired. (compare only one character)
}

int main()
{
    int n;
    scanf("%d", &n);
    char first[32][8];
    char second[32][8];
    char s[8];
    int fn = 0, sn = 0;
    while (n--) {
        scanf("%s", s);
        if ( s[2] == '-' ) {
            if ( check(s, 0) ) {
                strcpy(first[fn], s);
                fn++;
            }
        } else if ( s[3] == '-' ){
            if ( check(s, 1) ) {
                strcpy(second[sn], s);
                sn++;
            }
        }
    }
    qsort(first, fn, sizeof(char) * 8, cmp);
    qsort(second, sn, sizeof(char) * 8, cmp);
    for ( int i = 0; i < fn; i++) {
        printf("%s\n", first[i]);
    }
    for ( int i = 0; i < sn; i++) {
        printf("%s\n", second[i]);
    }
    return 0;
}