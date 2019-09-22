#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;

unordered_map<string, LL> mp;
priority_queue<LL, vector<LL>, greater<LL>> more;
priority_queue<LL> les;

int main()
{
    IOS;
    int Q, K; cin >> Q >> K;
    for ( int i = 0; i < Q; i++) {
        string name; cin >> name;
        LL v; cin >> v;
        mp[name] += v;
    }
    for ( auto pr : mp ) {
        LL val = pr.second;
        if ( more.size() < K ) {
            more.push(val);
        } else {
            if ( val <= more.top() )
                les.push(val);
            else {
                LL tmp = more.top(); more.pop();
                les.push(tmp);
                more.push(val);
            } 
        }
    }
    LL ans = 0;
    while ( !more.empty() )
        ans += more.top(), more.pop();
    cout << ans << '\n';
    return 0;
}
