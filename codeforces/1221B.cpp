#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;
using pii = pair<int, int>;

const int MAXN = 101;
const vector<pii> dir = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

int n;
char board[MAXN][MAXN];

bool in_board(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < n);
}
void solve(int i, int j) {
    char v = board[i][j] == 'W' ? 'B' : 'W';
    for ( pii d : dir ) {
        int ni = i + d.first, nj = j + d.second;
        if ( in_board(ni, nj) && !board[ni][nj] ) {
            board[ni][nj] = v;
            solve(ni, nj);
        }
    }
}
int main()
{
    IOS;
    cin >> n;
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            if ( !board[i][j] ) {
                board[i][j] = 'W';
                solve(i, j);
            }
        }
    }
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++)
            cout << board[i][j];
        cout << '\n';
    }
    return 0;
}
