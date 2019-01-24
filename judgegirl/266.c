#include <stdio.h>
#include <string.h>

int str_distance(char *s1, char *s2)
{
    int ans = strlen(s1) + strlen(s2);
    int minstep, mini, minj;
    char *p1 = s1, *p2 = s2;
    int flag = 1;
    while ( flag ) {
        flag = 0;
        minstep = 999999999;
        for ( int i = 0; p1[i] != '\0'; i++) {
            for ( int j = 0; p2[j] != '\0'; j++) {
                if ( p1[i] == p2[j] && i + j <= minstep ) {
                    minstep = i + j;
                    mini = i;
                    minj = j;
                    flag = 1;
                } 
            }
        }
        if ( flag ) {
            p1 += mini + 1;
            p2 += minj + 1;
            ans -= 2;
        }
    }
    return ans;
}

int main()
{
    char str[128][16];
    int i = 1;
    while ( scanf("%s", str[i]) != EOF ) {
        i++;
    }
    int index1, index2;
    int min = 100;
    for ( int j = 1; j < i; j++) {
        for ( int k = j + 1; k < i; k++) {
            int dis = str_distance(str[j], str[k]);
            if ( dis < min ) {
                min = dis;
                index1 = j;
                index2 = k;
            } else if ( dis == min && 1000 * j + k < 1000 * index1 + index2 ) {
                index1 = j;
                index2 = k;
            }
        }
    }
    printf("%d %d %d", min, index1, index2);
    return 0;
}