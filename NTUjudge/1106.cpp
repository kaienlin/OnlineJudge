#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;
using ULL = uint64_t;
using pii = pair<int, int>;

struct AC_automaton {
    static constexpr int ALPHABET = 26;
    vector<int> cnt;

    struct Node {
        Node *go[ALPHABET], *fail;
        vector<int> sid;
        Node() {
            fill(go, go+ALPHABET, nullptr);
            fail = nullptr;
            sid = vector<int>();
        }
    } *root;

    Node* new_node() {
        return new Node();
    }
    void init() {
        root = new_node();
        cnt.clear();
    }
    void insert(const string &s, int sid) {
        Node *cur = root;
        for ( char ch : s ) {
            int c = ch - 'a';
            if ( cur->go[c] == nullptr )
                cur->go[c] = new_node();
            cur = cur->go[c];
        }
        cur->sid.push_back(sid);
    }
    int add_str(const string &s) {
        insert(s, cnt.size());
        cnt.push_back(0);
    }
    void make_fail() {
        // BFS
        queue<Node*> q;
        q.push(root);
        while ( q.size() ) {
            Node *cur = q.front(); q.pop();
            for ( int i = 0; i < ALPHABET; i++) {
                if ( cur->go[i] ) {
                    Node *ptr = cur->fail;
                    while ( ptr && ptr->go[i] == nullptr )
                        ptr = ptr->fail;
                    if ( ptr == nullptr )
                        cur->go[i]->fail = root;
                    else
                        cur->go[i]->fail = ptr->go[i];
                    q.push(cur->go[i]);
                }
            }
        }
    }
    Node *trans(Node *cur, int c) {
        while ( cur && cur->go[c] == nullptr )
            cur = cur->fail;
        return cur ? cur->go[c] : root;
    }
    void match(const string &s) {
        Node *cur = root;
        for ( int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            cur = trans(cur, c);
            Node *ptr = cur;
            while ( ptr != root ) {
                for ( int i : ptr->sid )
                    cnt[i]++;
                ptr = ptr->fail;
            }
        }
    }
} AC;

string arr[155];
string S;

int main()
{
    IOS;
    int N;
    while ( cin >> N && N ) {
        AC.init();
        for ( int i = 0; i < N; i++) {
            cin >> arr[i];
            AC.add_str(arr[i]);
        }
        AC.make_fail();
        cin >> S;
        AC.match(S);
        int mx = *max_element(AC.cnt.begin(), AC.cnt.end());
        cout << mx << '\n';
        for ( int i = 0; i < N; i++) {
            // cout << arr[i] << ": " << AC.cnt[i] << '\n';
            if ( AC.cnt[i] == mx )
                cout << arr[i] << '\n';
        }
    }
    
    return 0;
}