#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

const int MAXN = 31;

int N;
LL A[MAXN];

unordered_map<LL, vector<int>> mp;

int main()
{
    IOS;
    int T; cin >> T;
    for ( int case_no = 1; case_no <= T; case_no++) {
        LL D;
        cin >> N >> D;
        cout << "Case #" << case_no << ": ";
        for ( int i = 0; i < N; i++)
            cin >> A[i];
        mp.clear();
        int nn = N / 2;
        for ( int msk = 0; msk < (1<<nn); msk++) {
            LL sum = 0;
            for ( int i = 0; i < nn; i++)
                if ( (1<<i) & msk )
                    sum += A[i];
            int num = __builtin_popcount(msk);
            mp[sum].push_back(num);
        }
        int mm = N - nn;
        int ans = -1; bool ambig = false;
        for ( unsigned msk = 0; msk < (1<<mm); msk++) {
            LL sum = 0, num = __builtin_popcount(msk);
            for ( int j = 0; j < mm; j++)
                if ( (1<<j) & msk )
                    sum += A[j + nn];
            auto it = mp.find(D - sum);
            if ( it != mp.end() ) {
                for ( int x : it->second ) {
                    if ( ans == -1 )
                        ans = x + num;
                    else if ( ans != x + num )
                        ambig = true;
                }
            }
            if ( ambig ) break;
        }
        if ( ambig )
            cout << "AMBIGIOUS\n";
        else if ( ans == -1 )
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << '\n';
    }
    return 0;
}
