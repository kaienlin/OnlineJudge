#include <bits/stdc++.h>
#define MAXL 500000

using namespace std;

char s[MAXL+1], t[MAXL+1];
int pi[MAXL], slen, tlen;

int KMP() {
    pi[0] = 0;
    for ( int i = 1; i < tlen; i++) {
        int j = pi[i - 1];
        while ( j > 0 && t[i] != t[j] )
            j = pi[j - 1];
        if ( t[i] == t[j] )
            ++j;
        pi[i] = j;
    }
    return pi[tlen - 1];
}
int prefix_cnt(int prefix_len) {
    int ret = 0;
    for ( int i = 0; i < prefix_len; i++)
        if ( t[i] == '1' )
            ret++;
    return ret;
}
int suffix_cnt(int suffix_len) {
    int ret = 0;
    for ( int i = tlen - 1, c = 0; c < suffix_len; c++, i--)
        if ( t[i] == '1' )
            ret++;
    return ret;
}
int s_cnt() {
    int ret = 0;
    for ( int i = 0; i < slen; i++)
        if ( s[i] == '1' )
            ret++;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    slen = strlen(s), tlen = strlen(t);
    int prefix_len = KMP();
    int suffix_len = tlen - prefix_len;
    int prefix_ones = prefix_cnt(prefix_len);
    int suffix_ones = suffix_cnt(suffix_len);
    int prefix_zeros = tlen - suffix_len - prefix_ones;
    int suffix_zeros = suffix_len - suffix_ones;
    int s_ones = s_cnt();
    int s_zeros = slen - s_ones;
    if ( (s_ones >= prefix_ones + suffix_ones) && (s_zeros >= prefix_zeros + suffix_zeros) ) {
        cout << t;
        s_ones -= (prefix_ones + suffix_ones);
        s_zeros -= (prefix_zeros + suffix_zeros);
    }
    while ( s_ones >= suffix_ones && s_zeros >= suffix_zeros ) {
        cout << t + prefix_len;
        s_ones -= suffix_ones;
        s_zeros -= suffix_zeros;
    }
    while ( s_ones-- )
        cout << '1';
    while ( s_zeros-- )
        cout << '0';
    cout << '\n';
}
