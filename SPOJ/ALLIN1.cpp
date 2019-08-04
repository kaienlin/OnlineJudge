#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, ov_tree_tag, tree_order_statistics_node_update> set_t;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int cmd, n;
    set_t t;
    while ( cin >> cmd >> n && cmd != -1 ) {
        switch ( cmd ) {
            case 1:
                t.insert(n);
                break;
            case 2:
                t.erase(n);
                break;
            case 3:
                if ( t.find(n) == t.end() )
                    cout << "-1\n";
                else
                    cout << t.order_of_key(n) + 1 << '\n';
                break;
            case 4:
                if ( n >= 1 && n <= t.size() )
                    cout << *t.find_by_order(n-1) << '\n';
                else
                    cout << "-1\n";
                break;
        }
    }
}
