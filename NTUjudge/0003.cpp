#include <bits/stdc++.h>
#define POOLSZ 30000
#define MAX_STR_N 1000

using namespace std;

struct Node {
    int cnt;
    bool end;
    Node *next[26];
    Node(): cnt(0), end(false) { memset(next, 0, sizeof(next)); }
} pool[POOLSZ];

int NN = 0;

inline Node *new_node() {
    pool[NN] = Node();
    return &pool[NN++];
}
void insert(Node *t, const char *s) {
    while ( *s ) {
        int idx = *s - 'a';
        if ( t->next[idx] )
            t = t->next[idx];
        else
            t = t->next[idx] = new_node();
        ++s;
    }
    t->end = true;
}
void dfs(Node *t) {
    t->cnt = (int)t->end;
    for ( int i = 0; i < 26; i++) {
        if ( t->next[i] ) {
            dfs(t->next[i]);
            t->cnt += t->next[i]->cnt;
        }
    }
}
void search(Node *t, string s, int i) {
    if ( i == s.size() )
        cout << s << " " << s << '\n';
    else if ( t->cnt == 1 )
        cout << s << " " << s.substr(0, i) << '\n';
    else
        search(t->next[s[i]-'a'], s, i+1);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    string ss[MAX_STR_N], s;
    int n = 0;
    Node *root = new_node();
    while ( cin >> s ) {
        insert(root, s.c_str());
        ss[n++] = s;
    }
    dfs(root);
    for ( int i = 0; i < n; i++)
        search(root, ss[i], 0);
}
