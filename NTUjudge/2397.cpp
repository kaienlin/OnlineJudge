#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;

const int MAXL = 32;

int H, W;
char board[MAXL][MAXL];
int dp[MAXL][MAXL][MAXL][MAXL];

/* Application of Sprague-Grundy Theorem:
 *     First player will win if the XOR sum of the grundy numbers of
 *     position in each sub-games at the beginning of the game is non-zero.
 *     Otherwise, the second player will definitely win.
 *
 * How-to:
 *     1. break the composite game into sub-games
 *     2. for each sub-game, calculate its Grundy Number
 *     3. calculate the XOR of all the Grundy Numbers
 *     4. if the XOR sum is non-zero, then the player who is going to
 *        make the turn is destined to win.
 */

int grundy(int rl, int rr, int cl, int cr) {
    if ( rl > rr || cl > cr )
        return 0;
    if ( dp[rl][rr][cl][cr] != -1 )
        return dp[rl][rr][cl][cr];
    
    set<int> S;
    for ( int i = rl; i <= rr; i++) {
        for ( int j = cl; j <= cr; j++) {
            if ( board[i][j] != 'X' ) {
                S.insert(grundy(rl, i-1, cl, j-1) ^
                         grundy(i+1, rr, cl, j-1) ^
                         grundy(rl, i-1, j+1, cr) ^
                         grundy(i+1, rr, j+1, cr));
            }
        }
    }

    // mex ( minimum excludant ): the smallest number that is not present in a set
    int mex = 0;
    while ( S.count(mex) )
        ++mex;
    return dp[rl][rr][cl][cr] = mex;
}

int main()
{
    IOS;
    cin >> H >> W;
    for ( int i = 0; i < H; i++)
        cin >> board[i];
    memset(dp, -1, sizeof(dp));
    if ( grundy(0, H-1, 0, W-1) )
        cout << "First\n";
    else
        cout << "Second\n";
    return 0;
}
