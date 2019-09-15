#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

#define LOG2(x) (31-__builtin_clz(x))
const int MAXN = 1e5+5, MAXLG = LOG2(MAXN)+1;

int N, A[MAXN];
int st[MAXLG][MAXN];
void preprocess() {
    for ( int i = 0; i < N; i++)
        st[0][i] = A[i];
    for ( int j = 1; (1<<j) <= N; j++)
        for ( int i = 0; i + (1<<j) - 1 < N; i++)
            st[j][i] = min(st[j-1][i], st[j-1][i + (1<<(j-1))]);
}
int query(int L, int R) {
    int j = LOG2(R - L + 1);
    return min(st[j][L], st[j][R - (1<<j) + 1]);
}
#undef LOG2

int main()
{
    IOS;
    cin >> N;
    for ( int i = 0; i < N; i++)
        cin >> A[i];
    preprocess();
    int Q; cin >> Q;
    while ( Q-- ) {
        int l, r; cin >> l >> r;
        cout << query(l, r) << '\n';
    }
    return 0;
}
