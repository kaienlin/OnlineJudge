#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define gc getchar_unlocked
#define MAXN 100000

using namespace std;

int trans['M'+1];
int _dp1[4][4][4][4], _dp2[4][4][4][4];
auto *dp1 = _dp1, *dp2 = _dp2;
char seq[MAXN+1];

int MAX(int a, int b) { return a > b ? a : b; }

inline void init() {
    trans['M'] = 1;
    trans['F'] = 2;
    trans['B'] = 3;
}

inline int calc(int a, int b, int c) {
    int cnt[4] = {0};
    ++cnt[a]; ++cnt[b]; ++cnt[c];
    return (!!cnt[1]) + (!!cnt[2]) + (!!cnt[3]);
}

int solve(int N) {
    memset(_dp1, -1, sizeof(_dp1));
    memset(_dp2, -1, sizeof(_dp2));
    dp1[0][0][0][0] = 0;
    for ( int i = 0; i < N; i++) {
        int id = trans[ seq[i] ];
        for ( int i = 0; i <= 3; i++)
            for ( int j = 0; j <= 3; j++)
                for ( int k = 0; k <= 3; k++) {
                    int mx1 = -1, mx2 = -1;
                    for ( int l = 0; l <= 3; l++)
                        if ( dp1[l][i][j][k] != -1 )
                            mx1 = MAX(mx1, dp1[l][i][j][k] + calc(l, i, id));
                    for ( int l = 0; l <= 3; l++)
                        if ( dp1[j][k][l][i] != -1 )
                            mx2 = MAX(mx2, dp1[j][k][l][i] + calc(l, i, id));
                    dp2[i][id][j][k] = MAX(dp2[i][id][j][k], mx1);
                    dp2[j][k][i][id] = MAX(dp2[j][k][i][id], mx2);
                }
        swap(dp1, dp2);
    }
    int ans = 0;
    for ( int i = 0; i <= 3; i++)
        for ( int j = 0; j <= 3; j++)
            for ( int k = 0; k <= 3; k++)
                for ( int l = 0; l <= 3; l++)
                    ans = MAX(ans, dp1[i][j][k][l]);
    return ans;
}

int main()
{
    int N;
    scanf("%d", &N);
    gc();
    char *s = seq;
    while((*s = gc()) != '\n') {s++;}
    *s = '\0';
    init();
    printf("%d\n", solve(N));
}
