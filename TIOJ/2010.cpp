#include <bits/stdc++.h>
#define MAXN 2000
#define pc putchar_unlocked

using namespace std;

char buffer[MAXN+1];
char X[MAXN+1], Y[MAXN+1];
unsigned short lcs[MAXN+1][MAXN+1];

inline unsigned short MAX(unsigned short a, unsigned short b) { return a > b ? a : b; }

void printLCS(int N, int M) {
    int i = N, j = M, pos = MAXN;
    buffer[pos] = '\0';
    while ( i > 0 && j > 0 ) {
        if ( X[i - 1] == Y[j - 1] ) {
            buffer[--pos] = X[i - 1];
            --i, --j;
        } else if ( lcs[i - 1][j] > lcs[i][j - 1] ) {
            --i;
        } else {
            --j;
        }
    }
    while ( buffer[pos] )
        pc(buffer[pos++]);
    pc('\n');
}

void LCS(int N, int M) {
    for ( int i = 0; i <= N; ++i) {
        for ( int j = 0; j <= M; ++j) {
            if ( !i || !j )
                lcs[i][j] = 0;
            else if ( X[i-1] == Y[j-1] )
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = MAX(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    int len = lcs[N][M];
    if ( !len )
        puts("*");
    else
        printLCS(N, M);
}

int main()
{
    int T;
    scanf("%d", &T);
    while ( T-- ) {
        int N, M;
        scanf("%d %d", &N, &M);
        scanf("%s %s", X, Y);
        LCS(N, M);
    }
}
