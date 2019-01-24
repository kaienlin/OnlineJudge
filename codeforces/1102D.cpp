#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char s[300001];
    scanf("%d%s", &n, s);
    int t[3] = {n/3, n/3, n/3};
    for ( char *c = s; *c; c++)
        t[*c - '0']--;
    int cnt[3] = {0};
    for ( char *c = s; *c; c++) {
        for ( int i = 0; i <= 2; i++) {
            if ( t[i] > 0 && t[*c - '0'] < 0 && ((i > *c - '0' && cnt[*c - '0'] == n/3) || (i < *c - '0')) ) {
                t[i]--;
                t[*c - '0']++;
                *c = i + '0';
                break;
            }
        }
        cnt[*c - '0']++;
    }
    printf("%s\n", s);
    return 0;
}