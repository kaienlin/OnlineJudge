#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;

const int MAXN = 45;
const int MAXM = 405;
const int MAXA = 100;
string INF;

int n, m;
string num[MAXN];
string dp[MAXN][MAXA];
int back[MAXN][MAXA];

string trans(string a, string b, int t) {
    string ret = b;
    int i, k = t;
    if ( t == 0 )
        return b >= a ? b : INF;
    for ( i = 0; i < m && k > 0; i++) {
        if ( ret[i] != a[i] ) {
            ret[i] = a[i];
            --k;
        }
    }
    if ( ret >= a )  // ret >= a
        return ret;

    --i;  // [0, i]: ret[i] == a[i], ret[i+1] < a[i+1]
    for ( ; i >= 0 && ret[i] == '9'; --i);
    if ( i < 0 )
        return INF;

    k = t;
    ret = b;
    for ( int j = 0; j < i; j++)
        if ( ret[j] != a[j] )
            ret[j] = a[j], --k;
    if ( ret[i] != a[i] + 1 )
        ret[i] = a[i] + 1, --k;

    ++i;
    for ( ; i < m && k > 0; i++)
        if ( ret[i] != '0' )
            ret[i] = '0', --k;

    return ret;
}
void print_ans(int j) {
    stack<string> st;
    for ( int i = n; i >= 1; i--) {
        st.push(dp[i][j]);
        j = back[i][j];
    }
    while ( !st.empty() )
        cout << st.top() << '\n', st.pop();
    exit(0);
}

int main()
{
    IOS;
    cin >> n >> m;
    INF = string(m, '9'+1);
    for ( int i = 1; i <= n; i++)
        cin >> num[i];
    
    memset(back, -1, sizeof(back));
    for ( int i = 0; i <= n; i++)
       for ( int j = 0; j <= 2*n; j++)
          dp[i][j] = INF;
    dp[0][0] = string(m, '0');

    for ( int i = 1; i <= n; i++) {
        for ( int j = 0; j <= 2*n; j++) {
            if ( dp[i-1][j] == INF ) continue;
            for ( int k = 0; k <= m && j + k <= 2*n; k++) {
                string r = trans(dp[i-1][j], num[i], k);
                if ( r != INF && r < dp[i][j+k] ) {
                    dp[i][j+k] = r;
                    back[i][j+k] = j;
                }
            }
        }
    }

    for ( int j = 0; j <= n<<1; j++)
        if ( dp[n][j] != INF )
            print_ans(j);
    return 0;
}
